#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include "../oop/class.h"


DEF_CLASS(socket_t
  ,
  int fd;
  int domain;
  int type;
  int protocol;

  union socket_address_t
  {
    struct sockaddr sa;
    struct sockaddr_in sa_in;
    struct sockaddr_in6 sa_in6;
    struct sockaddr_storage __storage;
  } address;
  ,
  generic_function_t start;
  generic_function_t stop;
  generic_function_t listen;
  generic_function_t accept;
)
