
cmake_minimum_required(VERSION 3.10)

project(SortingBenchmark)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(SortingBenchmark src/main.cpp)
