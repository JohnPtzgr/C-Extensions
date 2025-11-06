// #define __STRUCT_SUFFIX__
#define __CLASS_SUFFIX__ _S, , ,*


#include "../src/oop/class.h"

struct test_class_t
{
  ARG1_VA_ARGS_VA(int, long) b;
};

// #undef __CLASS_SUFFIX__
// #define __CLASS_SUFFIX__ _y

Class(DefaultBase, tst_c, int z, int w)

// class_field_t* __tst_c_fields__ = (ListClassFields(ClassField(tst_c, z, &(type_object_t){.type_name="int", .type_size=sizeof(int)})));
// class_field_t* __tst_c_static_fields__ = ListClassFields(StaticField(tst_c, w, &(type_object_t){.type_name="int", .type_size=sizeof(int)}));

DefClass(DefaultBase, tst_c, 0,
  self->z = 0;
  printf("TST_C init!\n");
) DEFAULT_DESTROY(tst_c)

DefInit(tst_c)

int asda() {
  struct tst_c_S as;
  // as.__base__.__meta__->cls;
  // tst_c da;
  // tst_c_y jkj;
  // da->z;
  // da.z;
  // jkj.z;
  // da->__base__.__meta__->cls;
}

// BareClass(DefaultBase, tst_b)
// BridgeClass(int)


// #define _CLASS tst_c


// int p() {
//   _CLASS a;
//   a.__meta__->cls;
//   // _C.__init__(&a);
//   _C.method_shift;
//   AsInterface(&a, &_C);
//   SMETHOD(_CLASS, __call__, 0);
// }

// #undef _CLASS

// void* tst_b_cast(tst_b* self,
//                  type_object_t* src_type,
//                  type_object_t* trg_type,
//                  void* expr) {
//   printf("B Cast<=>\n");
//   sizeof(tst_b);
//   return self;
// }

// DefClass(DefaultBase, tst_c, 0,
//   tst_b_type->type_meta->__cast__=(generic_function_t)tst_b_cast;
//   printf("C Static init\n");
// )
// { printf("C Static destroy!\n"); }
// void* tst_c_destroy(tst_c* self, ...) {
//   printf("C Destroy!\n");
// }
// DefInit(tst_c, printf("C Init\n");)
// // DEFAULT_DESTROY(tst_c) DEFAULT_INIT(tst_c);


// DefClass(DefaultBase, tst_b, BARE,
//   printf("B Static init\n");
// ) { printf("B Static destroy!\n"); }
// void* tst_b_destroy(tst_b* self, ...) {
//   printf("B Destroy!\n");
// }
// DefInit(tst_b, printf("B Init\n");)
// // DEFAULT_DESTROY(tst_b) DEFAULT_INIT(tst_b);

// DefBridgeClass(int, STATIC|BARE) { return NULL; };


    // generic_function_t __init__;
    // //
    // generic_function_t __move__;
    // __tst_c_FundamentalVClass__ _f;
    // __ClassObject__* cls;
    // //
    // unsigned int* __method_shift__;
    // STATIC_CLASS_FIELDS;
    // __meta__

int main() {
  SCOPE_BEGIN;
  sizeof(__DefaultBase_Default_vClassObject__.__meta__);
  // tst_c a = CLS(tst_c);
  // Class_Cast(tst_b, tst_c, a);
  // ((__vClassObject__*)NULL)->__add__(0);
  // SMETHOD(tst_c, _f.__add__, a);
  SCOPE_END;
}