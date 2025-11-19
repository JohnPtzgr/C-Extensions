#include "class.h"
#include <string.h>

#pragma once
typedef struct __type_object_t_vClassObject__ __type_object_t_vClassObject__;
typedef type_object_t type_object_t_S;
typedef struct type_object_t_R {
  DefaultBase_S __base__;
} type_object_t_R;
typedef struct __type_object_t_vClassObjectPrt__ {
  __vClassObjectPrt__ default_protected;
} __type_object_t_vClassObjectPrt__;
typedef __DefaultBase_FundamentalVClass__ __type_object_t_FundamentalVClass__;
struct __type_object_t_vClassObjectMeta__ {
  char __prot_vcls_data__[sizeof(__type_object_t_vClassObjectPrt__)];
  unsigned int __method_shift__[64 + 0 + 0];
  __vClassObjectPrt__* __protected__;
  __vTable__* __vtable__;
};
typedef struct __type_object_t_vClassObject__ {
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;
  __type_object_t_FundamentalVClass__ _f;
  unsigned int* __method_shift__;
  __ClassObject__* cls;
  __DefaultBase_vClassObject__* __base__;
  struct __type_object_t_vClassObjectMeta__ __meta__;
} __type_object_t_vClassObject__;
typedef struct __type_object_t_ClassInterface__ {
  type_object_t_S* self;
  const __type_object_t_vClassObject__* __meta__;
} __type_object_t_ClassInterface__;
extern void* __type_object_t_static_init__(type_object_t* self);
extern void* __type_object_t_static_destroy__(type_object_t* self);
extern void* type_object_t_init(type_object_t* self , ...);
extern void* type_object_t_destroy(type_object_t* self, ...);
extern __ClassObject__ __type_object_t_ClassObject__;
extern __type_object_t_vClassObject__ __type_object_t_Default_vClassObject__;
extern type_object_t __type_object_t_Default_Instance__;
extern type_object_t __type_object_t_type__;
extern type_object_t* type_object_t_type;
extern __InheritanceList__ __type_object_t__InheritanceList__;
extern __InheritanceListNode__ __type_object_t__InheritanceListNodes__[8];
extern class_field_t __type_object_t_fields__[0 + 1];
extern class_field_t __type_object_t_static_fields__[0 + 1];

#define TYPE_INFO(TYPE_NAME) \
  CLS(type_object_t, __STRING(TYPE_NAME), sizeof(TYPE_NAME), NULL)

#define CLASS_INFO(CLASS_NAME) \
  CLS(type_object_t, __STRING(CLASS_NAME), sizeof(CLASS_NAME), &__##CLASS_NAME##_Default_MetaData__, NULL)

#define CLASS_INFO_OF(CLASS_INSTANCE) \
  CLS(type_object_t, \
      ((__ClassMetaData__*)(CLASS_INSTANCE))->vcls->cls->name, \
      ((__ClassMetaData__*)(CLASS_INSTANCE))->vcls->cls->instance_size, \
      ((__ClassMetaData__*)(CLASS_INSTANCE)), NULL)

Class(DefaultBase, var_object_t, type_object_t* type; void* value)

void* __aux_default_type_init__(void* self, ...);

#define VAR(TYPE...) CLS(var_object_t, \
                         ARG1_VA_ARGS(TYPE), \
                         ((ARG1_VA_ARGS(TYPE))->type_meta.vcls == NULL ? \
                           __aux_default_type_init__ : \
                           (ARG1_VA_ARGS(TYPE))->type_meta.vcls->__init__)(alloca((ARG1_VA_ARGS(TYPE))->type_size), \
                           ARG1_VA_ARGS_VA(TYPE, NULL)), \
                         NULL)
