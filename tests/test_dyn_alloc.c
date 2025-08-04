#include "../src/memory/dyn_alloc_.h"

void* doNothing(void* x, ...) {
  printf("X = %d\n", x);
  return 0;
}

void* destroyX(void* x, void* y, void* z, void* w) {
  printf("DESTROY X = %d, %d, %d, %d\n", x, y, z, w);
  return 0;
}

void* checkX(void* x, void* y, void* z, void* w) {
  printf("CHECK X = %d, %d, %d, %d\n", x, y, z, w);
  return (void*)FALSE;
}

int test_scope_stack() {
  __SCOPE_DEFER_POOL__ pool;
  __SCOPE_STACK__ stack;
  __SCOPE_OBJECT__ scope;
  __scope_object_init__(&scope, &stack, &pool);
  int x = 0;
  SCOPE_BEGIN
  for (size_t i = 0; i < 2; ++i) {
    STAGE(x, (generic_function_t)destroyX, 1, 2, 3)
    STAGE(x, (generic_function_t)checkX, 4, 5, 6)
    // __scope_object_stage__(&scope, &x, destroyX, 0);
    // __scope_object_stage__(&scope, &x, 0, checkX, 0);
  }
  printf("FINISH\n");
  SCOPE_END
  __scope_object_destroy__(&scope);
  return 0;
}


int main() {
  SCOPE_BEGIN
  test_scope_stack();
  SCOPE_END
  return 0;
}