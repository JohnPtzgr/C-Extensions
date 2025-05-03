#define __T_ARG_A__ int
#include "../src/algorithm/linked_list.h"

int main() {
  linked_list_t l;
  LinkedList_int(&l);
  int h = 0;
  l.push(&l, h);
  printf("LLHEAD: %d\n", l.head->value);
  return 0;
}
