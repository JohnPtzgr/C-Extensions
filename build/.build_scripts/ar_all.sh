#!/bin/bash

ar rcs lib/libcextras.a \
  build/algorithm/hash.o \
  build/algorithm/linked_list.o \
  build/algorithm/rb_tree.o \
  build/memory/dyn_alloc.o \
  build/oop/class.o \
  build/oop/types.o \
  build/oop/exception.o \
  build/threads/task.o \
  build/threads/async.o


  # build/algorithm/matrix.o \
  # build/algorithm/container.o \
  # build/algorithm/vector.o \