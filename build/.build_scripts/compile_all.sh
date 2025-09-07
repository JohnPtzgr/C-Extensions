#!/bin/bash

# ./build/.build_scripts/compile_single.sh algorithm/container
./build/.build_scripts/compile_single.sh algorithm/hash
./build/.build_scripts/compile_single.sh algorithm/linked_list
./build/.build_scripts/compile_single.sh algorithm/allocator
./build/.build_scripts/compile_single.sh algorithm/container
# ./build/.build_scripts/compile_single.sh algorithm/matrix
# ./build/.build_scripts/compile_single.sh algorithm/vector
# ./build/.build_scripts/compile_single.sh algorithm/rb_tree

./build/.build_scripts/compile_single.sh memory/dyn_alloc

./build/.build_scripts/compile_single.sh oop/class
./build/.build_scripts/compile_single.sh oop/types
./build/.build_scripts/compile_single.sh oop/exception
./build/.build_scripts/compile_single.sh oop/iters
./build/.build_scripts/compile_single.sh oop/functional

./build/.build_scripts/compile_single.sh threads/async
./build/.build_scripts/compile_single.sh threads/task

./build/.build_scripts/compile_single.sh built-ins/int

# ./build/.build_scripts/compile_single.sh 

