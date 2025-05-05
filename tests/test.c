#include "stdlib.h"
#include "stdio.h"

extern int x;

int main() {
  //x = 90;
  int aq[sizeof(x)] = {0, 1};
  printf("%d\n", x);
  return 0;
}
