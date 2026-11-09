#include "math.h"
#include "stdlib.h"

#pragma once

#define CRAND_ALPHA 0.999

#define CRAND_BETA 1.4142135623730951

#define CRAND_K 64 

typedef struct fastRNG {
  int write_idx;
  int mxmn_idx;
  double phase;
  double cur_min;
  double cur_max;
  double state[CRAND_K];
} fastRNG;

fastRNG* fastRNG_new(int seed);
void fastRNG_destroy(fastRNG* self);

static inline double fastRNG_next(fastRNG* self) {
  double old_val = self->state[self->write_idx];
  double R = exp(-((double)(CRAND_K - 1)) * self->cur_min / self->cur_max);
  
  double X = (old_val > 0.5) ? (1.0 - R) : R;

  if (X > self->cur_max) {
    self->cur_max = X;
  }

  if (X < self->cur_min) {
    self->cur_min = X;
  }
  
  self->state[self->write_idx] = X;
  self->write_idx = (self->write_idx + 7) & (CRAND_K - 1);

  double Y = CRAND_ALPHA * X + (CRAND_BETA - CRAND_ALPHA) * self->phase;
  Y -= (double)(int)Y;

  if (self->state[self->mxmn_idx] > self->cur_max) {
    self->cur_max = self->state[self->mxmn_idx];
  }

  if (self->state[self->mxmn_idx] < self->cur_min) {
    self->cur_min = self->state[self->mxmn_idx];
  }
  
  self->mxmn_idx = (self->mxmn_idx + 1) & (CRAND_K - 1);
  self->phase += 1.0 / CRAND_BETA;
  self->phase -= (double)(int)self->phase;
  return Y;
}

static inline double fastRNG_uniform_next(fastRNG* self) {
  double r = fastRNG_next(self);
  // while (r < 0.5244 || r > 0.8898) {
  //   r = fastRNG_next(self);
  // }
  // return (r - 0.5244) / (0.8898 - 0.5244);
  while (r < 0.3385 || r > 0.99) {
    r = fastRNG_next(self);
  }
  if (r < 0.6605) {
    return (r - 0.3385) / (0.6605 - 0.3385);
  }
  if (r < 0.7537) {
    return (r - 0.6605) / (0.7537 - 0.6605);
  }
  return (r - 0.7537) / (0.99035 - 0.7537);
}

static inline double fastRNG_next_N(fastRNG* self, int N) {
  return 0.0;
}

static inline double fastRNG_uniform_next_N(fastRNG* self, int N) {
  return 0.0;
}
