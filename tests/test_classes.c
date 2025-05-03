#include "../src/oop/classes.h"

void* f() { printf("F():"); };

CLASS(base, size_t x;, 2)
void* show(base* self, void* args) {
  printf("SHOW:%llu\n", self->x);
}
CLASS_END(base,
  MAKE_STATIC(base);
  SET_METHOD(base, __m_to_str__, self, show);
  SET_METHOD(base, __m_call__, self, show);
  printf("IS INNER BASE: %llu\n", __GET_CLASS_MASK_IS_INNER(&__base_MASK));
  self->x = 90;
  //self->__meta[0](self, 0);
) DEFAULT_DESTROY

CLASS(base2, char x; size_t y; method_function_t show, 0)
void* show2(base2* self, void* args) {
  printf("SHOW:%c\n", self->x);
}
CLASS_END(base2,
  INIT_CLASS(base2,
  SET_METHOD(base2, -2, self, __default_method__);
  printf("INIT CLASS: %llu\n", __base2_BUILT_IN_METHOD_CURRENT_INDEX__);
  )
  printf("IS INNER BASE2: %llu\n", __GET_CLASS_MASK_IS_INNER(&__base2_MASK));
  self->x = 'a';
  // SET_METHOD(base2, -1, self, __default_method__);
  SET_METHOD(base2, __m_to_str__, self, show2);
  //self->show = (method_function_t)show2;
  //self->show = (method_function_t)show2;
  //(*(&(self->show)))(self, 0);
) DEFAULT_DESTROY

INHERIT(child, base, base2 __base2, 0)
INHERIT_END(child, base,
  INHERIT_ADD(base2, &(self->__base2));
  printf("IS INNER CHLD: %llu\n", __GET_CLASS_MASK_IS_INNER(&__child_MASK));
  printf("C show: %llu, %llu, %c\n", self, (&(self->__base2))->show, 23);
) DEFAULT_DESTROY

int main() {
  INIT(base, a);
  a.x = 90;
  METHOD(base, __m_to_str__, &a);
  INIT(base2, b);
  b.x = 'q';
  METHOD(base2, __m_to_str__, &b);
  INIT(child, c);
  c.__base2.show(&c.__base2);
  PURGE_HEAP;
  return 0;
}