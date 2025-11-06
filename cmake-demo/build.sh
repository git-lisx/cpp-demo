#!/bin/bash
rm -rf ./build
cmake -S . -B build
cmake --build build

# 上面的命令相当于
# mkdir -p build
# cd build
# cmake ..
# cmake --build .
