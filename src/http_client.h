// Copyright 2020 Kye Lewis <kye@kyedoesdev.com>
#ifndef SRC_HTTP_CLIENT_H_
#define SRC_HTTP_CLIENT_H_

#include <stdio.h>  // printf
#include <assert.h>  // assert
#include <unistd.h>  // close
#include <sys/socket.h>  // socket
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

void http_client(char* host);

#endif  // SRC_HTTP_CLIENT_H_
