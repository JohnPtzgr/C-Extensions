#include "classes.h"
#include "../algorithm/hash.h"
#include <string.h>

STATIC_CLASS(type_object_t, char* type_name; unsigned int size; unsigned int id, 0)

CLASS_END(type_object_t,
  METHOD_ARGS(2);
  self->type_name = (char*)__ARG_LIST__[0];
  self->size = (unsigned int)__ARG_LIST__[1];
  self->id = hash_byte_array(self->type_name, strlen(self->type_name));
) DEFAULT_DESTROY


#define DECL_TYPE( TYPENAME ) INIT_WITH(type_object_t, __##TYPENAME##_TYPE_VAR__, #TYPENAME, sizeof(TYPENAME))