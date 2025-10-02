#include "cextras.h"

int main() {
  var_object_t* x = VAR(&int_type, -80);
  BOOL b = strcmp(x->type->type_name, "int") == 0;
  printf("%s\n%s\n%d:%d\n%s\n", int_type.type_name, pointer_type.type_name, *(int*)x->value, b, x->type->type_name);
}