#ifndef TYPES_H
#define TYPES_H

#include "classes.h"
#include "../algorithm/hash.h"
#include <string.h>


STATIC_CLASS(class_meta_t, size_t* method_table; method_function_t meta_table; size_t mask, 0)


STATIC_CLASS(type_object_t, char* type_name; unsigned int size; unsigned int id; class_meta_t meta, 0)


#define __AUX_MACRO_ARG_GET_STR__( TYPE_NAME ) #TYPE_NAME
#define __AUX_TYPE_GET_SIZEOF__( TYPE_NAME ) sizeof(TYPE_NAME)

#define TYPE_INFO( TYPE_NAME, VAR_NAME ) INIT_WITH(type_object_t, \
  __AUX_MACRO_ARG_GET_STR__(VAR_NAME), \
  __AUX_MACRO_ARG_GET_STR__(TYPE_NAME), \
  __AUX_TYPE_GET_SIZEOF__(TYPE_NAME), \
  0)

#define __AUX_CLASS_INFO__( CLASS_NAME, VAR_NAME ) INIT_WITH(type_object_t, \
  __AUX_MACRO_ARG_GET_STR__(VAR_NAME), \
    __AUX_MACRO_ARG_GET_STR__(CLASS_NAME), \
  __AUX_TYPE_GET_SIZEOF__(CLASS_NAME), \
  __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__, \
  __meta_##CLASS_NAME, \
  __##CLASS_NAME##_MASK, \
  0)


#define CLASS_INFO( CLASS_NAME, VAR_NAME ) \
  __AUX_CLASS_INFO__(CLASS_NAME, VAR_NAME)

#endif
