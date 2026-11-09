#include "../src/async/co_promise.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

CorDecl(asd, int i; float f, int a; char buffer[256]);

CorDecl(asd2, int i; float f, int a;) {
  cor_init(asd2);
  printf("ASD2!\n");
  cor_return(0);
}

void call_asd_cor() {
  char buffer[256] = {};
  while (TRUE) {
    scanf("%s", buffer);
    // printf("You typed: 67\n JOking, \"%s\"\n", buffer);
  }
}

int y = 0;

CorDef(asd) {
  cor_init(asd);
  y++;
  // sleep(1);
  state->a = y;
  printf("asd!\n");
  // sleep(1);
  cor_yield(0);
  promise_t asd2p = cor_promise(asd2, NULL);
  printf("asd2!\n");
  int x = 0;
  state->buffer[10] = '\0';
  while (x < 1) {
    // scanf("%s", state->buffer);
    printf("You typed: 67\n JOking, \"%s\"\n", state->buffer);
    x++;
  }

  // call_asd_cor();

  // printf("fsf\n");
  
  cor_return((void*)((long)state->a));
}

int main() {
  promise_t pr1 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  promise_t pr2 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  promise_t pr3 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // pr_claim(pr3);
  // printf("REF:%d\n", pr3.handler->ref_count);
  // promise_t pr4 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr5 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr6 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr7 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr8 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr9 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr10 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  // promise_t pr11 = cor_promise(asd, &((asd_cor_args){.i = 0, .f = 0}), NULL);
  printf("AWAITED: %d\n", pr_await(pr1));
  printf("AWAITED: %d\n", pr_claim(pr2));
  pr_destroy(pr1);
  return 0;
}