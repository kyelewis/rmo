// Copyright 2020 Kye Lewis <kye@kyedoesdev.com>
#ifndef SRC_HTTP_REQUEST_H
#define SRC_HTTP_REQUEST_H

#include <stdio.h>  // snprintf

struct HttpRequestHeaders {
  char* host;
  char* userAgent;
};

void make_http_request(char* request, size_t size, char* path, struct HttpRequestHeaders headers);


#endif  // SRC_HTTP_REQUEST_H
