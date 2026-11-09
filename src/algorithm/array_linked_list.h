#include <stdlib.h>
#include <stdio.h>

#pragma once

typedef struct ArrayLinkedList {
  void* data;
  size_t size;
  size_t capacity;
  size_t* maskA;
  size_t* maskB;
} ArrayLinkedList;



