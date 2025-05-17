#!/bin/bash

./build/.build_scripts/compile_single.sh algorithm/container
./build/.build_scripts/compile_single.sh algorithm/hash
./build/.build_scripts/compile_single.sh algorithm/linked_list
./build/.build_scripts/compile_single.sh algorithm/matrix
./build/.build_scripts/compile_single.sh algorithm/vector

./build/.build_scripts/compile_single.sh memory/dyn_alloc

./build/.build_scripts/compile_single.sh oop/classes
./build/.build_scripts/compile_single.sh oop/types
./build/.build_scripts/compile_single.sh oop/functional
