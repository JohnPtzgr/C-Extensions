#include "setjmp.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"


typedef void (*coroutine_t)(void*);

size_t x = 0;

jmp_buf buf[8];
jmp_buf zero_buf;
size_t buf_size;

void coroutineA(void* arg) {
  buf_size++;

  x++;
  printf("A0, %d\n", x);

  if (!setjmp(buf[1])) {
    longjmp(buf[0], 1);
  }

  x++;
  printf("A1, %d\n", x);

  if (!setjmp(buf[1])) {
    longjmp(buf[0], 1);
  }

  x++;
  printf("A2, %d\n", x);
  
  buf_size--;
  memcpy(&buf[1], &zero_buf, sizeof(jmp_buf));
}

void coroutineB(void* arg) {
  buf_size++;

  x++;
  printf("B0, %d\n", x);

  if (!setjmp(buf[2])) {
    longjmp(buf[0], 1);
  }

  x++;
  printf("B1, %d\n", x);

  // if (!setjmp(buf[2])) {
  //   longjmp(buf[0], 1);
  // }

  // x++;
  // printf("B2, %d\n", x);

  buf_size--;
  memcpy(&buf[2], &zero_buf, sizeof(jmp_buf));
}

void coroutine_manager(coroutine_t* coroutines, void** args) {
  size_t i = 0;
  while ((size_t)coroutines[i]) {
    if (!setjmp(buf[0])) {
      coroutines[i](args[i]);
    }
    i++;
  }
  printf("Init(%d): OK!\n", i);
  char cond = 1;
  int jump_res = 0;
  while (cond)
  {
    if (!buf_size) {
      cond = 0;
      break;
    }
    for (size_t j = 0; j < i; ++j) {
      printf("J: %d\n", j);
      if (!memcmp(&buf[1 + j], &zero_buf, sizeof(jmp_buf))) {
        printf("ZEROBUF!\n");
        continue;
      }
      if (jump_res = setjmp(buf[0])) {
        switch (jump_res)
        {
          case -1:
            cond = 0;
            break;

          case 1:
            break;

          default:
            break;
        }
      } else {
        longjmp(buf[1 + j], 1);
        break;
      }
    }
    printf("Cycle Done!\n");
    sleep(1);
  }
  printf("Done!\n");
  return;
  
}

void soft_cr_call(coroutine_t* coroutines, void** args, size_t padded_space_size) {
  char padded_space[padded_space_size];
  padded_space[0] = 0;
  coroutine_manager(coroutines, args);
}


int main() {

  coroutine_t coroutines[3] = {coroutineA, coroutineB, 0};

  void* args[3] = {NULL, NULL, NULL};

  soft_cr_call(coroutines, args, 256);

  return 0;
}