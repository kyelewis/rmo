#include <stdlib.h>

#include "http_client.h"

int main(int argc, char* argv[]) {

  if(argc != 2) {
    printf("Usage: %s <domain>", argv[0]);
    exit(EXIT_FAILURE);
  }

  http_client(argv[1]);

  exit(EXIT_SUCCESS);
}
