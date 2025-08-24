#include "async.h"


int async_promise_check(async_promise_t* promise) {
  return promise->task.status == TSK_FINISHED;
}

int async_promise_callback(async_promise_t* promise) {
  if (promise->callback) {
    promise->callback(promise->callback_args, 0);
  }
  pthread_mutex_lock(&(promise->mutex));
  pthread_cond_signal(&(promise->condition));
  pthread_mutex_unlock(&(promise->mutex));
  return 0;
}

void* async_promise_await(async_promise_t* promise) {
  pthread_mutex_lock(&(promise->mutex));
  while (promise->task.status != TSK_FINISHED) {
    pthread_cond_timedwait(&(promise->condition),
                           &(promise->mutex),
                           &((struct timespec){.tv_sec=1}));
  }
  pthread_mutex_unlock(&(promise->mutex));
  return promise->task.result;
}

void* async_promise_finish(void* args, void* result) {
  return result;
}

async_promise_t* async_promise_new(task_function_t call,
                          void* call_args,
                          task_function_t check,
                          void* check_args,
                          task_function_t callback,
                          void* callback_args,
                          uint32_t fd_in,
                          uint32_t fd_out,
                          uint16_t fd_exc,
                          task_timer_t timer,
                          async_promise_t* dependency) {
  async_promise_t* promise = (async_promise_t*)malloc(sizeof(async_promise_t));
  (*promise).task = (task_t){.task_start=call,
                             .task_stop=NULL,
                             .task_continue=NULL,
                             .task_finish=(task_function_t)async_promise_finish,
                             .task_args=call_args,
                             .check=check,
                             .check_args=check_args,
                             .callback=(task_function_t)async_promise_callback,
                             .callback_args=promise,
                             .fd_in=fd_in,
                             .fd_out=fd_out,
                             .fd_exc=fd_exc,
                             .task_timer=timer,
                             .depends_on=&(dependency->task)};
  promise->callback = callback;
  promise->callback_args = callback_args;
  pthread_mutex_init(&(promise->task.task_mutex), NULL);
  pthread_mutex_init(&(promise->mutex), NULL);
  pthread_cond_init(&(promise->condition), NULL);
  return promise;
}

void* async_promise_delete(async_promise_t* promise) {
  pthread_mutex_destroy(&(promise->mutex));
  pthread_mutex_destroy(&(promise->task.task_mutex));
  pthread_cond_destroy(&(promise->condition));
  free(promise);
  return NULL;
}