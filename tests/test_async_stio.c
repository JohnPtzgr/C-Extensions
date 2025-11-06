#include "../src/oop/async_stio.h"
#include "stdio.h"

COROUTINE_DECL(sda, int sd; BOOL j, int sd; void* state)
COROUTINE_DECL(cda, int sd; BOOL j, int sd;)
COROUTINE_DECL(gda, int sd; BOOL j, int sd;)

COROUTINE(gda, 16) {
  COROUTINE_INIT(gda);
  printf("gda 0\n");
  COROUTINE_SAVEPOINT;
  printf("gda 1\n");
  COROUTINE_SAVEPOINT;
  printf("gda 2\n");
  COROUTINE_EXIT
}

COROUTINE(sda) {
  COROUTINE_INIT(sda);
  printf("sda 0\n");

  COROUTINE_SAVEPOINT;
  printf("sda 1\n");

  COROUTINE_CALL(gda);
  printf("gda - F\n");

  COROUTINE_SAVEPOINT;
  printf("sda 2\n");

  COROUTINE_EXIT
}

COROUTINE(cda, 512) {
  COROUTINE_INIT(cda);
  printf("cda 0\n");
  COROUTINE_SAVEPOINT;
  printf("cda 1\n");
  COROUTINE_SAVEPOINT;
  printf("cda 2\n");
  COROUTINE_EXIT
}

int main() {
  COROUTINE_ADD(sda, .sd=10, .j=1);
  COROUTINE_ADD(cda, .sd=10, .j=1);
  COROUTINE_SET_PADDING_SIZE(256);
  COROUTINE_RUN;
  return 0;
}