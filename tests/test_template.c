#include "stdio.h"

#define __T_ARG_A__ int
#define __T_ARG_B__
#include "test_template_f.h"

int main() {
  int a = 0;
  int b = 1;
  add_int(&a, &b);
  printf("%d\n", a);
  return 0;
}