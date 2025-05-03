#include "../src/oop/types.h"
#include "../src/oop/classes.h"

STATIC_CLASS(cl_t, size_t x;, 0)
CLASS_END(cl_t, ;) DEFAULT_DESTROY

int funct() {
  TYPE_INFO(int, x);
  printf("%s\n", x.type_name);
  printf("%llu\n", x.meta.mask);
  CLASS_INFO(cl_t, y);
  printf("%s\n", y.type_name);
  printf("%llu\n", y.meta.mask);
  return 0;
}


int main() {
  hash_byte_array("0", 0);
  return funct();
}