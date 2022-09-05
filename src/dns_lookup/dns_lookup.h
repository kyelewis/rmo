// Copyright 2020 Kye Lewis <kye@kyedoesdev.com>
#ifndef SRC_DNS_LOOKUP_H
#define SRC_DNS_LOOKUP_H

#include <unistd.h>  // close
#include <assert.h>
#include <sys/socket.h>  // socket
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

struct addrinfo* dns_lookup(char* host, char* port);

#endif  // SRC_DNS_LOOKUP_H
