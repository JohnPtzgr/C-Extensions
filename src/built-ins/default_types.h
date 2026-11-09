#include "../oop/types.h"
#include "inttypes.h"
#pragma once

#define BUILT_IN_TYPE 512

typedef void* pointer;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned short ushort;

extern type_object_t int_type;
extern __ClassObject__ __bi_int_Class__;
extern __vClassObject__ __bi_int_vClass__;
extern type_object_t uint_type;
extern __ClassObject__ __bi_uint_Class__;
extern __vClassObject__ __bi_uint_vClass__;
extern type_object_t long_type;
extern __ClassObject__ __bi_long_Class__;
extern __vClassObject__ __bi_long_vClass__;
extern type_object_t ulong_type;
extern __ClassObject__ __bi_ulong_Class__;
extern __vClassObject__ __bi_ulong_vClass__;
extern type_object_t char_type;
extern __ClassObject__ __bi_char_Class__;
extern __vClassObject__ __bi_char_vClass__;
extern type_object_t uchar_type;
extern __ClassObject__ __bi_uchar_Class__;
extern __vClassObject__ __bi_uchar_vClass__;
extern type_object_t short_type;
extern __ClassObject__ __bi_short_Class__;
extern __vClassObject__ __bi_short_vClass__;
extern type_object_t ushort_type;
extern __ClassObject__ __bi_ushort_Class__;
extern __vClassObject__ __bi_ushort_vClass__;
extern type_object_t int8_t_type;
extern __ClassObject__ __bi_int8_t_Class__;
extern __vClassObject__ __bi_int8_t_vClass__;
extern type_object_t uint8_t_type;
extern __ClassObject__ __bi_uint8_t_Class__;
extern __vClassObject__ __bi_uint8_t_vClass__;
extern type_object_t int16_t_type;
extern __ClassObject__ __bi_int16_t_Class__;
extern __vClassObject__ __bi_int16_t_vClass__;
extern type_object_t uint16_t_type;
extern __ClassObject__ __bi_uint16_t_Class__;
extern __vClassObject__ __bi_uint16_t_vClass__;
extern type_object_t int32_t_type;
extern __ClassObject__ __bi_int32_t_Class__;
extern __vClassObject__ __bi_int32_t_vClass__;
extern type_object_t uint32_t_type;
extern __ClassObject__ __bi_uint32_t_Class__;
extern __vClassObject__ __bi_uint32_t_vClass__;
#ifdef INT64_MAX
  extern type_object_t int64_t_type;
  extern __ClassObject__ __bi_int64_t_Class__;
  extern __vClassObject__ __bi_int64_t_vClass__;
  extern type_object_t uint64_t_type;
  extern __ClassObject__ __bi_uint64_t_Class__;
  extern __vClassObject__ __bi_uint64_t_vClass__;
#endif
extern type_object_t float_type;
extern __ClassObject__ __bi_float_Class__;
extern __vClassObject__ __bi_float_vClass__;
extern type_object_t double_type;
extern __ClassObject__ __bi_double_Class__;
extern __vClassObject__ __bi_double_vClass__;
extern type_object_t pointer_type;
extern __ClassObject__ __bi_pointer_Class__;
extern __vClassObject__ __bi_pointer_vClass__;
extern type_object_t bool_type;
extern __ClassObject__ __bi_bool_Class__;
extern __vClassObject__ __bi_bool_vClass__;
