#include "../src/memory/dyn_alloc_.h"
#include <stdio.h>
#include <stdlib.h>

// Cleanup function for memory
void* cleanup_free(void* ptr, ...) {
    free(ptr);
    printf("Memory freed!\n");
    return NULL;
}

// Cleanup function for FILE*
void* cleanup_fclose(void* fptr, ...) {
    if (fptr) {
        fclose((FILE*)fptr);
        printf("File closed!\n");
    }
    return NULL;
}

void do_work_with_defer() {
    __SCOPE_STACK__ stack;
    __scope_stack_init__(&stack);

    // Allocate memory and register cleanup
    void* mem = malloc(128);
    if (!mem) {
        printf("Memory allocation failed\n");
        goto cleanup;
    }
    __scope_stack_push__(&stack, cleanup_free, mem);

    // Open a file and register cleanup
    FILE* f = fopen("test.txt", "w");
    if (!f) {
        printf("File open failed\n");
        goto cleanup;
    }
    __scope_stack_push__(&stack, cleanup_fclose, f);

    // ... do stuff with mem and f ...

    fprintf(f, "Hello, world!\n");

cleanup:
    // Clean up all resources in reverse order
    __scope_stack_destroy__(&stack);
}

int main() {
    do_work_with_defer();
    return 0;
}