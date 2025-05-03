#include "classes.h"
#include "../algorithm/hash.h"
#include <string.h>


STATIC_CLASS(class_meta_t, size_t* method_table; method_function_t meta_table; size_t mask, 0)
CLASS_END(class_meta_t, ) DEFAULT_DESTROY


STATIC_CLASS(type_object_t, char* type_name; unsigned int size; unsigned int id; class_meta_t meta, 0)
CLASS_END(type_object_t,
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


#define TYPE_INFO( TYPE_NAME, VAR_NAME ) INIT_WITH(type_object_t, \
  VAR_NAME, \
  #TYPE_NAME, \
  sizeof(TYPE_NAME), \
  0)
#define CLASS_INFO( CLASS_NAME, VAR_NAME ) INIT_WITH(type_object_t, \
  VAR_NAME, \
  #CLASS_NAME, \
  sizeof(CLASS_NAME), \
  __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__, \
  __meta_##CLASS_NAME, \
  __##CLASS_NAME##_MASK, \
  0)

