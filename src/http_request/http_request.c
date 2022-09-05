// Copyright 2022 Kye Lewis <kye@kyedoesdev.com>
#include "http_request.h"

void make_http_request(
  char* request,
  size_t size,
  char* path,
  struct HttpRequestHeaders headers
) {
  snprintf(
    request,
    size,
    "GET %s HTTP/1.1\n"
    "Host: %s\n"
    "User-Agent: %s\n"
    "\n",
    path,
    headers.host,
    headers.userAgent);
}
