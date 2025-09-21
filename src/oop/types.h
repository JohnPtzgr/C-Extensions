#include "class.h"
#include <string.h>

#pragma once


typedef struct __type_object_t_ClassMetaData__ __type_object_t_ClassMetaData__;
typedef struct __type_object_t_vClassObjectPrt__ { __vClassObjectPrt__ default_protected; }
__type_object_t_vClassObjectPrt__;
typedef struct __type_object_t_vClassObject__ {
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __to_str__;
  generic_function_t __data__;
  generic_function_t __iter__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __len__;
  generic_function_t __neg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __contains__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __cmp__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __pow__;
  generic_function_t __cast__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;
  generic_function_t __ineg__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __id__;
  unsigned int* method_shift;
  class_structure_t fields;
  class_structure_t static_fields;
  __ClassObject__* cls;
  __vTable__* vtable;
  __vClassObjectPrt__* __protected__;
  char __prot_vcls_data__[sizeof(__type_object_t_vClassObjectPrt__)];
  unsigned int __method_shift__[64 + 0 + 0];
  class_field_t __fields__[0];
  class_field_t __static_fields__[0];
} __type_object_t_vClassObject__;
typedef struct __type_object_t_ClassMetaData__ {
  __type_object_t_vClassObject__* vcls;
  __vTable__* vtable;
} __type_object_t_ClassMetaData__;
extern void* __type_object_t_static_init__(type_object_t* self);
extern void* __type_object_t_static_destroy__(type_object_t* self);
extern void* type_object_t_init(type_object_t* self , ...);
extern void* type_object_t_destroy(type_object_t* self, ...);
extern __ClassObject__ __type_object_t_ClassObject__;
extern __type_object_t_vClassObject__ __type_object_t_Default_vClassObject__;
extern type_object_t __type_object_t_Default_Instance__;
extern __type_object_t_ClassMetaData__ __type_object_t_Default_MetaData__;
extern type_object_t type_object_t_type;

#define TYPE_INFO(TYPE_NAME) \
  CLS(type_object_t, __STRING(TYPE_NAME), sizeof(TYPE_NAME), NULL)

#define CLASS_INFO(CLASS_NAME) \
  CLS(type_object_t, __STRING(CLASS_NAME), sizeof(CLASS_NAME), &__##CLASS_NAME##_Default_MetaData__, NULL)

#define CLASS_INFO_OF(CLASS_INSTANCE) \
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
