#include "types.h"


STATIC_CLASS_END(class_meta_t, 0, ) DEFAULT_DESTROY


STATIC_CLASS_END(type_object_t, 0,
  METHOD_ARGS(5);
  self->type_name = (char*)((void**)__ARG_LIST__[0]);
  self->size = (size_t)((void**)__ARG_LIST__[1]);
  self->id = hash_byte_array(self->type_name, strlen(self->type_name));
  self->meta.mask = (size_t)(-1);
  self->meta.meta_table = 0;
  self->meta.method_table = 0;
  if (__ARG_CNT__ > 2) {
    self->meta.method_table = (size_t*)((void**)__ARG_LIST__[2]);
    self->meta.meta_table = (method_function_t*)((void**)__ARG_LIST__[3]);
    self->meta.mask = (size_t)((void**)__ARG_LIST__[4]);
  }
) DEFAULT_DESTROY


STATIC_CLASS_END(var_object_t, 0,
  METHOD_ARGS(10);
  self->type = *((type_object_t*)((void**)__ARG_LIST__[0]));
  self->value = ((void**)__ARG_LIST__[1]);
  if (self->type.meta.meta_table) {
    switch (__ARG_CNT__ - 2)
    {
    case 1:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], 0);
      break;

    case 2:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], 0);
      break;

    case 3:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], 0);
      break;

    case 4:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], __ARG_LIST__[5], 0);
      break;

    case 5:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], __ARG_LIST__[5], __ARG_LIST__[6], 0);
      break;

    case 6:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], 0);
      break;

    case 7:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], __ARG_LIST__[8], 0);
      break;

    case 8:
      self->type.meta.meta_table[__m_init__](self->value, __ARG_LIST__[2], __ARG_LIST__[3], \
        __ARG_LIST__[4], __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], 0);
      break;
        
    default:
      self->type.meta.meta_table[__m_init__](self->value, 0);
      break;
    }
  }
) {
  if (self->type.meta.meta_table) {
    self->type.meta.meta_table[__m_destroy__](self->value);
  }
  return self;
}