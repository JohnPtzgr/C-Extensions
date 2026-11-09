#include "../src/memory/dyn_alloc.h"
// #include <pthread.h>

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
  int x = 100;
  SCOPE_BEGIN
  int* y = ALLOC(16, int);
  for (size_t i = 0; i < 16; ++i) {
    printf("I - %d\n", y[i]);
  }
  FORCE_RELEASE(y);
  SKIP(y);
  for (size_t i = 0; i < 2; ++i) {
    STAGE(&x, destroyX, 1, 2, 3);
    STAGE(&x, checkX, 4, 5, 6);
    // __scope_object_stage__(&scope, &x, destroyX, 0);
    // __scope_object_stage__(&scope, &x, 0, checkX, 0);
  }
  STAGE(&x, checkX);
  SKIP(&x);
  SCOPE_END
  printf("FINISH\n");
  checkX(&x, (void*)4, (void*)5, (void*)6);
  __scope_object_destroy__(&scope);
  return 0;
}


int main()
// {
//   printf("%d\n", *(pthread_t**)__aux_mt_thread_ids_ptr__);
// }
BEGIN
  test_scope_stack();
  RETURN(0);
END
