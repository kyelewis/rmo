// Copyright 2022 Kye Lewis <kye@kyedoesdev.com>
#include "http_client.h"
#include "http_request/http_request.h"
#include "dns_lookup/dns_lookup.h"

void http_client(char* host) {
  // DNS Lookup
  struct addrinfo* rp = dns_lookup(host, "80");
  assert(rp != NULL);

  // Create socket
  int fd = socket(rp->ai_family, rp->ai_socktype, 0);
  assert(fd != -1);

  // Connect to socket
  int r = connect(fd, rp->ai_addr, rp->ai_addrlen);
  assert(r == 0);

  // Build HTTP Request header
  char http_request[1024];

  struct HttpRequestHeaders headers = {
    .host = host,
    .userAgent = "rmo/0.0.1"
  };

  make_http_request(http_request, sizeof(http_request), "/index.html", headers);
  printf("---Request:---\n%s\n--------------\n", http_request);

  // Write request header to socket
  int res = write(fd, http_request, sizeof(http_request));
  assert(res = sizeof(http_request));

  // Read response
  char* buffer = malloc(1024);
  char* ptr = buffer;
  int len;

  do {
    len = read(fd, ptr, sizeof(buffer));
    ptr += len;
  } while (len > 0);

  printf("---Response:---\n%s\n---------------\n", buffer);

  // Close Socket
  close(fd);
}
