#include "class.h"

Class(DefaultBase, tst_c, int z, int w)
BareClass(DefaultBase, tst_b)
BridgeClass(int)


#define _CLASS tst_c


int a = (__AUX_16_BYTE_HASH__('a', 'b', 'c', 'k'));
__vTableHash__ h = (__AUX_16_BYTE_VHASH__('a', 'b', 'c', 'k'));


int p() {
  _CLASS a;
  a.__meta__->cls;
  // _C.__init__(&a);
  _C.method_shift;
  AsInterface(&a, &_C);
  SMETHOD(_CLASS, __call__, 0);
}

#undef _CLASS

void* tst_b_cast(tst_b* self,
                 type_object_t* src_type,
                 type_object_t* trg_type,
                 void* expr) {
  printf("B Cast<=>\n");
  sizeof(tst_b);
  return self;
}

DefClass(DefaultBase, tst_c, 0,
  tst_b_type->type_meta->__cast__=(generic_function_t)tst_b_cast;
  printf("C Static init\n");
) { printf("C Static destroy!\n"); }
void* tst_c_destroy(tst_c* self, ...) {
  printf("C Destroy!\n");
}
DefInit(tst_c, printf("C Init\n");)
// DEFAULT_DESTROY(tst_c) DEFAULT_INIT(tst_c);


DefClass(DefaultBase, tst_b, BARE,
  printf("B Static init\n");
) { printf("B Static destroy!\n"); }
void* tst_b_destroy(tst_b* self, ...) {
  printf("B Destroy!\n");
}
DefInit(tst_b, printf("B Init\n");)
// DEFAULT_DESTROY(tst_b) DEFAULT_INIT(tst_b);


DefClass(DefaultBase, int_B, STATIC|BARE) DEFAULT_DESTROY(int_B) DEFAULT_INIT(int_B);

int main() {
  SCOPE_BEGIN
  tst_c* a = CLS(tst_c);
  // Class_Cast(tst_b, tst_c, a);
  ((__vClassObject__*)NULL)->__add__(0);
  SMETHOD(tst_c, __add__, a);
  SCOPE_END
}