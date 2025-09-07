#include "class.h"
#include <string.h>

#pragma once

DEF_BARE_CLASS(type_object_t, __ClassMetaData__ type_meta; const char* type_name; size_t type_size; size_t type_mask)

#define TYPE_INFO(TYPE_NAME) \
  CLS(type_object_t, __STRING(TYPE_NAME), sizeof(TYPE_NAME), NULL)

#define CLASS_INFO(CLASS_NAME) \
  CLS(type_object_t, __STRING(CLASS_NAME), sizeof(CLASS_NAME), &__##CLASS_NAME##_Default_MetaData__, NULL)

#define CLASS_OF(CLASS_INSTANCE) \
  CLS(type_object_t, \
      ((__ClassMetaData__*)(CLASS_INSTANCE))->vcls->cls->name, \
      ((__ClassMetaData__*)(CLASS_INSTANCE))->vcls->cls->instance_size, \
      ((__ClassMetaData__*)(CLASS_INSTANCE)), NULL)

DEF_CLASS(var_object_t, type_object_t* type; void* value)

void* __aux_default_type_init__(void* self, ...);

#define VAR(TYPE...) CLS(var_object_t, \
                         ARG1_VA_ARGS(TYPE), \
                         ((ARG1_VA_ARGS(TYPE))->type_meta.vcls == NULL ? \
                           __aux_default_type_init__ : \
                           (ARG1_VA_ARGS(TYPE))->type_meta.vcls->__init__)(alloca((ARG1_VA_ARGS(TYPE))->type_size), \
                           ARG1_VA_ARGS_VA(TYPE, NULL)), \
                         NULL)
