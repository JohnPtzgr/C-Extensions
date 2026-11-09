#include "DEPRECATED_vector.h"


#ifndef UCHAR_MAX
#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#endif // !UCHAR_MAX


// Initialize empty ARRAY for objects of TYPE_SIZE size
void array_init(darray_t* array, size_t type_size) {
    array->da_capacity = 16;
    array->da_size = 0;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
}


// Initialize ARRAY of SIZE objects of TYPE_SIZE size. Default object is set to *VALUE
void array_init_with(darray_t* array, size_t type_size, size_t size, const void* value) {
    array->da_capacity = 2 * size;
    array->da_size = size;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
    for (size_t i = 0; i < size; ++i) {
        memcpy(array->data + i * type_size, value, type_size);
    }
}

// Initialize ARRAY with SIZE objects of TYPE_SIZE size from SOURCE
void array_init_from(darray_t* array, size_t type_size, const void* source, size_t size) {
    array->da_capacity = 2 * size;
    array->da_size = size;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
    memcpy(array->data, source, type_size * size);
}

// Copy SIZE chunks(darray_t::type_size bytes) of data from SOURCE to ARRAY
void array_copy(darray_t* array, const void* source, size_t size) {
    if (1 + size >= array->da_capacity) {
        array->da_capacity = 2 * size;
        free(array->data);
        array->data = malloc(array->type_size * array->da_capacity);
    }
    memcpy(array->data, source, array->type_size * size);
    array->da_size = size;
}

// Destroy ARRAY
void array_destroy(darray_t* array) {
    array->da_capacity = 0;
    array->da_size = 0;
    free(array->data);
    array->type_size = 0;
}

// Destroy ARRAY with applying DESTROY function to each instance
void array_destroy_with(darray_t* array, generic_function_t destroy) {
    for (size_t i = 0; i < array->da_size; ++i) {
        destroy(array->data + i * array->type_size);
    }
    array->da_capacity = 0;
    array->da_size = 0;
    free(array->data);
    array->type_size = 0;
}

// Get pointer to data in ARRAY
void* array_get(darray_t* array) {
    return array->data;
}

// Push *VALUE to the back of the ARRAY
void array_push(darray_t* array, const void* value) {
    if (array->da_size + 1 >= array->da_capacity) {
        void* buffer = malloc(array->type_size * array->da_capacity * 2);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
        array->da_capacity *= 2;
    }
    memcpy(array->data + array->da_size * array->type_size,
           value,
           array->type_size);
    array->da_size++;
}

// Pop value from the back of the ARRAY
void array_pop(darray_t* array) {
    if (array->da_size == 0) {
        return;
    }
    if (array->da_size + 1 >= array->da_capacity / 4 && array->da_size > 16) {
        void* buffer = malloc(array->type_size * array->da_capacity / 2);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
        array->da_capacity /= 2;
    }
    for (size_t i = 0; i < array->type_size; ++i) {
        *(unsigned char*)(array->data + array->da_size * array->type_size + i) = 0;
    }
    array->da_size--;
}

// Insert *VALUE at INDEX in ARRAY
void array_insert(darray_t* array, size_t index, const void* value) {
    size_t max_size = array->da_size + 1;
    if (index > array->da_size) {
        max_size = index + 1;
    }
    if (max_size >= array->da_capacity) {
        while (array->da_capacity <= max_size) {
            array->da_capacity *= 2;
        }
        void* buffer = malloc(array->type_size * array->da_capacity);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
    }
    if (index < array->da_size) {
        memmove(array->data + (index + 1) * array->type_size,
                array->data + index * array->type_size,
                (array->da_size - index) * array->type_size);
    }
    memcpy(array->data + index * array->type_size,
           value,
           array->type_size);
    array->da_size++;
}

void array_remove(darray_t* array, size_t index) {
    if (array->da_size <= index) {
        return;
    }
    if (array->da_size < index + 1) {
        memmove(array->data + index * array->type_size,
                array->data + (index + 1) * array->type_size,
                (array->da_size - index - 1) * array->type_size);
        array->da_size--;
    } else {
        array_pop(array);
    }
}

// Clears the array, without deallocating memory
void array_clear(darray_t* array) {
    array->da_size = 0;
}

// Find the first instance of *VALUE in the ARRAY
size_t array_find(const darray_t* array, const void* value) {
    for (size_t i = 0; i < array->da_size; ++i) {
        if (strncmp((const char*)array->data + i * array->type_size,
                    (const char*)value, array->type_size) == 0) {
            return i;
        }
    }
    return -1;
}

