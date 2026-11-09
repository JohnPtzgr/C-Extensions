#!/bin/bash

./build/.build_scripts/clear.sh

./build/.build_scripts/prepare.sh
./build/.build_scripts/compile_all.sh
./build/.build_scripts/ar_all.sh
