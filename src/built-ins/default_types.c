#include "default_types.h"

#define __DEF_BI_TYPE__(TYPE, TYPE_NAME) \
  void* __bi_##TYPE_NAME##_init(TYPE* self, ...) { \
    __M_VA_ARG__(1, 0); \
    *self = *(TYPE*)&(__ARG_LIST__[0]); \
    return self; \
  } \
   \
  __ClassObject__ __bi_##TYPE_NAME##_Class__ = (__ClassObject__){ \
                                                                 .mask=STATIC|BARE, \
                                                                 .name=#TYPE, \
                                                                 .default_meta=&__bi_##TYPE_NAME##_vClass__, \
                                                                 .default_vcls=&__bi_##TYPE_NAME##_vClass__, \
                                                                 .instance_size=sizeof(TYPE), \
                                                                 .vclass_size=sizeof(__vClassObject__) \
                                                                }; \
  __vClassObject__ __bi_##TYPE_NAME##_vClass__ = (__vClassObject__){ \
                                                                    .cls=&__bi_##TYPE_NAME##_Class__, \
                                                                    .__init__=__bi_##TYPE_NAME##_init \
                                                                   }; \
  __ClassMetaData__ __bi_##TYPE_NAME##_MetaData__ = (__ClassMetaData__){ \
                                                                        .vcls=&__bi_##TYPE_NAME##_vClass__ \
                                                                       }; \
  type_object_t TYPE_NAME##_type = (type_object_t){ \
                                                   .type_mask=STATIC|BARE|BUILT_IN_TYPE, \
                                                   .type_meta=&__bi_##TYPE_NAME##_MetaData__, \
                                                   .type_name=#TYPE, \
                                                   .type_size=sizeof(TYPE) \
                                                  };


__DEF_BI_TYPE__(int, int);
__DEF_BI_TYPE__(unsigned int, uint);
__DEF_BI_TYPE__(long, long);
__DEF_BI_TYPE__(unsigned long, ulong);
__DEF_BI_TYPE__(char, char);
__DEF_BI_TYPE__(unsigned char, uchar);
__DEF_BI_TYPE__(short, short);
__DEF_BI_TYPE__(unsigned short, ushort);
__DEF_BI_TYPE__(int8_t, int8);
__DEF_BI_TYPE__(uint8_t, uint8);
__DEF_BI_TYPE__(int16_t, int16);
__DEF_BI_TYPE__(uint16_t, uint16);
__DEF_BI_TYPE__(int32_t, int32);
__DEF_BI_TYPE__(uint32_t, uint32);
#ifdef INT64_MAX
  __DEF_BI_TYPE__(int64_t, int64);
  __DEF_BI_TYPE__(uint64_t, uint64);
#endif
__DEF_BI_TYPE__(float, float);
__DEF_BI_TYPE__(double, double);
__DEF_BI_TYPE__(void*, pointer);
__DEF_BI_TYPE__(BOOL, bool);
