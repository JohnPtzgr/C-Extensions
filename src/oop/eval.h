#include "class.h"
#include "math.h"

#pragma once

#define LAMBDA_MAX_TOKEN_LENGTH 256

long long __LL_ADD_FUNCTION(long long a, long long b);

long long __LL_SUB_FUNCTION(long long a, long long b);

long long __LL_DIV_FUNCTION(long long a, long long b);

long long __LL_MUL_FUNCTION(long long a, long long b);

long long __LL_MOD_FUNCTION(long long a, long long b);

long long __LL_AND_FUNCTION(long long a, long long b);

long long __LL_OR_FUNCTION(long long a, long long b);

long long __LL_XOR_FUNCTION(long long a, long long b);

long long __LL_POW_FUNCTION(long long a, long long b);

long double __LD_ADD_FUNCTION(long double a, long double b);

long double __LD_SUB_FUNCTION(long double a, long double b);

long double __LD_DIV_FUNCTION(long double a, long double b);

long double __LD_MUL_FUNCTION(long double a, long double b);

long double __LD_POW_FUNCTION(long double a, long double b);

int __LAMBDA_EXPRESSION_GET_TYPE(const __int16_t* mask);

void __LAMBDA_EXPRESSION_SET_TYPE(__int16_t* mask, int type);

DEF_CLASS(lambda_t, void* data; __int16_t* mask; double* fp_vars)
void* __lambda_compile(lambda_t* self, const char* string, ...);
