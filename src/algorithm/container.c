#include "container.h"

STATIC_CLASS_END(smartptr_t, 0,
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

STATIC_CLASS_END(generic_container_t, 2,
  METHOD_ARGS(2);
  if (self->data != 0) {
    free(self->data);
  }
  self->data = 0;
  self->capacity = 0;
  switch (__ARG_CNT__) {
    case 1:
      self->data = malloc(((generic_container_t**)__ARG_LIST__)[0]->capacity);
      self->capacity = ((generic_container_t**)__ARG_LIST__)[0]->capacity;
      memcpy(self->data,
             ((generic_container_t**)__ARG_LIST__)[0]->data,
             self->capacity);
    case 2:
      self->capacity = *((size_t**)__ARG_LIST__)[0] * \
        *((size_t**)__ARG_LIST__)[1];
      self->data = malloc(*((size_t**)__ARG_LIST__)[0] * \
        *((size_t**)__ARG_LIST__)[1]);
    case 3:
      self->capacity = *((size_t**)__ARG_LIST__)[0] * \
        *((size_t**)__ARG_LIST__)[1];
      self->data = malloc(*((size_t**)__ARG_LIST__)[0] * \
        *((size_t**)__ARG_LIST__)[1]);
      for (size_t i = 0; \
        i < self->capacity; \
        i += *((size_t**)__ARG_LIST__)[1]) {
        memcpy(self->data + i, __ARG_LIST__[2], *((size_t**)__ARG_LIST__)[1]);
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
  self->capacity = 0;
  return self;
}

void* gen_cont_alloc(generic_container_t* self,
  size_t size,
  size_t type_size) {
  if (self->data != 0) {
    gen_cont_free((generic_container_t*)self->data);
  }
  self->data = malloc(size * type_size);
  self->capacity = size * type_size;
  return self;
}