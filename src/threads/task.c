#include "task.h"
#include <stdatomic.h>
#include <alloca.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>


task_t* task_new(task_function_t t_start,
                 task_function_t t_stop,
                 task_function_t t_continue,
                 task_function_t t_finish,
                 void* t_args,
                 task_function_t check,
                 void* check_args,
                 task_function_t callback,
                 void* callback_args,
                 uint32_t fd_in,
                 uint32_t fd_out,
                 uint16_t fd_exc,
                 task_timer_t timer,
                 task_t* dependency) {
  if (!(t_start && t_stop && t_continue && t_finish)) {
    t_stop = NULL;
    t_continue = NULL;
    if (!t_start || !t_finish) {
      t_start = NULL;
      t_finish = NULL;
      t_args = NULL;
    }
  }
  task_t* task = (task_t*)malloc(sizeof(task_t));
  *task = (task_t){.task_start=t_start,
                   .task_stop=t_stop,
                   .task_continue=t_continue,
                   .task_finish=t_finish,
                   .task_args=t_args,
                   .check=check,
                   .check_args=check_args,
                   .callback=callback,
                   .callback_args=callback_args,
                   .fd_in=fd_in,
                   .fd_out=fd_out,
                   .fd_exc=fd_exc,
                   .task_timer=timer,
                   .depends_on=dependency};
  pthread_mutex_init(&(task->task_mutex), NULL);
  return task;
}

void* task_delete(task_t* task) {
  pthread_mutex_destroy(&(task->task_mutex));
  free(task);
  return NULL;
}


void* task_manager_init(task_manager_t* manager) {
  *manager = (task_manager_t){};
  pthread_mutex_init(&(manager->query_mutex), NULL);
  pthread_create(&(manager->control_thread),
                 NULL,
                 (void *(*)(void *))task_manager_controller,
                 (void*)manager);
  for (size_t i = 0; i < __THREAD_POOL_SIZE__; ++i) {
    pthread_mutex_init(&(manager->workers[i].worker_mutex), NULL);
    manager->workers[i].thread_idx = i;
    manager->workers[i].manager = manager;
    pthread_create(&(manager->workers[i].thread),
                   NULL,
                   (void *(*)(void *))task_manager_worker,
                   (void*)&(manager->workers[i]));
  }
  manager->state = TSKM_WORKER_THREADS_INIT;
  return NULL;
}

void* task_manager_destroy(task_manager_t* manager) {
  while (manager->state != TSKM_READY) {};
  pthread_mutex_lock(&(manager->query_mutex));
  manager->state = TSKM_STOPPED;
  pthread_mutex_unlock(&(manager->query_mutex));
  for (size_t i = 0; i < __THREAD_POOL_SIZE__; ++i) {
    while (manager->workers[i].thread_state < TSKW_WAITING) {};
    pthread_mutex_lock(&(manager->workers[i].worker_mutex));
    manager->workers[i].thread_state = TSKW_STOPPED;
    pthread_join(manager->workers[i].thread, NULL);
    pthread_mutex_unlock(&(manager->workers[i].worker_mutex));
    pthread_mutex_destroy(&(manager->workers[i].worker_mutex));
  }
  pthread_mutex_destroy(&(manager->query_mutex));
  return NULL;
}

