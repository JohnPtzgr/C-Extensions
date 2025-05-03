#include "../src/oop/templates.h"

void __TEMPLATE_1(int, add)(__T_ARG_A__* a, __T_ARG_A__* b) {
  *a += *b;
  printf("%llu\n", __T_ARG_CNT__);
}

#include "../src/oop/templates_undef.h"
