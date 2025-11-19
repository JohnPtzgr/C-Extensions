#include "../src/oop/class.h"
#include "stdio.h"

void* call(void* any) {
  printf("Call X!\n");
  return NULL;
}
Class(DefaultBase, X, int z);
DefClass(DefaultBase, X, STATIC,
  int x = 0;
  int y = self->z;
  y += 1;
  __X_Default_vClassObject__._f.__call__ = (generic_function_t)call;
) DEFAULT_DESTROY(X)
DefInit(X,
  ;
)

// int dfsf(Y* i) {
//   i->x;
//   return 0;
// }

Class(DefaultBase,
  Y,
  PRIVATE(int_t, x);
  char x;
  size_t y;,
  generic_function_t show;
);
// #include "../src/built-ins/int.h"
void* show2(Y_S* self, void* args) {
  printf("SHOW:%c\n", self->x);
  // self->__p_x->value;
  return NULL;
}
DefClass(DefaultBase, Y, 0,
  __ON_INIT__(Y,
    printf("INIT CLASS: %llu\n", self->x);
  );
  // printf("IS INNER Y: %llu\n", __GET_CLASS_MASK_IS_INNER__(&__CLASS_MASK__(Y)));
  self->x = 'a';
  self->__meta__->__cast__ = (generic_function_t)show2;
) DEFAULT_DESTROY(Y)
void* Y_init(Y_S* self, ...) {
  __AUX_INIT_BEGIN__(Y);
  // printf("META VCLS %d\n", self->__base__.__meta__->vcls);
  // printf("ACTL VCLS %d\n", &__Y_Default_vClassObject__);
  // printf("META CLS %d\n", self->__base__.__meta__->cls);
  // printf("ACTL CLS %d\n", &__Y_sClassObject__);
  // printf("VCLS CLS %d\n", __Y_Default_vClassObject__.cls);
  // printf("DMET CLS %d\n", __Y_Default_MetaData__.cls);
  self->__meta__->show = (generic_function_t)show2;
  __vTableHash__ hash = __class_vtable_hash__("show");
  printf("HASH IS %d-%d\n", hash.hashX, hash.hashY);
  __vTable_add__(self->__meta__->__meta__.__vtable__, hash, (__vTableNode__){.data=show2});
  BEGIN
  X a = (X_S){};
  __ClassMetaObject__ vbvb;
  X_init(&a);
  END
  __AUX_INIT_END__(Y);
}

int test1() {
  BEGIN
  X a = (X){};
  Y b = (Y){};
  X_init(&a);
  Y_init(&b);
  b.__meta__->show(&b, 0);
  // SMETHOD(Y, show, &b);
  // b.__meta__->__cast__(&b, 0);
  printf("Name is %s\n", a.__meta__->cls->name);
  a.z = 0;
  __vTableHash__ hash = __class_vtable_hash__("show");
  printf("HASH IS %d-%d\n", hash.hashX, hash.hashY);
  for (size_t i = 0; i < b.__meta__->__meta__.__vtable__->size; ++i) {
    printf("%d - (D) %d - (M) %d\n", i, b.__meta__->__meta__.__vtable__->data[i].data, b.__meta__->__meta__.__vtable__->data[i].mask);
  }
  // printf("show: %d\n", __vTable_get__(b.__meta__->__meta__.__vtable__, hash)->data);
  // printf("ACTL show: %d\n", show2);
  // ((generic_function_t)(__vTable_get__(b.__meta__->__meta__.__vtable__, __class_vtable_hash__("show"))->data))(&b, 0);
  END
  return 0;
}

Class(DefaultBase, base1, int c, int a, int c)
DefClass(DefaultBase, base1, 0,
  self->__meta__->a = 100;
  self->__meta__->_f.__call__ = (generic_function_t)100;
  printf("INIT BASE1!\n");
)
DEFAULT_DESTROY(base1)
void* base1_init(base1* self, ...) {
  __AUX_INIT_BEGIN__(base1)
  // __vTable
  __vTable_add__(((__ClassInstance__*)self)->__meta__->__meta__.__vtable__, __class_vtable_hash__("0"), (__vTableNode__){.data=(void*)90});
  printf("base1 DYN INIT! %d / %d\n", self, &__base1_Default_Instance__);
  __AUX_INIT_END__(base1)
  return self;
}

Class(base1, child1, int d, int b, int d)
DefClass(base1, child1, 0,
  printf("INIT CHILD1!\n");
  printf("INHERITED BASE1!\n");
) DEFAULT_DESTROY(child1)
void* child1_init(child1* self, ...) {
  __AUX_INIT_BEGIN__(child1)
  printf("child1 DYN INIT! %d / %d\n", self, &__child1_Default_Instance__);
  __AUX_INIT_END__(child1)
  return self;
}

int test2() {
  BEGIN
  base1 x = (base1){};
  base1_init(&x);
  printf("VCLS! %d\n", ((__ClassInstance__*)&x)->__meta__->cls->default_vcls);
  printf("CALL! %d\n", ((__ClassInstance__*)&x)->__meta__->_f.__call__);
  printf("VT %d\n", __vTable_get__(((__ClassInstance__*)&x)->__meta__->__meta__.__vtable__, __class_vtable_hash__("0"))->data);
  child1 y = (child1){};
  child1_init(&y);
  // for (size_t i = 0; i < __VCLASS_METHOD_COUNT__; ++i) {
  //   printf("- %d -\n", *(&(((__ClassInstance__*)&y)->__meta__->__init__) + i));
  // }
  printf("CALL! %d\n", ((__ClassInstance__*)&y)->__meta__->_f.__call__);
  printf("VT %d\n", __vTable_get__(((__ClassInstance__*)&y)->__meta__->__meta__.__vtable__, __class_vtable_hash__("0"))->data);
  END
  return 0;
}

