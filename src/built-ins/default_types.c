#include "default_types.h"

#define __DEF_BI_TYPE__(TYPE) \
  void* __bi_##TYPE##_static_init(TYPE* self, ...) { \
    __M_VA_ARG__(1, 0); \
    *self = *(TYPE*)&(__ARG_LIST__[0]); \
    return self; \
  } \
   \
  __ClassObject__ __bi_##TYPE##_Class__ = (__ClassObject__){ \
                                                                 .mask=STATIC|BARE, \
                                                                 .name=#TYPE, \
                                                                 .default_meta=(__ClassMetaData__*)&TYPE##_type, \
                                                                 .default_vcls=&__bi_##TYPE##_vClass__, \
                                                                 .instance_size=sizeof(TYPE), \
                                                                 .vclass_size=sizeof(__vClassObject__), \
                                                                 .__static_init__=(generic_function_t)__bi_##TYPE##_static_init \
                                                                }; \
  __vClassObject__ __bi_##TYPE##_vClass__ = (__vClassObject__){ \
                                                                    .cls=&__bi_##TYPE##_Class__, \
                                                                    .__init__=(generic_function_t)__bi_##TYPE##_static_init \
                                                                   }; \
  type_object_t TYPE##_type = (type_object_t){ \
                                                   .type_mask=STATIC|BARE|BUILT_IN_TYPE, \
                                                   .type_meta=(__ClassMetaData__){.vcls=&__bi_##TYPE##_vClass__}, \
                                                   .type_name=#TYPE, \
                                                   .type_size=sizeof(TYPE) \
                                                  };

__DEF_BI_TYPE__(int);
__DEF_BI_TYPE__(uint);
__DEF_BI_TYPE__(long);
__DEF_BI_TYPE__(ulong);
__DEF_BI_TYPE__(char);
__DEF_BI_TYPE__(uchar);
__DEF_BI_TYPE__(short);
__DEF_BI_TYPE__(ushort);
__DEF_BI_TYPE__(int8_t);
__DEF_BI_TYPE__(uint8_t);
__DEF_BI_TYPE__(int16_t);
__DEF_BI_TYPE__(uint16_t);
__DEF_BI_TYPE__(int32_t);
__DEF_BI_TYPE__(uint32_t);
#ifdef INT64_MAX
  __DEF_BI_TYPE__(int64_t);
  __DEF_BI_TYPE__(uint64_t);
#endif
__DEF_BI_TYPE__(float);
__DEF_BI_TYPE__(double);
__DEF_BI_TYPE__(pointer);
__DEF_BI_TYPE__(BOOL);