void* task_manager_enqueue_priority(task_t** queue,
                                    task_t** tasks,
                                    size_t* i,
                                    fd_set* set,
                                    size_t max_i) {
  task_t* prev_task = NULL;
  task_t* cur_task = *queue;
  while (cur_task) {
    if (*i > max_i) {
      break;
    }
    struct timeval tval;
    gettimeofday(&tval, NULL);
    suseconds_t cur_time = tval.tv_usec;
    pthread_mutex_lock(&(cur_task->task_mutex));
    if ((cur_task->status == TSK_FINISHED) || (cur_task->status == TSK_CLAIMED)) {
      if (cur_task->callback) {
        cur_task->callback(cur_task->callback_args, cur_task->result, cur_task, 0);
      }
      if (prev_task) {
        pthread_mutex_lock(&(prev_task->task_mutex));
        prev_task->next_task = cur_task->next_task;
        pthread_mutex_unlock(&(prev_task->task_mutex));
      } else {
        *queue = cur_task->next_task;
      }
    } else if (cur_task->status == TSK_DONE) {
      cur_task->status = TSK_FINISHED;
      if (cur_task->depends_on) {
        pthread_mutex_lock(&(cur_task->depends_on->task_mutex));
        cur_task->depends_on->dependencies--;
        pthread_mutex_unlock(&(cur_task->depends_on->task_mutex));
      }
    } else if (cur_task->status < TSK_CLAIMED) {
      int task_mask = 1;
      if (cur_task->check) {
        task_mask &= ((size_t)cur_task->check(cur_task->check_args, cur_task, 0)) > 0;
      }
      if (cur_task->fd_in) {
        __FD_SET((cur_task->fd_in - 1) & (FD_SETSIZE - 1), set);
        select(((cur_task->fd_in - 1) & (FD_SETSIZE - 1)) + 1, set, NULL, NULL, &((struct timeval){}));
        task_mask &= (__FD_ISSET((cur_task->fd_in - 1) & (FD_SETSIZE - 1), set) > 0);
        __FD_CLR((cur_task->fd_in - 1) & (FD_SETSIZE - 1), set);
      }
      if (cur_task->fd_out) {
        __FD_SET((cur_task->fd_out - 1) & (FD_SETSIZE - 1), set);
        select(((cur_task->fd_out - 1) & (FD_SETSIZE - 1)) + 1, set, NULL, NULL, &((struct timeval){}));
        task_mask &= (__FD_ISSET((cur_task->fd_out - 1) & (FD_SETSIZE - 1), set) > 0);
        __FD_CLR((cur_task->fd_out - 1) & (FD_SETSIZE - 1), set);
      }
      if (cur_task->fd_exc) {
        __FD_SET((cur_task->fd_exc - 1) & (FD_SETSIZE - 1), set);
        select(((cur_task->fd_exc - 1) & (FD_SETSIZE - 1)) + 1, set, NULL, NULL, &((struct timeval){}));
        task_mask &= (__FD_ISSET((cur_task->fd_exc - 1) & (FD_SETSIZE - 1), set) > 0);
        __FD_CLR((cur_task->fd_exc - 1) & (FD_SETSIZE - 1), set);
      }
      if (cur_task->task_timer.time_start) {
        task_mask &= cur_time > cur_task->task_timer.time_start;
      }
      if (task_mask) {
        if (cur_task->task_start) {
          tasks[(*i)++] = cur_task;
        } else {
          cur_task->status = TSK_DONE;
        }
      }
    }
    pthread_mutex_unlock(&(cur_task->task_mutex));
    cur_task = cur_task->next_task;
  }
  return NULL;
}

void* task_manager_controller(task_manager_t* manager) {
  while (manager->state < TSKM_WORKER_THREADS_INIT) {};
  pthread_mutex_lock(&(manager->query_mutex));
  manager->state = TSKM_READY;
  pthread_mutex_unlock(&(manager->query_mutex));
  suseconds_t min_time = 100;
  struct timeval tval;
  while (manager->state != TSKM_STOPPED) {

    select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=min_time}));
    int lock = pthread_mutex_trylock(&(manager->query_mutex));

    if (lock) {
      min_time = 10;
      continue;

    } else {

      task_t* tasks[__THREAD_POOL_SIZE__] = {};
      size_t max_i = __THREAD_POOL_SIZE__;
      size_t i = 0;

      for (size_t j = 0; j < __THREAD_POOL_SIZE__; ++j) {
        if (manager->workers[j].current_task && manager->workers[j].current_task->task_stop) {
          manager->workers[j].current_task->task_stop(manager->workers[j].current_task);
        }
      }

      for (size_t j = 0; j < __TASK_PRIORITY_CNT__; ++j) {
        task_manager_enqueue_priority(&(manager->tasks_request_list_head_priority[j]),
                                      tasks,
                                      &i,
                                      &(manager->fds),
                                      max_i);
      }

      suseconds_t min_time = (tasks[0]) ? 1000 : 0;
      gettimeofday(&tval, NULL);
      suseconds_t cur_time = tval.tv_usec;
      for (size_t i = 0; i < __THREAD_POOL_SIZE__ && tasks[i]; ++i) {
        if (tasks[i]->task_timer.time_start) {
          suseconds_t rem_time = cur_time - \
                                 tasks[i]->task_timer.time_start + \
                                 tasks[i]->task_timer.deadline_mcs;
          rem_time = (rem_time > 0) ? rem_time : tasks[i]->task_timer.deadline_mcs;
          if (rem_time < min_time) {
            min_time = rem_time;
          }
        }
      }
      min_time += 100;
      pthread_mutex_unlock(&(manager->query_mutex));
      for (size_t j = 0; j < i; ++j) {
        pthread_mutex_lock(&(manager->workers[j].worker_mutex));
        manager->workers[j].current_task = tasks[j];
        pthread_mutex_unlock(&(manager->workers[j].worker_mutex));
      }
    }
  }
  return NULL;
}

