cmake_minimum_required(VERSION 3.24)
project(Algorithms_in_Cpp)

set(CMAKE_C_STANDARD 20)

include_directories(.)

add_executable(Algorithms_in_Cpp
        driver.cpp UnionFind.h)
