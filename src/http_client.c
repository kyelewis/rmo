// Copyright 2022 Kye Lewis <kye@kyedoesdev.com>
#include <http_client.h>

void http_client(char* domain) {
  printf("\n--- INTERNET SOCKET ---\n");

  struct addrinfo hints = {
    .ai_family = AF_INET,  // IPV4 only
    .ai_socktype = SOCK_STREAM,
    .ai_flags = 0,
    .ai_protocol = 0
  };

  // DNS Lookup
  struct addrinfo *result;
  int s = getaddrinfo(domain, "80", &hints, &result);
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

  char hello[1024];
  snprintf(hello, "GET / HTTP/1.1\nHost: %s\n\n", domain);
  int res = write(fd, hello, sizeof(hello));
  assert(res = sizeof(hello));

  printf("---\n%s\n", hello);

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
