#include "types.h"


STATIC_CLASS_END(class_meta_t, 0, ) DEFAULT_DESTROY

STATIC_CLASS_END(type_object_t, 0,
  METHOD_ARGS(5);
  self->type_name = (char*)__ARG_LIST__[0];
  self->size = (size_t)__ARG_LIST__[1];
  self->id = hash_byte_array(self->type_name, strlen(self->type_name));
  self->meta.mask = (size_t)(-1);
  printf("ARG_CNT: %llu\n", __ARG_CNT__);
  if (__ARG_CNT__ > 2) {
    self->meta.method_table = (size_t*)__ARG_LIST__[2];
    self->meta.meta_table = (method_function_t)__ARG_LIST__[3];
    self->meta.mask = (size_t)__ARG_LIST__[4];
  }
) DEFAULT_DESTROY