// Find the last instance of *VALUE in the ARRAY
size_t array_rfind(const darray_t* array, const void* value) {
    for (size_t i = array->da_size; i > 0; --i) {
        if (strncmp((const char*)array->data + (i - 1) * array->type_size,
                    (const char*)value, array->type_size) == 0) {
            return i - 1;
        }
    }
    return -1;
}

// Find all the instances of *VALUE in the ARRAY and put them into CONTAINER for size_t
size_t array_find_all(const darray_t* array, const void* value, darray_t* container) {
    array_clear(container);
    for (size_t i = 0; i < array->da_size; ++i) {
        if (memcmp(array->data + i * array->type_size, value, array->type_size) == 0) {
            array_push(container, &i);
        }
    }
    return container->da_size;
}

// Split ARRAY into chunks separated by *VALUE and put into CONTAINER
size_t array_split(darray_t* array, const void* value, darray_t* container) {
    array_clear(container);
    darray_t tmp_array[1];
    darray_t iter_array[1];
    array_init(tmp_array, sizeof(size_t));
    array_find_all(array, value, tmp_array);
    size_t initial_index = 0;
    size_t iter_index = 0;
    for (size_t i = 0; i < tmp_array->da_size; ++i) {
        iter_index = ((size_t*)tmp_array->data)[i] + 1;
        iter_array->da_capacity = 4 * (iter_index - initial_index) / 3;
        iter_array->data = malloc(iter_array->da_capacity * array->type_size);
        iter_array->da_size = iter_index - initial_index - 1;
        iter_array->type_size = array->type_size;
        memcpy(iter_array->data, 
               array->data + initial_index * array->type_size,
               iter_array->da_size * array->type_size);
        initial_index = iter_index;
        if (iter_array->da_size > 0) {
            array_push(container, &iter_array);
        }
    }
    if (initial_index < array->da_size) {
        iter_index = array->da_size;
        iter_array->da_capacity = 4 * (iter_index - initial_index) / 3;
        iter_array->data = malloc(iter_array->da_capacity * array->type_size);
        iter_array->da_size = iter_index - initial_index;
        iter_array->type_size = array->type_size;
        memcpy(iter_array->data, 
                array->data + initial_index * array->type_size,
                iter_array->da_size * array->type_size);
        if (iter_array->da_size > 0) {
            array_push(container, &iter_array);
        }
    }
    array_destroy(tmp_array);
    return container->da_size;
}
//


// Initialize ITERATOR with the ARRAY
void iterator_init(iterator_t* iterator, darray_t* array) {
    memcpy(iterator->container, array, sizeof(darray_t));
    iterator->index = 0;
    iterator->flags = 0;
}

// Destroy ITERATOR. Does NOT destroy the array itself
void iterator_destroy(iterator_t* iterator) {
    iterator->container->data = NULL;
    iterator->container->da_capacity = 0;
    iterator->container->da_size = 0;
    iterator->container->type_size = 0;
    iterator->index = 0;
    iterator->flags = 0;
}

// Go to next value in the ITERATOR.container, forwarding the address to its value
void* iterator_next(iterator_t* iterator) {
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_FORWARD_IMMEDIATE);
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE);
    iterator->index++;
    if (iterator->index == iterator->container->da_size) {
        iterator->index = 0;
        iterator->flags |= ITERATOR_OVERFLOW |
                           ITERATOR_OVERFLOW_FORWARD |
                           ITERATOR_OVERFLOW_FORWARD_IMMEDIATE;
    }
    return iterator->container->data + iterator->index * iterator->container->type_size;
}

// Go to previous value in the ITERATOR.container, forwarding the address to its value
void* iterator_prev(iterator_t* iterator) {
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_FORWARD_IMMEDIATE);
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE);
    if (iterator->index == 0) {
        iterator->index = iterator->container->da_size;
        iterator->flags |= ITERATOR_OVERFLOW |
                           ITERATOR_OVERFLOW_BACKWARD |
                           ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE;
    }
    iterator->index--;
    return iterator->container->data + iterator->index * iterator->container->type_size;
}

// Go to value in the ITERATOR.container at INDEX, forwarding the address to its value
void* iterator_at(iterator_t* iterator, size_t index) {
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_FORWARD_IMMEDIATE);
    iterator->flags &= (UCHAR_MAX ^ ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE);
    if (index >= iterator->container->da_size) {
        return NULL;
    }
    iterator->index = index;
    return iterator->container->data + iterator->index * iterator->container->type_size;
}

BOOL iterator_BOOL(iterator_t* iterator) {
    if (iterator->flags & (ITERATOR_OVERFLOW_FORWARD_IMMEDIATE |
        ITERATOR_OVERFLOW_BACKWARD_IMMEDIATE)) {
        return FALSE;
    }
    return TRUE;
}

void reset(iterator_t* iterator) {
    iterator->flags = 0;
    iterator->index = 0;
}
//


