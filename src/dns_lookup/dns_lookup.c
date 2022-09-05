// Copyright 2022 Kye Lewis <kye@kyedoesdev.com>
#include "dns_lookup.h"

struct addrinfo* dns_lookup(char* host, char* port) {
  struct addrinfo hints = {
    .ai_family = AF_INET,  // IPV4 only
    .ai_socktype = SOCK_STREAM,
    .ai_flags = 0,
    .ai_protocol = 0
  };

  struct addrinfo *result, *rp;
  int s = getaddrinfo(host, port, &hints, &result);
  assert(s == 0);

  int fd;
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    // Create Socket
    fd = socket(rp->ai_family, rp->ai_socktype, 0);
    if (fd == -1) continue;    // could not open socket
    close(fd);
    return rp;
  }

  return NULL;
}