void* task_manager_worker(task_worker_t* worker) {
  while (worker->manager->state < TSKM_READY) {};
  pthread_mutex_lock(&(worker->worker_mutex));
  worker->thread_state = TSKW_INIT;
  pthread_mutex_unlock(&(worker->worker_mutex));
  while (worker->thread_state != TSKW_STOPPED) {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    suseconds_t cur_time = tval.tv_usec;
    int timer = 0;
    int lock = pthread_mutex_trylock(&(worker->worker_mutex));
    if (lock) {
      select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=10}));
    } else {
      worker->thread_state = TSKW_WAITING;
      task_t* task = worker->current_task;
      if (task) {
        pthread_mutex_lock(&(task->task_mutex));
        void* result = NULL;
        if (task->status == TSK_READY_TO_BE_EXECUTED) {
          task->status = TSK_RUNNING;
          result = task->task_start(task->task_args, result, task, 0);
          task->result = result;
          task->status = TSK_WAITING;
        } else {
          if (task->task_continue) {
            task->status = TSK_RUNNING;
            result = task->task_continue(task->task_args, result, task, 0);
            task->result = result;
            task->status = TSK_WAITING;
          }
          task->status = TSK_INVALID;
        }
        if (task->task_timer.deadline_mcs && (task->status != TSK_INVALID)) {
          timer = (task->task_timer.time_start + task->task_timer.deadline_mcs) < cur_time;
        }
        if (result || timer) {
          task->result = task->task_finish(task->task_args, result, task, 0);
          task->status = TSK_DONE;
          if (task->depends_on) {
            pthread_mutex_lock(&(task->depends_on->task_mutex));
            task->depends_on->dependencies--;
            pthread_mutex_unlock(&(task->depends_on->task_mutex));
          }
        }
        pthread_mutex_unlock(&(task->task_mutex));
      }
      pthread_mutex_unlock(&(worker->worker_mutex));
      if (!task) {
        select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=1000}));
      } else {
        select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=100}));
      }
    }
  }
  return NULL;
}

void* task_manager_add_task(task_manager_t* manager,
                            task_t* task,
                            int priority) {
  priority = (priority > 0) ? priority : 0;
  priority = (priority < __TASK_PRIORITY_CNT__) ? priority : (__TASK_PRIORITY_CNT__ - 1);
  pthread_mutex_lock(&(manager->query_mutex));
  if (manager->tasks_request_list_head_priority[priority]) {
    manager->tasks_request_list_head_priority[priority]->prev_task->next_task = task;
    task->prev_task = manager->tasks_request_list_head_priority[priority]->prev_task;
  } else {
    manager->tasks_request_list_head_priority[priority] = task;
  }
  manager->tasks_request_list_head_priority[priority]->prev_task = task;
  pthread_mutex_unlock(&(manager->query_mutex));
  return NULL;
}

void* task_manager_claim_task(task_t* task) {
  if (task->status < TSK_FINISHED) {
    return NULL;
  }
  pthread_mutex_lock(&(task->task_mutex));
  task->status = TSK_CLAIMED;
  pthread_mutex_unlock(&(task->task_mutex));
  return task->result;
}

void* task_manager_await_task(task_t* task) {
  while ((task->status < TSK_FINISHED) && (task->status != TSK_INVALID)) {
    select(0, NULL, NULL, NULL, &((struct timeval){.tv_usec=10000}));
  }
  return task_manager_claim_task(task);
}

