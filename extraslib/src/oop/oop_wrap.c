#include "classes.h"

void* generic_destroy(void*) {
  printf("GENERIC DESTROY\n");
  return 0;
}

CLASS( new_t,
  size_t a,
  3)
CLASS_END( new_t,
  self->a = 0;
) {
  return self;
}

STATIC_CLASS( st_t,
  size_t a,
  3,
  (method_function_t)generic_destroy)
CLASS_END( st_t,
  printf("INITIATE ST_T\n");
  self->a = 0;
) {
  printf("DESTROY ST_T00%llu\n", self);
  return 0;
}

INHERIT( new_st,
  st_t,
  size_t q;
  method_function_t show,
  3,
  (method_function_t)generic_destroy)
void* sttjkk(new_st* self) {
  printf("%llu\n", self->q);
  return self;
}
INHERIT_END( new_st,
  st_t,
  self->q = 0;
  self->show = (method_function_t)sttjkk;
  printf("INITIATE NEW_ST\n");
) {
  //METHOD(st_t, 1, self->__base, 0);
  printf("DESTROY NEW_ST00%llu\n", self);
  return 0;
}

STATIC_INHERIT( new_st1,
  new_st,
  size_t q;
  method_function_t show,
  3,
  (method_function_t)generic_destroy)
INHERIT_END( new_st1,
  new_st,
  printf("INITIATE NEW_ST1\n");
  //static_dest1(0);
  //CLASS_META(new_st1)[0] = (method_function_t)static_dest1;
  self->q = 0;
  self->__base.q = 110;
) {
  printf("STATIC INHERIT DESTROY\n");
  return 0;
}

int fc() {
  BEGIN
  INIT(new_st, a)
  INIT(new_st1, b)
  a.show(&a);
  printf("b is %llu\n", &b);
  SCOPE_END
}


size_t opo = 90;

CLASS(myclass_t, 
  method_function_t add;
  method_function_t destroy;
  size_t q,
  3,
  (method_function_t)generic_destroy,
  (method_function_t)generic_destroy)
void* myclass_destroy(myclass_t* a) {
  printf("MYCLASS DESTROY\n");
  return 0;
}
void* myclass_add(myclass_t* a, myclass_t* b) {
  a->q += b->q;
  return 0;
}
CLASS_END( myclass_t, 
  self->destroy = (method_function_t)myclass_destroy;
  self->add = (method_function_t)myclass_add;
  self->q = opo++;
  self->__meta[0] = self->destroy;
) {
  return 0;
}

INHERIT(child_t, myclass_t, size_t b; method_function_t add, 4)
void* child_add(child_t* a, child_t* b) {
  a->b += b->b;
  a->__base.add(&a->__base, &b->__base);
  return a;
}
INHERIT_END(child_t, myclass_t,
  self->add = (method_function_t)child_add;
  self->b = 0;
) {
  return 0;
}

FUNC(int, func, int a, int b)
  INIT(myclass_t, x);
  FOR(size_t i = 0, i < 3, ++i)
    INIT(myclass_t, y);
    x.add(&x, &y);
    printf("NEW VAL is %llu\n", x.q);
  END
  FOREACH(void*, x, __SCOPE_STACK)
    printf("ADR: %llu\n", x);
  END
  RETURN(a + b)
END

int main() {
  BEGIN
  int a = 0;
  fc();
  func(0, 0);
  SCOPE_END
  return 0;
}