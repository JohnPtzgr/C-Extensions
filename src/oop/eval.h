#include "class.h"
#include "math.h"
#include "types.h"
#include "../built-ins/int.h"

#pragma once

#define EVAL_MAX_TOKEN_LENGTH 256

typedef eval_proc_var_t;

typedef eval_proc_op_t;

DEF_CLASS(eval_proc_t,
  __vTable__* scope;
  size_t scope_indent;
  eval_proc_var_t* stack;
  eval_proc_var_t* heap;
  eval_proc_op_t* compiled_expr;
);

void* eval_compile(eval_proc_t* self, const char* string, ...);

void* eval_run(eval_proc_t* self, ...);
