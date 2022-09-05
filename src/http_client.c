// Copyright 2022 Kye Lewis <kye@kyedoesdev.com>
#include "http_client.h"
#include "http_request/http_request.h"

void http_client(char* host) {
  struct addrinfo hints = {
    .ai_family = AF_INET,  // IPV4 only
    .ai_socktype = SOCK_STREAM,
    .ai_flags = 0,
    .ai_protocol = 0
  };

  // DNS Lookup
  struct addrinfo *result;
  int s = getaddrinfo(host, "80", &hints, &result);
  assert(s == 0);

  struct addrinfo *rp;
  int fd;
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    // Create Socket
    printf("Creating socket\n");
    fd = socket(rp->ai_family, rp->ai_socktype, 0);
    if (fd == -1) continue;    // could not open socket

    printf("Trying to connect\n");
    if (connect(fd, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(fd);
  }

  assert(rp != NULL);

  printf("Connected\n");

  char http_request[1024];
  struct HttpRequestHeaders headers = {
    .host = host,
    .userAgent = "rmo/0.0.1"
  };
  make_http_request(http_request, sizeof(http_request), "/index.html", headers);

  int res = write(fd, http_request, sizeof(http_request));
  assert(res = sizeof(http_request));

  printf("---\n%s\n", http_request);

  char* buffer = malloc(1024);
  char* ptr = buffer;
  int len;

  do {
    len = read(fd, ptr, sizeof(buffer));
    ptr += len;
  } while (len > 0);

  printf("---\n%s", buffer);

  close(fd);
}
