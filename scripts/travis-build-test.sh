#!/usr/bin/env bash

BUILD_DIR=cmake-build-release
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=gcc-6 \
    -DCMAKE_CXX_COMPILER=g++-6 \
    ..
make
make test
