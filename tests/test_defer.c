#include "dyn_alloc_.h"
#include <stdio.h>
#include <stdlib.h>

void cleanup(void *ptr) {
    printf("Cleaning up: %p\n", ptr);
    free(ptr);
}

void* doNothing(void* x, ...) {
  printf("X = %d\n", x);
  return 0;
}

int main() {
    SCOPE_BEGIN;

    int *array = (int *)malloc(5 * sizeof(int));
    if (!array) {
        perror("malloc failed");
        SCOPE_END;
        return 1;
    }
    
    SCOPE_PUSH(cleanup, array);

    for (int i = 0; i < 5; ++i) {
        array[i] = i * 10;
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("Doing more work...\n");

    SCOPE_END;
    return 0;
}