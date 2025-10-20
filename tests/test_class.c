#include "../src/oop/class.h"

__GENERIC_CLASS_DECLARE_MACRO__(X, __BaseClass__ __base__; int z;, int x; int y;, int z, 0, 0, int xxyy = 1);

void* call(void* any) {
  printf("Call X!\n");
  return NULL;
}

__GENERIC_CLASS_DEFINE_MACRO__(X, STATIC,
  int x = 0;
  int y = self->z;
  y += 1;
  __X_Default_vClassObject__.__call__ = (generic_function_t)call;
) DEFAULT_DESTROY(X)
DEF_INIT(X,
  ;
)

// BARE_CLASS(Y, ;, ;,int x;)

// int dfsf(Y* i) {
//   i->x;
//   return 0;
// }

DEF_CLASS(Y,
  PRIVATE(int_t, x);
  char x;
  size_t y;,  
  generic_function_t show;
)
// #include "../src/built-ins/int.h"
void* show2(Y* self, void* args) {
  printf("SHOW:%c\n", self->x);
  // self->__p_x->value;
  return NULL;
}
CLASS_END(Y, 0,
  __ON_INIT__(Y,
    printf("INIT CLASS: %llu\n", self->x);
  );
  printf("IS INNER Y: %llu\n", __GET_CLASS_MASK_IS_INNER__(&__CLASS_MASK__(Y)));
  self->x = 'a';
  self->__meta__->vcls->__cast__ = (generic_function_t)show2;
  __AUX_SMETHOD__(Y, show, self) = (generic_function_t)show2;
) DEFAULT_DESTROY(Y)
void* Y_init(Y* self, ...) {
  __AUX_INIT_BEGIN__(Y);
  // printf("META VCLS %d\n", self->__base__.__meta__->vcls);
  // printf("ACTL VCLS %d\n", &__Y_Default_vClassObject__);
  // printf("META CLS %d\n", self->__base__.__meta__->vcls->cls);
  // printf("ACTL CLS %d\n", &__Y_sClassObject__);
  // printf("VCLS CLS %d\n", __Y_Default_vClassObject__.cls);
  // printf("DMET CLS %d\n", __Y_Default_MetaData__.vcls->cls);
  __vTableHash__ hash = __class_vtable_hash__("show");
  printf("HASH IS %d-%d\n", hash.hashX, hash.hashY);
  __vTable_add__(self->__meta__->vcls->vtable, hash, (__vTableNode__){.data=show2});
  BEGIN
  X a = (X){};
  __ClassMetaData__ vbvb;
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
  SMETHOD(Y, show, &b);
  b.__meta__->vcls->__cast__(&b, 0);
  printf("Name is %s\n", a.__base__.__meta__->vcls->cls->name);
  a.z = 0;
  __vTableHash__ hash = __class_vtable_hash__("show");
  printf("HASH IS %d-%d\n", hash.hashX, hash.hashY);
  for (size_t i = 0; i < b.__meta__->vcls->vtable->size; ++i) {
    printf("%d - (D) %d - (M) %d\n", i, b.__meta__->vcls->vtable->data[i].data, b.__meta__->vcls->vtable->data[i].mask);
  }
  printf("show: %d\n", __vTable_get__(b.__meta__->vcls->vtable, hash)->data);
  printf("ACTL show: %d\n", show2);
  ((generic_function_t)(__vTable_get__(b.__meta__->vcls->vtable, __class_vtable_hash__("show"))->data))(&b, 0);
  END
  return 0;
}

DEF_CLASS(base1, int c, int a, int c)
CLASS_END(base1, 0,
  ((__base1_vClassObject__*)((__ClassInstance__*)self)->__meta__->vcls)->a = 100;
  ((__ClassInstance__*)self)->__meta__->vcls->__call__ = (generic_function_t)100;
  printf("INIT BASE1!\n");
)
DEFAULT_DESTROY(base1)
void* base1_init(base1* self, ...) {
  __AUX_INIT_BEGIN__(base1)
  __vTable_add__(((__ClassInstance__*)self)->__meta__->vtable, __class_vtable_hash__("0"), (__vTableNode__){.data=(void*)90});
  printf("base1 DYN INIT! %d / %d\n", self, &__base1_Default_Instance__);
  __AUX_INIT_END__(base1)
  return self;
}

