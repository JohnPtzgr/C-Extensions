#include "stdio.h"

#define __TEMPLATE__
#define __T_ARG_A__ int
#define __T_ARG_B__
#include "test_template_f.h"
#define __TEMPLATE__
#define __T_ARG_A__ float
#include "test_template_f.h"

int add() {
  #define __TEMPLATE__
  #define __T_ARG_A__ long
  #include "test_template_f.h"
  ;

  long a = 0;
  long b = 100;
  add_long(&a, &b);
  return a;
}

#define __TEMPLATE__
#define __T_ARG_A__ int
#define __T_ARG_B__ float
#include "test_template_c.h"

int main() {
  int a = 0;
  int b = 1;
  float c = 0;
  float d = 0;
  __TEMPLATE_2(int, float, cls_t) e;
  INIT(__TEMPLATE_2(int, float, cls_t), &e);
  e.b = 90;
  add_int(&a, &b);
  add_float(&c, &d);
  printf("%d\n", a);
  printf("%d\n", add());
  printf("%d\n", e.a);
  return 0;
}