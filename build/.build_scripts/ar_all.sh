#!/bin/bash

ar rcs lib/libcextras.a \
  build/algorithm/container.o \
  build/algorithm/hash.o \
  build/algorithm/linked_list.o \
  build/algorithm/matrix.o \
  build/algorithm/vector.o \
  build/memory/dyn_alloc.o \
  build/oop/classes.o \
  build/oop/types.o
