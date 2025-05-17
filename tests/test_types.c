#include "../src/oop/classes.h"
#include "../src/oop/types.h"
#include "string.h"

STATIC_CLASS(cl_t, size_t x;, 0)
STATIC_CLASS_END(cl_t, 0, ;) DEFAULT_DESTROY

STATIC_CLASS(cl_add_t, size_t x;, 1)
void* claddt_func(cl_add_t* a, cl_add_t* b, cl_add_t* c) {
  printf("ADD CLADD\n");
  c->x = a->x + b->x;
  return c;
}
STATIC_CLASS_END(cl_add_t, 1,
  self->x = 1;
  SET_METHOD(cl_add_t, __m_add__, self, claddt_func);
  printf("INIT CLADD!\n");
) DEFAULT_DESTROY


void generic_add(var_object_t* a, var_object_t* b, var_object_t* c) {
  VAR_METHOD(__m_add__, a, b->value, c->value);
}


int funct() {
  size_t v = 0;
  TYPE_INFO(typeof(v), vt);
  printf("VT: %s\n", vt.type_name);
  printf("VT: %u\n", vt.id);
  printf("VT: %d\n", vt.size);
  TYPE_INFO(int, x);
  printf("%s\n", x.type_name);
  printf("%llu\n", x.meta.mask);
  CLASS_INFO(cl_t, y);
  printf("%s\n", y.type_name);
  printf("%llu\n", y.meta.mask);
  var_object_t a;
  cl_t w;
  INIT(var_object_t, &a, &y, &w);
  printf("%s\n", a.type.type_name);
  printf("%d\n", a.type.meta.mask);
  a.type.meta;
  var_object_t v_a;
  var_object_t v_b;
  var_object_t v_c;
  cl_add_t add_a;
  cl_add_t add_b;
  cl_add_t add_c;
  CLASS_INFO(cl_add_t, addt);
  INIT(var_object_t, &v_a, &addt, &add_a);
  INIT(var_object_t, &v_b, &addt, &add_b);
  INIT(var_object_t, &v_c, &addt, &add_c);
  printf("%s\n", v_a.type.type_name);
  printf("%d\n", v_a.type.meta.mask);
  // void* p = VAR_METHOD(__m_add__, &v_a);
    void* q = VAR_METHOD(__m_add__, &v_a, v_a.value, v_a.value);
  //add_b.x = 90;
  printf("A: %llu, B: %llu, C: %llu\n", add_a.x, add_b.x, add_c.x);
  generic_add(&v_a, &v_b, &v_b);
  printf("A: %llu, B: %llu, C: %llu\n", add_a.x, add_b.x, add_c.x);
  var_object_t lis[10];
  // for (size_t i = 0; i < 10; ++i) {
  //   INIT(var_object_t, &(lis[i]), &addt, 0);
  //   var_object_alloc(&(lis[i]));
  // }
  return 0;
}


int main() {
  int q = 0;
  typeof(q) p = 1;
  printf("P: %d\n", p);
  hash_byte_array("0", 0);
  return funct();
}