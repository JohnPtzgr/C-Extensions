#include "./crandom.h"
#include "stdio.h"
#include "time.h"
#include <string.h>


fastRNG* fastRNG_new(int seed) {
  fastRNG* rng = calloc(1, sizeof(fastRNG));
  rng->cur_max = 0.0;
  rng->cur_min = 1.0;
  if (seed) {
    srand(seed);
  } else {
    srand(41);
  }
  for (size_t i = 0; i < CRAND_K; ++i) {
    rng->state[i] = ((double)rand()) / RAND_MAX;
    if (rng->state[i] > rng->cur_max) {
      rng->cur_max = rng->state[i];
    }
    if (rng->state[i] < rng->cur_min) {
      rng->cur_min = rng->state[i];
    }
  }
  for (size_t i = 0; i < CRAND_K / 2; ++i) {
    fastRNG_next(rng);
  }
  return rng;
}

void fastRNG_destroy(fastRNG* self) {
  for (size_t i = 0; i < CRAND_K; ++i) {
    self->state[i] = 0.0;
  }
  *self = (fastRNG){};
  free(self);
}

// int main() {
//   double mid = 0;
//   for (size_t k = 0; k < 100; ++k) {
//     long double middle = 0;
//     size_t N = 1000;
//     fastRNG* rng = fastRNG_new(k);
//     clock_t time_s;
//     clock_t time_f;
//     size_t ops = 100000llu;
//     time_s = clock();
//     size_t cnt = 0;
//     for (size_t j = 0; j < 1; ++j) {
//       // srand(121 + j);
//       for (size_t i = 0; i < ops / 1; ++i) {
//         middle += fastRNG_uniform_next(rng);
//         // if (fastRNG_uniform_next(rng) >= 0.5) {
//         //   cnt += 1;
//         // }
//         fastRNG_uniform_next(rng);
//       }
//     }
//     time_f = clock();
//     mid = mid * (k + 1) / (k + 2) + (1.0 / (k + 2)) * ((double)(middle / ((double)ops)));
//     if ((time_f - time_s) * 1000 / CLOCKS_PER_SEC < 1400 && fabs(((double)(middle / ((double)ops))) - 0.5) < 0.01) {
//       printf("I(%d): Time diff - %d ms\n AVG: %f \\ %f\n", k, (time_f - time_s) * 1000 / CLOCKS_PER_SEC, ((double)(middle / ((double)ops))), mid);
//       // printf("Time diff - %d ms\n AVG: %f\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC, ((double)(cnt / ((double)ops))));
//     }
//     fastRNG_destroy(rng);
//   }
// }



// Comparison function for qsort
int cmp_double(const void* a, const void* b) {
  double da = *(const double*)a;
  double db = *(const double*)b;
  return (da > db) - (da < db);
}

// Print ASCII histogram
void print_histogram(const double* data, size_t n, int num_buckets, int width) {
  double* sorted = malloc(n * sizeof(double));
  if (!sorted) return;
  memcpy(sorted, data, n * sizeof(double));
  qsort(sorted, n, sizeof(double), cmp_double);
  
  int* counts = calloc(num_buckets, sizeof(int));
  double bucket_size = 1.0 / num_buckets;
  
  // Fill histogram using sorted array (O(n))
  size_t idx = 0;
  for (int b = 0; b < num_buckets; ++b) {
    double endpoint = (b + 1) * bucket_size;
    while (idx < n && sorted[idx] < endpoint) {
      counts[b]++;
      idx++;
    }
  }
  
  // Find maximum count for scaling
  int max_count = 0;
  for (int b = 0; b < num_buckets; ++b)
    if (counts[b] > max_count) max_count = counts[b];
  
  // Print histogram
  printf("\nHistogram (%d buckets, %d = %d values):\n", 
          num_buckets, max_count, (int)n);
  printf("    ");
  for (int w = 0; w < width; ++w) printf("-");
  printf("\n");
  
  for (int b = 0; b < num_buckets; ++b) {
    double start = b * bucket_size;
    double end = (b + 1) * bucket_size;
    printf("%5.2f-%.2f | ", start, end);
    
    int bar_len = (int)((double)counts[b] / max_count * width);
    for (int i = 0; i < bar_len; ++i) printf("#");
    printf(" %d\n", counts[b]);
  }
  printf("    ");
  for (int w = 0; w < width; ++w) printf("-");
  printf("\n");
  
  free(sorted);
  free(counts);
}

int main(int argc, char* argv[]) {
  size_t N = (argc > 1) ? atoll(argv[1]) : 1000000;
  int buckets = (argc > 2) ? atoi(argv[2]) : 50;
  int width = (argc > 3) ? atoi(argv[3]) : 60;
  int seed = (argc > 4) ? atoi(argv[4]) : 41;

  double* data = malloc(N * sizeof(double));
  if (!data) return 1;
  
  for (size_t j = seed; j < 100; ++j) {
 
    printf("Generating %zu random numbers, seed=%d, buckets=%d\n", N, j, buckets);
    
    fastRNG* rng = fastRNG_new(j);
    
    clock_t start = clock();
    for (size_t i = 0; i < N; ++i) {
      data[i] = fastRNG_uniform_next(rng);
      // data[i] = ((double)rand()) / RAND_MAX;
    }
    clock_t end = clock();
    
    fastRNG_destroy(rng);
    
    double time_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time: %.2f ms, %.2f ns/op\n", time_ms, time_ms * 1e6 / N);
    
    // Sort and print histogram
    print_histogram(data, N, buckets, width);
    
    // Basic statistics
    double sum = 0.0;
    for (size_t i = 0; i < N; ++i) sum += data[i];
    printf("\nMean: %.6f (expected 0.5)\n", sum / N);
  }

  free(data);
  return 0;
}
