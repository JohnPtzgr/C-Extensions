#include "stdlib.h"
#include "stdio.h"

// extern int x;

void* doNothing(void* x) {
  return x;
}

int main() {
  //x = 90;
  // int aq[sizeof(x)] = {0, 1};

  char* a = doNothing((char[4]){0, 0, 0, 0});
  printf("%d - %d\n", a, a[0]);
  return 0;
}
