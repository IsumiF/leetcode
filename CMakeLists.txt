cmake_minimum_required(VERSION 3.12)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

# Pull in external targets:
#   - Catch2::Catch2
add_subdirectory(extern)

# old code
add_executable(771 src/771.cpp)
add_executable(929 src/929.cpp)

enable_testing()

add_compile_definitions(LEETCODE_LOCAL)
add_subdirectory(src/lib)
add_subdirectory(src/test)