void string_init(string_t* string) {
    array_init(string->container, 1);
}

void string_init_from(string_t* string, const char* input_string, size_t string_size) {
    array_init_from(string->container, 1, input_string, string_size + 1);
    ((char*)string->container->data)[string_size] = '\0';
}

void string_destroy(string_t* string) {
    array_destroy(string->container);
}
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

// Initialize HEAP
void heap_init(heap_t* heap) {
    heap->pointers_allocated = 0;
    heap->pointers_freed = 0;
    heap->pointers_total = 0;
    heap->pointers_on_heap = (darray_t*)malloc(sizeof(darray_t));
    heap->pointers_on_stack = (darray_t*)malloc(sizeof(darray_t));
    array_init(heap->pointers_on_heap, sizeof(heap));
    array_init(heap->pointers_on_stack, sizeof(heap));
}

// Destroy HEAP and deallocate remaining non-free memory
void heap_destroy(heap_t* heap) {
    for (size_t i = 0; i < heap->pointers_total; ++i) {
        if (((void***)array_get(heap->pointers_on_stack))[i] != NULL) {
            free(((void**)array_get(heap->pointers_on_heap))[i]);
        }
    }
    array_destroy(heap->pointers_on_heap);
    array_destroy(heap->pointers_on_stack);
    heap->pointers_allocated = 0;
    heap->pointers_freed = 0;
    heap->pointers_total = 0;
}

// Allocate SIZE * TYPE_SIZE bytes of memory on HEAP and put it into ADDRESS
void heap_alloc(heap_t* heap, size_t size, size_t type_size, void* address) {
    heap->pointers_allocated++;
    heap->pointers_total++;
    *((void**)address) = malloc(type_size * size);
    array_push(heap->pointers_on_stack, &address);
    array_push(heap->pointers_on_heap, address);
}

// Allocate SIZE * TYPE_SIZE bytes of memory on HEAP, initialize it from INIT_VALUE, and put it into ADDRESS
void heap_alloc_init(heap_t* heap, size_t size, size_t type_size, void* address, void* init_value) {
    heap->pointers_allocated++;
    heap->pointers_total++;
    *((void**)address) = malloc(type_size * size);
    for (size_t i = 0; i < size * type_size; i += type_size) {
        memcpy(*((void**)address), &init_value, type_size);
    }
    array_push(heap->pointers_on_stack, &address);
    array_push(heap->pointers_on_heap, address);
}

// Deallocate memory from HEAP located at ADDRESS
void heap_dealloc(heap_t* heap, void* address) {
    for (size_t i = heap->pointers_total; i > 0; --i) {
        if (((void**)array_get(heap->pointers_on_heap))[i - 1] == address) {
            free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
            ((void***)array_get(heap->pointers_on_stack))[i - 1] = NULL;
            heap->pointers_allocated--;
            if (i == heap->pointers_total) {
                array_pop(heap->pointers_on_heap);
                array_pop(heap->pointers_on_stack);
                heap->pointers_total--;
            } else {
                heap->pointers_freed++;
            }
        }
    }
}

// Deallocate all the memory from HEAP, that went out of scope containing REFERENCE_ADDRESS
void collect_garbage(heap_t* heap, void* reference_address) {
    int tmp_object_on_stack_old = 0;
    int tmp_object_on_stack_new = tmp_object_on_stack_old + 1;
    int flag = 1;
    for (size_t i = heap->pointers_total; (i > 0) && (flag & 1); --i) {
        flag &= 3;
        if (&tmp_object_on_stack_new < &tmp_object_on_stack_old) {
            if (((void***)array_get(heap->pointers_on_stack))[i - 1] <= (void**)reference_address) {
                free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
                ((void**)array_get(heap->pointers_on_stack))[i - 1] = NULL;
                heap->pointers_allocated--;
                if (i == heap->pointers_total) {
                    array_pop(heap->pointers_on_heap);
                    array_pop(heap->pointers_on_stack);
                    heap->pointers_total--;
                } else {
                    heap->pointers_freed++;
                }
                flag |= 2;
                flag |= 4;
            }
        } else {
            if (((void***)array_get(heap->pointers_on_stack))[i - 1] >= (void**)reference_address) {
                free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
                ((void**)array_get(heap->pointers_on_stack))[i - 1] = NULL;
                heap->pointers_allocated--;
                if (i == heap->pointers_total) {
                    array_pop(heap->pointers_on_heap);
                    array_pop(heap->pointers_on_stack);
                    heap->pointers_total--;
                } else {
                    heap->pointers_freed++;
                }
                flag |= 2;
                flag |= 4;
            }
        }
        if (flag & 2) {
            flag &= 2 + ((flag & 4) > 0);
        }
    }
}
//