struct pp {
  int _;
  long __;
  double ___;
};

int aaa = sizeof(struct pp);


Class(DefaultBase, base2, int c; PRIVATE(pp, dsa), int a; PRIVATE(pp, asd), int c)
//
// struct pp {
//   int a;
// };
DefClass(DefaultBase, base2, 0,
  self->c = 0;
  printf("INIT BASE2!\n");
)
DEFAULT_DESTROY(base2)
void* base2add(base2* self, base2* other) {
  printf("ADD!\n");
  // Protected
  ((__base2_vClassObjectPrt__*)self->__meta__->__meta__.__protected__->data)->c;
  // Private
  self->__p_dsa->_;
  self->__meta__->__p_asd->__;
  Static_Cast(int, self->c);
  Static_Cast(float, self);
  Dynamic_Cast(base1, base2, self);
  self->c += other->c + 100;
  return self;
}
void* base2_init(base2* self, ...) {
  __AUX_INIT_BEGIN__(base2)
  ((__ClassInstance__*)self)->__meta__->_f.__add__ = (generic_function_t)base2add;
  printf("base2 DYN INIT! %d / %d\n", self, &__base2_Default_Instance__);
  __AUX_INIT_END__(base2)
  return self;
}

// DEF_BARE_CLASS(b1, int a);
// DEF_BARE_CLASS(b2, int b);

// Class(DefaultBasechild2, int c);
// void* child2_init(child2* self, ...) {
//   __AUX_INIT_BEGIN__(child2)
//   sizeof(child2);
//   (char[9]){0};
//   sizeof(child2_type);
//   sizeof(__child2__InheritanceList__);
//   sizeof(__child2__InheritanceListNodes__);
//   sizeof(__child2_ClassObject__);
//   sizeof(__child2_Default_Instance__);
//   sizeof(__child2_Default_MetaData__);
//   sizeof(__child2_Default_vClassObject__);
//   __AUX_INIT_END__(child2)
//   return self;
// }

Class(base1, child2, base2 __base2__; int d, __base2_vClassObject__* __base2__; int b, int c)
DefClass(base1, child2, 0,
  printf("INHERITED BASE1!\n");
  // __AUX_ADD_INHERITS__(child2, base2, __base2__);
  printf("INHERITED BASE2!\n");
  printf("INIT CHILD2!\n");
) DEFAULT_DESTROY(child2)
void* child2_init(child2* self, ...) {
  __AUX_INIT_BEGIN__(child2)
  self->__base__.__meta__->a;
  Dynamic_Cast(base1, child2, self);
  sizeof(child2);
  sizeof(child2_type);
  sizeof(__child2__InheritanceList__);
  sizeof(__child2__InheritanceListNodes__);
  sizeof(__child2_ClassObject__);
  sizeof(__child2_Default_Instance__);
  sizeof(__child2_Default_vClassObject__);
  printf("child2 DYN INIT! %d / %d\n", self, &__child2_Default_Instance__);
  __AUX_INIT_END__(child2)
  return self;
}


Class(DefaultBase,
  cls_prot
  ,
  int x;
  PRIVATE(int_S, y);
  ,
  int s
  ,
  int p
)
// int q(cls_prot* self) {
//   self->__p_y->z;
//   return 0;
// }
struct int_S
{
  int z;
};

DefClass(DefaultBase,
  cls_prot,
  STATIC
) DEFAULT_DESTROY(cls_prot)
void* cls_prot_init(cls_prot* self, ...) {
  __AUX_INIT_BEGIN__(cls_prot)
  struct int_S u = (struct int_S){.z=90};
  self->__p_y = &u;
  self->__p_y->z = 888;
  printf("Z is %d\n", self->__p_y->z);
  __AUX_INIT_END__(cls_prot)
}



int test3() {
  BEGIN
  base2 a = (base2){};
  base2 b = (base2){};
  base2_init(&a);
  base2_init(&b);
  a.__meta__->a;
  a.__meta__->__meta__.__prot_vcls_data__;
  printf("BFR: %d\n", a.c);
  ((__ClassInstance__*)&a)->__meta__->_f.__add__(&a, &b);
  printf("AFT: %d\n", a.c);
  child2 c = (child2){};
  child2 d = (child2){};
  child2_init(&c);
  child2_init(&d);
  printf("ADD: %d\n", c.__base2__.c);
  ((__ClassInstance__*)&c)->__meta__->_f.__add__(&c + \
    ((__ClassInstance__*)&c)->__meta__->__method_shift__[__m_add__],
    &d + ((__ClassInstance__*)&c)->__meta__->__method_shift__[__m_add__]);
  printf("ADD: %d\n", c.__base2__.c);
  CLS(cls_prot);
  END
  return 0;
}

typedef struct c_class {
  int x;
} c_class;

BridgeClass(c_class, int st_x;)

DefBridgeClass(c_class, 0,
  self->__base__.x = 0;
) {
  sizeof(__c_class_B_ClassObject__);
  return 0;
}


int main() {
  test1();
  test2();
  test3();
  // test4();
  return 0;
}