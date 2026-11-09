#include "../src/built-ins/int.h"
#include "../src/algorithm/container.h"

struct ss {
  char q;
  int a;
};

struct test_int
{
  int sa;
  void* a;
  int_t sd;
  struct int_t i;
  char b[8];
  struct ss as;
};


int main() {
  int_t* i = Int(100);
  iterator_t itr;
  generic_container_t cnt;
  // cnt.__meta__->vcls->clear(NULL);
  struct test_int tst = (struct test_int){.i=*i};
  tst.i.value;
  sizeof(struct test_int);
  sizeof(__int_t_vClassObject__);
  sizeof(__int_t_vClassObjectPrt__);
  ((__int_t_vClassObjectPrt__*)(i->__meta__->vcls->__protected__))->default_protected.data = printf;
  ((generic_function_t)((__int_t_vClassObjectPrt__*)(i->__meta__->vcls->__protected__))->default_protected.data)("0, %d, %d, %d\n", sizeof(struct test_int), sizeof(int_t), tst.i.value);
  return 0;
}