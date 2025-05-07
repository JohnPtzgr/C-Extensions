#ifndef VECTOR_H
#define VECTOR_H

#include "../oop/classes.h"
#include "string.h"
#define UCHAR_MAX (__SCHAR_MAX__*2 + 1)

STATIC_CLASS(generic_container_t,
  void* data;
  size_t size;,
  2)
void* gen_cont_free(generic_container_t* self);
void* gen_cont_alloc(generic_container_t* self, size_t size);

STATIC_INHERIT(vector_t, generic_container_t, size_t size; size_t type_size; , 10)

// Dynamic data structure (C vector)
typedef struct darray_t {
    void* data;
    size_t type_size;
    size_t da_size;
    size_t da_capacity;
} darray_t;

// Initialize empty ARRAY for objects of TYPE_SIZE size
void array_init(darray_t* array, size_t type_size);


// Initialize ARRAY of SIZE objects of TYPE_SIZE size. Default object is set to *VALUE
void array_init_with(darray_t* array, size_t type_size, size_t size, const void* value);

// Initialize ARRAY with SIZE objects of TYPE_SIZE size from SOURCE
void array_init_from(darray_t* array, size_t type_size, const void* source, size_t size);

// Copy SIZE chunks(darray_t::type_size bytes) of data from SOURCE to ARRAY
void array_copy(darray_t* array, const void* source, size_t size);

// Destroy ARRAY
void array_destroy(darray_t* array);

// Destroy ARRAY with applying DESTROY function to each instance
void array_destroy_with(darray_t* array, generic_function_t destroy);

// Get pointer to data in ARRAY
void* array_get(darray_t* array);

// Push *VALUE to the back of the ARRAY
void array_push(darray_t* array, const void* value);

// Pop value from the back of the ARRAY
void array_pop(darray_t* array);

// Insert *VALUE at INDEX in ARRAY
void array_insert(darray_t* array, size_t index, const void* value);

void array_remove(darray_t* array, size_t index);

// Clears the array, without deallocating memory
void array_clear(darray_t* array);

// Find the first instance of *VALUE in the ARRAY
size_t array_find(const darray_t* array, const void* value);

// Find the last instance of *VALUE in the ARRAY
size_t array_rfind(const darray_t* array, const void* value);

// Find all the instances of *VALUE in the ARRAY and put them into CONTAINER for size_t
size_t array_find_all(const darray_t* array, const void* value, darray_t* container);

// Split ARRAY into chunks separated by *VALUE and put into CONTAINER
size_t array_split(darray_t* array, const void* value, darray_t* container);
//


// Iterator for darray_t array
typedef struct iterator_t {
    darray_t container[1];
    size_t index;
    unsigned char flags;
} iterator_t;

#define ITERATOR_OVERFLOW_FORWARD 2
#define ITERATOR_OVERFLOW_BACKWARD 4
#define ITERATOR_OVERFLOW_FORWARD_IMMEDIATE 8
#define ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE 16
#define ITERATOR_OVERFLOW 1

// Initialize ITERATOR with the ARRAY
void iterator_init(iterator_t* iterator, darray_t* array);

// Destroy ITERATOR. Does NOT destroy the array itself
void iterator_destroy(iterator_t* iterator);

// Go to next value in the ITERATOR.container, forwarding the address to its value
void* iterator_next(iterator_t* iterator);

// Go to previous value in the ITERATOR.container, forwarding the address to its value
void* iterator_prev(iterator_t* iterator);

// Go to value in the ITERATOR.container at INDEX, forwarding the address to its value
void* iterator_at(iterator_t* iterator, size_t index);

BOOL iterator_BOOL(iterator_t* iterator);

void reset(iterator_t* iterator);
//


// Dynamic string data structure (C string)
typedef struct string_t {
    darray_t container[1];
} string_t;

void string_init(string_t* string);

void string_init_from(string_t* string, const char* input_string, size_t string_size);

void string_destroy(string_t* string);
//


// // Smart pointers

// #define off_scope_free_macro __attribute__((cleanup(off_scope_routine)))

// __attribute__ ((always_inline))
// inline void off_scope_routine(void *ptr) {
//     free(ptr);
// }

// typedef struct unique_ptr
// {
//     void* data;
//     size_t size;
//     size_t type_size;
// } unique_ptr;

// void unique_alloc(unique_ptr* ptr, size_t size, size_t type_size) {
//     off_scope_free_macro void* data = malloc(size * type_size);
//     ptr->data = data;
//     ptr->size = size;
//     ptr->type_size = type_size;
// }

// void unique_assign(unique_ptr* ptr_dst, unique_ptr* ptr_src) {
//     ptr_dst->data = ptr_src->data;
//     ptr_src->data = NULL;
//     ptr_dst->size = ptr_src->size;
//     ptr_src->size = 0;
//     ptr_dst->type_size = ptr_src->type_size;
//     ptr_src->type_size = 0;
// }

// void* unique_get(unique_ptr* ptr, size_t index) {
//     return ptr->data + index * ptr->type_size;
// }

// //


// Dynamic memory framework
typedef struct heap_t {
    darray_t* pointers_on_heap;
    darray_t* pointers_on_stack;
    size_t pointers_allocated;
    size_t pointers_freed;
    size_t pointers_total;
} heap_t;

// Initialize HEAP
void heap_init(heap_t* heap);

// Destroy HEAP and deallocate remaining non-free memory
void heap_destroy(heap_t* heap);

// Allocate SIZE * TYPE_SIZE bytes of memory on HEAP and put it into ADDRESS
void heap_alloc(heap_t* heap, size_t size, size_t type_size, void* address);

// Allocate SIZE * TYPE_SIZE bytes of memory on HEAP, initialize it from INIT_VALUE, and put it into ADDRESS
void heap_alloc_init(heap_t* heap, size_t size, size_t type_size, void* address, void* init_value);

// Deallocate memory from HEAP located at ADDRESS
void heap_dealloc(heap_t* heap, void* address);

// Deallocate all the memory from HEAP, that went out of scope containing REFERENCE_ADDRESS
void collect_garbage(heap_t* heap, void* reference_address);
//

#endif
