#include "../src/memory/dyn_alloc_.h"

void* doNothing(void* x, ...) {
  return 0;
}

int test_scope_stack() {
  __SCOPE_STACK__ stack;
  __scope_stack_init__(&stack);
  int x = 0;
  __scope_stack_push__(&stack, doNothing, &x);
  __scope_stack_pop__(&stack);
  __scope_defer_stack_destroy__(&stack);

}


int main() {
  test_scope_stack();
  return 0;
}