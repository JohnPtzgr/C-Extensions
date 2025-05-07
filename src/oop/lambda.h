#ifndef LAMBDA_H
#define LAMBDA_H

#include "classes.h"
#include "math.h"

#pragma once

#define LAMBDA_MAX_TOKEN_LENGTH 256

long long __LL_ADD_FUNCTION(long long a, long long b) {
  return a + b;
}

long long __LL_SUB_FUNCTION(long long a, long long b) {
  return a - b;
}

long long __LL_DIV_FUNCTION(long long a, long long b) {
  return a / b;
}

long long __LL_MUL_FUNCTION(long long a, long long b) {
  return a * b;
}

long long __LL_MOD_FUNCTION(long long a, long long b) {
  return a % b;
}

long long __LL_AND_FUNCTION(long long a, long long b) {
  return a & b;
}

long long __LL_OR_FUNCTION(long long a, long long b) {
  return a | b;
}

long long __LL_XOR_FUNCTION(long long a, long long b) {
  return a ^ b;
}

long long __LL_POW_FUNCTION(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  return __LL_POW_FUNCTION(a, b / 2) * __LL_POW_FUNCTION(a, (b + 1) / 2);
}

long double __LD_ADD_FUNCTION(long double a, long double b) {
  return a + b;
}

long double __LD_SUB_FUNCTION(long double a, long double b) {
  return a - b;
}

long double __LD_DIV_FUNCTION(long double a, long double b) {
  return a / b;
}

long double __LD_MUL_FUNCTION(long double a, long double b) {
  return a * b;
}

long double __LD_POW_FUNCTION(long double a, long double b) {
  if (b < 0) {
    return 0;
  }
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  return __LL_POW_FUNCTION(a, b / 2) * __LL_POW_FUNCTION(a, (b + 1) / 2);
}

int __LAMBDA_EXPRESSION_GET_TYPE(const __int16_t* mask) {
  return (*mask) & 7;
}

void __LAMBDA_EXPRESSION_SET_TYPE(__int16_t* mask, int type) {
  *mask &= (1 << (sizeof(__int16_t) * __CHAR_BIT__)) - 8;
}

STATIC_CLASS(lambda_t, void* data; __int16_t* mask; double* fp_vars, 2)
void* __lambda_compile(lambda_t* self, const char* string, ...) {
  char cur_token[LAMBDA_MAX_TOKEN_LENGTH];
  size_t cur_token_i = 0;
  int var_begin = 0;
  size_t stack_size = 0;
  size_t stack_capacity = 16;
  self->data = malloc(stack_capacity * sizeof(void*));
  ((void**)self->data)[0] = 0;
  for (size_t i = 0; string[i] != 0; ++i) {
    if (string[i] != ' ' &&
        string[i] != ',' &&
        string[i] != '%') {
      cur_token[cur_token_i++] = string[i];
    } else if (string[i] == '%') {
      var_begin = 1;
    } else if (string[i] == ' ' || string[i] == ',') {
      var_begin = 0;
      //if ()
    }
  }
  int prev = 0;
  return 0;
}
STATIC_CLASS_END(lambda_t, 2, ;) DEFAULT_DESTROY;

#define LAMBDA

#endif
