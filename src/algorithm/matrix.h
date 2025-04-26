#include "oop/classes.h"
#include "vector.h"

STATIC_CLASS(binary_matrix_t,
vector_t container;
size_t shape_x;
size_t shape_y,
10)
void* binary_matrix_add_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_add(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_sub(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul_self(binary_matrix_t*, binary_matrix_t*);
void* binary_matrix_mul(binary_matrix_t*, binary_matrix_t*, binary_matrix_t*);
CLASS_END(binary_matrix_t,
) {
  return self;
}