DEF_INHERIT(child1, base1, int d, int b, int d)
INHERIT_END(child1, base1, 0,
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
  printf("VCLS! %d\n", ((__ClassInstance__*)&x)->__meta__->vcls->cls->default_vcls);
  printf("CALL! %d\n", ((__ClassInstance__*)&x)->__meta__->vcls->__call__);
  printf("VT %d\n", __vTable_get__(((__ClassInstance__*)&x)->__meta__->vtable, __class_vtable_hash__("0"))->data);
  child1 y = (child1){};
  child1_init(&y);
  // for (size_t i = 0; i < __VCLASS_METHOD_COUNT__; ++i) {
  //   printf("- %d -\n", *(&(((__ClassInstance__*)&y)->__meta__->vcls->__init__) + i));
  // }
  printf("CALL! %d\n", ((__ClassInstance__*)&y)->__meta__->vcls->__call__);
  printf("VT %d\n", __vTable_get__(((__ClassInstance__*)&y)->__meta__->vtable, __class_vtable_hash__("0"))->data);
  END
  return 0;
}

struct pp {
  int _;
  long __;
  double ___;
};

int aaa = sizeof(struct pp);


DEF_CLASS(base2, int c; PRIVATE(pp, dsa), int a; PRIVATE(pp, asd), int c)
//
struct pp {
  int a;
};
CLASS_END(base2, 0,
  self->c = 0;
  printf("INIT BASE2!\n");
)
DEFAULT_DESTROY(base2)
void* base2add(base2* self, base2* other) {
  printf("ADD!\n");
  // Protected
  ((__base2_vClassObjectPrt__*)self->__meta__->vcls->__protected__->data)->c;
  // Private
  self->__p_dsa->a;
  self->__meta__->vcls->__p_asd->a;
  STATIC_CAST(int, self->c);
  STATIC_CAST(float, self);
  DYNAMIC_CAST(base1, base2, self);
  self->c += other->c + 100;
  return self;
}
void* base2_init(base2* self, ...) {
  __AUX_INIT_BEGIN__(base2)
  ((__ClassInstance__*)self)->__meta__->vcls->__add__ = (generic_function_t)base2add;
  printf("base2 DYN INIT! %d / %d\n", self, &__base2_Default_Instance__);
  __AUX_INIT_END__(base2)
  return self;
}

// DEF_BARE_CLASS(b1, int a);
// DEF_BARE_CLASS(b2, int b);

// DEF_CLASS(child2, int c);
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

DEF_INHERIT(child2, base1, base2 __base2__; int d, __base2_vClassObject__* __base2__; int b, int c)
INHERIT_END(child2, base1, 0,
  printf("INHERITED BASE1!\n");
  __AUX_ADD_INHERITS__(child2, base2, __base2__);
  printf("INHERITED BASE2!\n");
  printf("INIT CHILD2!\n");
) DEFAULT_DESTROY(child2)
void* child2_init(child2* self, ...) {
  __AUX_INIT_BEGIN__(child2)
  self->__meta__->vcls->__base__->a;
  DYNAMIC_CAST(base1, child2, self);
  sizeof(child2);
  sizeof(child2_type);
  sizeof(__child2__InheritanceList__);
  sizeof(__child2__InheritanceListNodes__);
  sizeof(__child2_ClassObject__);
  sizeof(__child2_Default_Instance__);
  sizeof(__child2_Default_MetaData__);
  sizeof(__child2_Default_vClassObject__);
  printf("child2 DYN INIT! %d / %d\n", self, &__child2_Default_Instance__);
  __AUX_INIT_END__(child2)
  return self;
}


DEF_CLASS(cls_prot
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

CLASS_END(cls_prot, STATIC,
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
  a.__meta__->vcls->a;
  a.__meta__->vcls->__prot_vcls_data__;
  printf("BFR: %d\n", a.c);
  ((__ClassInstance__*)&a)->__meta__->vcls->__add__(&a, &b);
  printf("AFT: %d\n", a.c);
  child2 c = (child2){};
  child2 d = (child2){};
  child2_init(&c);
  child2_init(&d);
  printf("ADD: %d\n", c.__base2__.c);
  ((__ClassInstance__*)&c)->__meta__->vcls->__add__(&c + \
    ((__ClassInstance__*)&c)->__meta__->vcls->method_shift[__m_add__],
    &d + ((__ClassInstance__*)&c)->__meta__->vcls->method_shift[__m_add__]);
  printf("ADD: %d\n", c.__base2__.c);
  CLS(cls_prot);
  END
  return 0;
}

typedef struct c_class {
  int x;
} c_class;

DEF_BRIDGE(c_class, int st_x;)

BRIDGE_END(c_class, 0,
  self->__base__.x = 0;
) {
  sizeof(__c_class_B_ClassObject__.default_vcls->protected);
  return 0;
}


int main() {
  test1();
  test2();
  test3();
  // test4();
  return 0;
}