#include "../src/threads/task.h"
#include <stdio.h>


void* doNothingTrue(void* args) {
  return (void*)1;
}

void* callback1(void* args, ...) {
  printf("Call back!?\n");
  return (void*)1;
}

struct addrange {
  long accum;
  int* range;
  size_t len;
  size_t iter;
  size_t signal;
  pthread_mutex_t mutex;
};

int addrange_init(struct addrange* r, int sz) {
  r->range = (int*)malloc(sz * sizeof(int));
  r->len = sz;
  r->iter = 0;
  r->signal = 1;
  r->accum = 0;
  pthread_mutex_init(&(r->mutex), NULL);
  return 0;
}

int addrange_destroy(struct addrange* r) {
  free(r->range);
  pthread_mutex_destroy(&(r->mutex));
  return 0;
}

int addrange_start(struct addrange* r) {
  pthread_mutex_lock(&(r->mutex));
  int cond;
  long sum = 0;
  for (size_t i = r->iter; i < r->len && r->signal; ++i) {
    sum += r->range[i];
    r->iter = i;
    cond = ((i + 1) == r->len);
  }
  r->accum += sum;
  pthread_mutex_unlock(&(r->mutex));
  return cond;
}

int addrange_stop(struct addrange* r) {
  r->signal = 0;
  return 0;
}

int addrange_continue(struct addrange* r) {
  pthread_mutex_lock(&(r->mutex));
  r->signal = 1;
  int cond;
  long sum = 0;
  for (size_t i = r->iter; i < r->len && r->signal; ++i) {
    sum += r->range[i];
    r->iter = i;
    cond = (i + 1) == r->len;
  }
  r->accum += sum;
  pthread_mutex_unlock(&(r->mutex));
  return cond;
}

int addrange_finish(struct addrange* r) {
  pthread_mutex_lock(&(r->mutex));
  int cond;
  long sum = 0;
  for (size_t i = r->iter; i < r->len; ++i) {
    sum += r->range[i];
    r->iter = i;
    cond = ((i + 1) == r->len);
  }
  r->accum += sum;
  pthread_mutex_unlock(&(r->mutex));
  return 1;
}


int main() {

  struct addrange r = (struct addrange){};
  addrange_init(&r, 10000);
  r.range[10] = 100;

  task_t* task1 = task_new(NULL, NULL, NULL, NULL, NULL, (task_function_t)doNothingTrue, NULL, callback1, NULL, 0, 0, 0, (task_timer_t){}, NULL);
  task_t* task2 = task_new((task_function_t)addrange_start,
                           (task_function_t)addrange_stop,
                           (task_function_t)addrange_continue,
                           (task_function_t)addrange_finish,
                           (void*)&r,
                           (task_function_t)doNothingTrue,
                           NULL,
                           callback1,
                           NULL,
                           0,
                           0,
                           0,
                           (task_timer_t){},
                           NULL);
  task_t* task3 = task_new(NULL, NULL, NULL, NULL, NULL, (task_function_t)doNothingTrue, NULL, callback1, NULL, 1, 0, 0, (task_timer_t){}, NULL);
  task_manager_t manager = (task_manager_t){};

  printf("%d\n", &manager);

  task_manager_init(&manager);
  printf("Manager init\n");
  select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=100000}));
  task_manager_add_task(&manager, task1, 0);
  printf("Added task1\n");
  task_manager_add_task(&manager, task2, 0);
  printf("Added task2\n");
  task_manager_add_task(&manager, task3, 0);
  printf("Added task3\n");
  fd_set st;
  FD_ZERO(&st);
  FD_SET(0, &st);
  select(5, &st, NULL, NULL, &((struct timeval){.tv_usec=5000000}));

  printf("INPUT: %d\n", FD_ISSET(0, &st));

  // printf("INIT MAIN\n");

  select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=1000000}));

  task_manager_destroy(&manager);


  long sum = 0;
  for (size_t i = 0; i < r.len; ++i) {
    sum += r.range[i];
  }

  printf("Task sum is %ld, ACT sum is %ld\n", r.accum, sum);
  
  task_delete(task1);
  task_delete(task2);
  task_delete(task3);
  addrange_destroy(&r);
  return 0;
}