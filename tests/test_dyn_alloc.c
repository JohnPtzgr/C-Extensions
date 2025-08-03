#include "../src/memory/dyn_alloc_.h"

void* doNothing(void* x, ...) {
  printf("X = %d\n", x);
  return 0;
}

void* destroyX(void* x, ...) {
  printf("DESTROY X = %d\n", x);
  return 0;
}

void* checkX(void* x, ...) {
  printf("CHECK X = %d\n", x);
  return 0;
}

int test_scope_stack() {
  __SCOPE_STACK__ stack;
  __SCOPE_DEFER_POOL__ pool;
  printf("0\n");
  __scope_stack_init__(&stack);
  __scope_defer_pool_init__(&pool);
  printf("1\n");
  int x = 0;
  __scope_defer_pool_enter__(&pool);
  __scope_stack_push__(&stack, destroyX, &x);
  __scope_defer_pool_add_token__(&pool);
  printf("2\n");
  void* y = __scope_stack_top__(&stack);
  __scope_defer_pool_add_token__(&pool);
  __scope_stack_push__(&stack, destroyX, y);
  __scope_stack_push__(&stack, destroyX, y);
  __scope_stack_defer_instance__(&stack, &pool, y, checkX);
  printf("3\n");
  x = 100;
  if (x != *(int*)y) {
    printf("Wrong instance on stack top!");
    *(int*)NULL;
  }
  __scope_stack_pop__(&stack);
  __scope_defer_pool_escape__(&pool);
  printf("4\n");
  __scope_stack_destroy__(&stack);
  printf("5\n");
  __scope_defer_pool_destroy__(&pool);
  printf("6\n");
  return 0;
}


int main() {
  test_scope_stack();
  return 0;
}