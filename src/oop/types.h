#ifndef TYPES_H
#define TYPES_H

#include "classes.h"
#include "../algorithm/hash.h"
#include <string.h>


STATIC_CLASS(class_meta_t, size_t* method_table; method_function_t* meta_table; size_t mask, 0)


STATIC_CLASS(type_object_t, char* type_name; unsigned int size; unsigned int id; class_meta_t meta, 0)


#define __AUX_MACRO_ARG_GET_STR__( TYPE_NAME ) #TYPE_NAME
#define __AUX_TYPE_GET_SIZEOF__( TYPE_NAME ) sizeof(TYPE_NAME)

#define TYPE_INFO( TYPE_NAME, VAR_NAME ) \
  type_object_t VAR_NAME; \
  INIT(type_object_t, \
  &VAR_NAME, \
  __AUX_MACRO_ARG_GET_STR__(TYPE_NAME), \
  __AUX_TYPE_GET_SIZEOF__(TYPE_NAME))

#define __AUX_CLASS_INFO__( CLASS_NAME, VAR_NAME ) \
  type_object_t VAR_NAME; \
  INIT(type_object_t, \
  &VAR_NAME, \
  __AUX_MACRO_ARG_GET_STR__(CLASS_NAME), \
  __AUX_TYPE_GET_SIZEOF__(CLASS_NAME), \
  __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__, \
  __##CLASS_NAME##_META, \
  __##CLASS_NAME##_MASK)


#define CLASS_INFO( CLASS_NAME, VAR_NAME ) \
  __AUX_CLASS_INFO__(CLASS_NAME, VAR_NAME)


STATIC_CLASS(var_object_t, type_object_t type; void* value; char allocated, 0)


#define __AUX_VAR_METHOD__( METHOD_ID, ... ) ((void*)( \
  ((ARG1_VA_ARGS(__VA_ARGS__))->type.meta.meta_table == 0) ? ( \
    0 \
  ) : ( \
    (METHOD_ID < __BUILT_IN_METHOD_TABLE_SIZE__) ? ( \
      (ARG1_VA_ARGS(__VA_ARGS__))->type.meta.meta_table[ \
        (ARG1_VA_ARGS(__VA_ARGS__))->type.meta.method_table[METHOD_ID] - 1] \
        ((ARG1_VA_ARGS(__VA_ARGS__))->value, ARG1_VA_ARGS_VA(__VA_ARGS__)) \
    ) : ( \
      (ARG1_VA_ARGS(__VA_ARGS__))->type.meta.meta_table[ \
        METHOD_ID - __BUILT_IN_METHOD_TABLE_SIZE__] \
        ((ARG1_VA_ARGS(__VA_ARGS__))->value, ARG1_VA_ARGS_VA(__VA_ARGS__)) \
    ) \
  ) \
))


#define VAR_METHOD( METHOD_ID, OBJ... ) \
  __AUX_VAR_METHOD__(METHOD_ID, OBJ, NULL)


void* var_object_alloc(var_object_t*);

#endif
