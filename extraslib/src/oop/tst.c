#include "classes.h"

void* f() { printf("F():"); }

CLASS(base, size_t x;, 2)
void* show(base* self, void* args) {
  printf("SHOW:%llu\n", self->x);
}
CLASS_END(base,
  MAKE_STATIC(base);
  SET_METHOD(base, __m_to_str__, self, show);
  SET_METHOD(base, __m_call__, self, show);
  self->x = 90;
  //self->__meta[0](self, 0);
) DEFAULT_DESTROY

CLASS(base2, char x; size_t y; method_function_t show;, 0)
void* show2(base2* self, void* args) {
  printf("SHOW:%llu, %llu\n", &(self->show), self);
}
CLASS_END(base2,
  MAKE_INNER(base2);
  SET_METHOD(base2, -2, self, __default_method__);
  SET_METHOD(base2, __m_to_str__, self, show2);
  //self->show = (method_function_t)show2;
  //(*(&(self->show)))(self, 0);
) DEFAULT_DESTROY

int main() {
  printf("%llu\n", __BUILT_IN_METHOD_TABLE_SIZE__);
  INIT(base, a);
  a.x = 90;
  METHOD(base, __m_to_str__, &a);
  METHOD(base, __m_call__, &a);
  INIT(base2, b);
  b.x = 'q';
  printf("FUNC:%llu\n", show2);
  show2(&b, 0);
  METHOD(base2, __m_to_str__, &b);
  PURGE_HEAP;
  return 0;
}