#ifndef MATRIX_H
#define MATRIX_H

#include "../oop/class.h"
#include "vector.h"


DEF_CLASS(binary_matrix_t,
  ,
  vector_t container;
  size_t shape_x;
  size_t shape_y;
)
void* binary_matrix_add_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_add(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);

#endif
