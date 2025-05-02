#include "../src/oop/types.h"
#include "../src/oop/classes.h"


int funct() {
  DECL_TYPE(int);
  printf("%s\n", __int_TYPE_VAR__.type_name);
  return 0;
}


int main() {
  return funct();
}