#include "matrix.h"


CLASS_END(binary_matrix_t, 10,
  __ON_INIT__(binary_matrix_t,
  );
) {
  return self;
}

void* binary_matrix_add_self(binary_matrix_t* self, binary_matrix_t* other) {
  for (size_t i = 0; i < self->shape_x * self->shape_y; ++i) {
    ((size_t*)self->container.data.data)[i] ^= \
        ((size_t*)other->container.data.data)[i];
  }
  return self;
}

void* binary_matrix_add(binary_matrix_t* self, binary_matrix_t* other, binary_matrix_t* dest) {
  for (size_t i = 0; i < self->shape_x * self->shape_y; ++i) {
    ((size_t*)dest->container.data.data)[i] = \
        ((size_t*)self->container.data.data)[i] ^ \
        ((size_t*)other->container.data.data)[i];
  }
  return self;
}

void* binary_matrix_mul_self(binary_matrix_t* self, binary_matrix_t* other) {
  for (size_t i = 0; i < self->shape_x; ++i) {
    vector_t row;
    for (size_t j = 0; j < self->shape_y; ++j) {
      for (size_t k = 0; k < other->shape_y; ++k) {
        ((size_t*)row.data.data)[j] ^= \
            ((size_t*)self->container.data.data)[i * self->shape_y + k] & \
            ((size_t*)other->container.data.data)[k * other->shape_y + j];
      }
    }
    for (size_t j = 0; j < self->shape_y; ++j) {
      ((size_t*)self->container.data.data)[i * self->shape_y + j] = \
          ((size_t*)row.data.data)[j];
    }
  }
  return self;
}

void* binary_matrix_inverse(binary_matrix_t* self, binary_matrix_t* dest) {
  binary_matrix_t mat_copy = *COPY(binary_matrix_t, self);
  for (size_t i = 0; i < dest->shape_x; i++)
  {
    for (size_t j = 0; j < dest->shape_y; j++)
    {
      ((size_t*)dest->container.data.data)[i * dest->shape_y + j] = (i == j);
    }
  }
  
  for (size_t i = 0; i < self->shape_x; ++i) {
    if (((size_t*)self->container.data.data)[i * self->shape_y] == 1) {
      size_t tmp_val = ((size_t*)dest->container.data.data)[i * dest->shape_y + i];
      ((size_t*)dest->container.data.data)[i * dest->shape_y + i];
    }
  }
}

