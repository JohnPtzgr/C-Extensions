#include "../../src/threads/task.h"


typedef struct async_promise_t {
  task_function_t callback;
  void* callback_args;
  pthread_mutex_t mutex;
  pthread_cond_t condition;
  task_t task;
} async_promise_t;

int async_promise_check(async_promise_t* promise);

int async_promise_callback(async_promise_t* promise);

void* async_promise_await(async_promise_t* promise);

task_t* async_promise_new(task_function_t call,
  void* call_args,
  task_function_t check,
  void* check_args,
  task_function_t callback,
  void* callback_args,
  uint32_t fd_in,
  uint32_t fd_out,
  uint16_t fd_exc,
  task_timer_t timer,
  async_promise_t* dependency);

void* async_promise_delete(async_promise_t* promise);
