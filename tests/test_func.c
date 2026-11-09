// #include "stdio.h"
#include "../src/oop/functional.h"

DEF_FUNC(int, x, void* s);

// call
// callable_t x_f = (callable_t){.__base__=(__BaseClass__){.__meta__=&__callable_t_Default_MetaData__}, .func_ptr=(generic_function_t)x}; int x(void* s, ...)
FUNC(int, x, void* s) {
  printf("%d\n", s);
  return 0;
}

typedef struct S {
  int y;
  int x;
  void* x_ptr;
  void* S_ptr;
} S;

int add_sds() {
  return 0;
}


LAMBDA(int s, int, o_as_int, float x, double y) {
  __F_VA_ARG__(y, 3, 0, 0, 0);
  ctx->s;
  return 1;
}

extern S e;
S e = (S){.x = 0, .S_ptr=&e, .x_ptr=&(e.x)};

int main() {
  CALL(CLS(callable_t, add_sds));
  x(0);
  CALL(&x_f, 100);
  LAMBDA_CALL(o_as_int, {.s=1}, 8787);
  callable_t* l = LAMBDA_LOAD(o_as_int, {.s=10});
  CALL(l, 90909);
  l->__meta__->vcls->__call__(l, 90909);
  printf("%d, %d - %d, %d\n", &e, &(e.x), e.S_ptr, e.x_ptr);
  return 0;
}

