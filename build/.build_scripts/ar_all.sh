#!/bin/bash

ar rcs lib/libcextras.a \
  build/algorithm/hash.o \
  build/algorithm/linked_list.o \
  build/algorithm/allocator.o \
  build/algorithm/container.o \
  build/memory/dyn_alloc.o \
  build/oop/class.o \
  build/oop/iters.o \
  build/oop/exception.o \
  build/oop/functional.o \
  build/threads/task.o \
  build/threads/async.o \
  build/built-ins/int.o

