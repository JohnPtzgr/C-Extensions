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

extern S e;
S e = (S){.x = 0, .S_ptr=&e, .x_ptr=&(e.x)};

int main() {
  x(0);
  CALL(x_f, 100);
  printf("%d, %d - %d, %d\n", &e, &(e.x), e.S_ptr, e.x_ptr);
  return 0;
}

