#include "socket_IO.h"

void* socket_t_open(socket_t* self) {
  self->fd = socket(self->domain, self->type, self->protocol);

  EXCTH_ASSERT(void*, self->fd != -1 && "Unable to create a new socket!");
  if (bind(self->fd, (struct sockaddr*)&(self->address), sizeof(self->address)) < 0) {
    close(self->fd);
    EXCTH_ASSERT(void*, FALSE && "Unable to create a new socket!");
  }
  return self;
}

void* socket_t_close(socket_t* self) {
  close(self->fd);
  return self;
}

void* socket_t_listen(socket_t* self) {
  self->fd = socket(self->domain, self->type, self->protocol);
  return self;
}

void* socket_t_accept(socket_t* self) {
  self->fd = socket(self->domain, self->type, self->protocol);
  return self;
}

CLASS_END(socket_t, STATIC,
  __ON_STATIC_INIT__(socket_t,

  )
) {}

void* socket_t_destroy(socket_t* self, ...) {
  if (self->fd != -1) {
    close(self->fd);
  }
  return NULL;
}

void* socket_t_init(socket_t* self, ...) {
  __AUX_INIT_BEGIN__(socket_t)
  // Domain, Type, Protocol, Address|Address*, Port|AddressSize, Family
  __M_VA_ARG__(5, AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 0);
  if (__ARG_LIST__[5] == 0) {
    __ARG_LIST__[5] = __ARG_LIST__[0];
  }
  self->domain = (int)__ARG_LIST__[0];
  self->type = (int)__ARG_LIST__[1];
  self->protocol = (int)__ARG_LIST__[2];
  self->address.sa.sa_family = (sa_family_t)__ARG_LIST__[5];
  if (self->address.sa.sa_family == AF_INET) {
    self->address.sa_in.sin_addr.s_addr = (in_addr_t)__ARG_LIST__[3];
    self->address.sa_in.sin_port = htons((uint16_t)__ARG_LIST__[4]);
  } else if (self->address.sa.sa_family == AF_INET6) {
    memcpy(self->address.sa_in6.sin6_addr.__in6_u.__u6_addr8, __ARG_LIST__[3], \
        sizeof(self->address.sa_in6.sin6_addr.__in6_u.__u6_addr8));
    self->address.sa_in6.sin6_port = htons((uint16_t)__ARG_LIST__[4]);
  } else {
    size_t address_size = (size_t)__ARG_LIST__[4];
    if (address_size > (__CHAR_BIT__ * sizeof(self->address))) {
      address_size = sizeof(self->address);
    }
    memcpy(&(self->address.sa), __ARG_LIST__[3], address_size);
  }
  __AUX_INIT_END__(socket_t)
}