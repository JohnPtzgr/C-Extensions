#include "../src/oop/functional.h"

DEF_FUNC(int, x, void* s);

// call
// callable_t x_f = (callable_t){.__base__=(__BaseClass__){.__meta__=&__callable_t_Default_MetaData__}, .func_ptr=(generic_function_t)x}; int x(void* s, ...)
FUNC(int, x, void* s) {
  printf("%d\n", s);
  return 0;
}

int main() {
  x(0);
  CALL(x_f, 100);

  return 0;
}

