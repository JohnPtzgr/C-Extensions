#include "../oop/class.h"
#include "vector.h"
#pragma once


DEF_CLASS(binary_matrix_t,
  vector_t container;
  size_t shape_x;
  size_t shape_y;
)

DEF_METHODS(__add__, __sub__, __mul__, __div__, __move__, __copy__, __assign__, __init__, __destroy__, \
  __iter__, __next__)

void* binary_matrix_add_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_add(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
