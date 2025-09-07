#include "../src/oop/types.h"
#include "string.h"

DEF_CLASS(cl_t, size_t x;);
CLASS_END(cl_t, STATIC,
) DEFAULT_DESTROY(cl_t)
DEF_INIT(cl_t, ;)

DEF_CLASS(cl_add_t, size_t x;);
void* claddt_func(cl_add_t* a, cl_add_t* b, cl_add_t* c) {
  printf("ADD CLADD\n");
  c->x = a->x + b->x;
  return c;
}
CLASS_END(cl_add_t, STATIC,
  self->x = 1;
  ((__ClassMetaData__*)self)->vcls->__add__=(generic_function_t)claddt_func;
  printf("INIT CLADD!\n");
) DEFAULT_DESTROY(cl_add_t)
DEF_INIT(cl_add_t,
  __M_VA_ARG__(1, NULL);
  self->x = (size_t)(__ARG_LIST__[0]);
)



void generic_add(var_object_t* a, var_object_t* b, var_object_t* c) {
  a->type->type_meta.vcls->__add__(a->value, b->value, c->value);
}


int funct() {
  size_t v = 0;
  type_object_t* vt = TYPE_INFO(size_t);
  cl_add_t* cl = CLS(cl_add_t);
  __cl_add_t_Default_MetaData__;
  type_object_t* clt = CLASS_INFO(cl_add_t);
  var_object_t* var = VAR(clt, 100);
  printf("vt: %s, %d, %d\n%s, %d, %d",
         vt->type_name,
         vt->type_size,
         vt->type_meta.vcls,
         var->type->type_name,
         var->type->type_size,
         ((cl_add_t*)var->value)->x);
  return 0;
}


int main() {
  int q = 0;
  return funct();
}