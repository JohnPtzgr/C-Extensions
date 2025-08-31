#include "test_some.h"
#include "../src/oop/iters.h"


int_t* expexc(int_t* self, int_t* other, int_t* result) {
  EXC_ASSERT(other->value >= 0 && "Negative Power is not allowed!");
  return self->__base__.__meta__->vcls->__pow__(self, other, result);
}


int main() {
  BEGIN
  int_t a = *Int(1110);
  int_t b = *Int(8889);
  int_t* c = NEW(int_t, 10, 100);
  int_t* d = CLS(int_t);
  int_t* e = Int(10);
  ((__ClassInstance__*)&a)->__meta__->vcls->__iadd__(&a, &b);
  ((__ClassInstance__*)&a)->__meta__->vcls->__imul__(&a, e);
  iterator_t* it = Iter(c, c + 10);
  printf("%d - %d\n", a.value, c->value);
  while (it) {
    printf("%d\n", ((int_t*)it->cur_ptr)->value);
    it = IterNext(it);
  }
  int_t* pow = Int(-5l);
  int_t* result = Int(0);
  TRY {
    expexc(e, pow, result);
    BREAKPOINT;
  } CATCH {
    _EXCEPTION = CAUGHT_EXCEPTION;
    _EXCEPTION_CONTEXT = CAUGHT_EXCEPTION_CONTEXT;
    printf("Caught error!\n");
  } FINALLY {
    printf("Value is %d\n", result->value);
  }
  END
  // free(c);
  return 0;
}