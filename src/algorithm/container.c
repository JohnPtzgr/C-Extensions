#include "container.h"

CLASS_END(smartptr_t,
  METHOD_ARGS(1);
  if (self->data != 0) {
    free(self->data);
  }
  if (__ARG_CNT__ == 1) {
    self->data = malloc(*((size_t**)__ARG_LIST__)[0]);
  }
) {
  if (self->data != 0) {
    free(self->data);
    self->data = 0;
  }
  return self;
}

CLASS_END(generic_container_t,
  METHOD_ARGS(2);
  if (self->data != 0) {
    free(self->data);
  }
  self->data = 0;
  self->size = 0;
  switch (__ARG_CNT__) {
    case 1:
      self->data = malloc(((generic_container_t**)__ARG_LIST__)[0]->size * \
        ((generic_container_t**)__ARG_LIST__)[0]->type_size);
      self->size = ((generic_container_t**)__ARG_LIST__)[0]->size;
      self->type_size = ((generic_container_t**)__ARG_LIST__)[0]->type_size;
      memcpy(self->data,
             ((generic_container_t**)__ARG_LIST__)[0]->data,
             self->size * self->type_size);
    case 2:
      self->data = calloc(*((size_t**)__ARG_LIST__)[0] * *((size_t**)__ARG_LIST__)[1]);
      self->size = *((size_t**)__ARG_LIST__)[0];
      self->type_size = *((size_t**)__ARG_LIST__)[1];
    case 3:
      self->data = calloc(*((size_t*)__ARG_LIST__)[0] * *((size_t*)__ARG_LIST__)[1]);
      self->size = *((size_t**)__ARG_LIST__)[0];
      self->type_size = *((size_t**)__ARG_LIST__)[1];
      for (size_t i = 0; i < self->size * self->type_size; i += self->type_size) {
        memcpy(self->data + i, __ARG_LIST__[2], self->type_size);
      }
  }
) {
  SET_METHOD(generic_container_t, 32, self, gen_cont_free)
  if (self->data != 0) {
    gen_cont_free(self);
  }
  return self;
}

void* gen_cont_free(generic_container_t* self) {
  free(self->data);
  self->data = 0;
  self->size = 0;
  self->type_size = 0;
  return self;
}

void* gen_cont_alloc(generic_container_t* self,
  size_t size,
  size_t type_size) {
  if (self->data != 0) {
    gen_cont_free((generic_container_t*)self->data);
  }
  self->data = malloc(size * type_size);
  self->type_size = type_size;
  self->size = size;
  return self;
}