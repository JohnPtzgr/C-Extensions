#include <pthread.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdint.h>

typedef void*(*task_function_t)(void*, ...);

typedef struct task_timer_t
{
  time_t time_start;
  unsigned long long deadline_mcs;
} task_timer_t;

typedef unsigned char task_status_t;

typedef struct task_manager_t task_manager_t;

typedef enum task_status_enum {
  TSK_INVALID=-1,
  TSK_ASSIGNED,
  TSK_READY_TO_BE_EXECUTED,
  TSK_WAITING,
  TSK_RUNNING,
  TSK_DONE,
  TSK_FINISHED,
  TSK_CLAIMED,
  TSK_ACQUIRED_BY_MAIN_THREAD=16,
  TSK_ACQUIRED_BY_CONTROL_THREAD,
  TSK_ACQUIRED_BY_WORKER_THREAD,
  TSK_STOPPED = 24
} task_status_enum;

typedef unsigned char task_mask_t;

typedef struct task_t
{
  task_status_t status;
  task_mask_t mask;
  uint16_t fd_exc;
  uint32_t fd_in;
  uint32_t fd_out;
  uint32_t dependencies;
  void* task_args;
  void* check_args;
  void* callback_args;
  void* result;
  task_function_t task_start;
  task_function_t task_stop;
  task_function_t task_continue;
  task_function_t task_finish;
  task_function_t callback;
  task_function_t check;
  struct task_t* depends_on;
  struct task_t* next_task;
  struct task_t* prev_task;
  task_timer_t task_timer;
  pthread_mutex_t task_mutex;
} task_t;

task_t* task_new(task_function_t task_start,
  task_function_t task_stop,
  task_function_t task_continue,
  task_function_t task_finish,
  void* task_args,
  task_function_t check,
  void* check_args,
  task_function_t callback,
  void* callback_args,
  uint32_t fd_in,
  uint32_t fd_out,
  uint16_t fd_exc,
  task_timer_t timer,
  task_t* dependency);

void* task_delete(task_t* task);


typedef unsigned char task_worker_state_t;

typedef enum task_worker_state_enum {
  TSKW_INVALID=-1,
  TSKW_NOT_INIT,
  TSKW_INIT,
  TSKW_WAITING,
  TSKW_RUNNING,
  TSKW_ACQUIRED_BY_MAIN_THREAD=16,
  TSKW_ACQUIRED_BY_CONTROL_THREAD,
  TSKW_ACQUIRED_BY_WORKER_THREAD,
  TSKW_STOPPED = 24
} task_worker_state_enum;

typedef struct task_worker_t {
  task_worker_state_t thread_state;
  unsigned int thread_idx;
  pthread_t thread;
  task_t* current_task;
  task_manager_t* manager;
  pthread_mutex_t worker_mutex;
} task_worker_t;


typedef unsigned char task_manager_state_t;

typedef enum task_manager_state_enum {
  TSKM_INVALID=-1,
  TSKM_NOT_INIT,
  TSKM_CONTROL_THREAD_INIT,
  TSKM_WORKER_THREADS_INIT,
  TSKM_MANAGER_INIT,
  TSKM_READY,
  TSKM_ACQUIRED_BY_MAIN_THREAD=16,
  TSKM_ACQUIRED_BY_CONTROL_THREAD,
  TSKM_ACQUIRED_BY_WORKER_THREAD,
  TSKM_STOPPED = 24
} task_manager_state_enum;

#define __TASK_POOL_SIZE__ 64

#define __THREAD_POOL_SIZE__ 4

#define __TASK_PRIORITY_CNT__ 4

typedef struct task_manager_t {
  unsigned char mask;
  task_manager_state_t state;
  unsigned int task_cnt;
  task_t* tasks_request_list_head_priority[__TASK_PRIORITY_CNT__];
  pthread_t control_thread;
  pthread_mutex_t query_mutex;
  task_worker_t workers[__THREAD_POOL_SIZE__];
  fd_set fds;
} task_manager_t;

void* task_manager_init(task_manager_t* manager);
void* task_manager_controller_init(task_manager_t* manager);
void* task_manager_worker_init(task_worker_t* worker);
void* task_manager_destroy(task_manager_t* manager);
void* task_manager_add_task(task_manager_t* manager,
  task_t* task,
  int priority);
void* task_manager_await_task(task_t* task);
void* task_manager_claim_task(task_t* task);
void* task_manager_worker(task_worker_t* worker);
void* task_manager_controller(task_manager_t* manager);

