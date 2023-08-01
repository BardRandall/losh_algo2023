cmake_minimum_required(VERSION 3.25)
project(losh_algo2023)

set(CMAKE_CXX_STANDARD 20)

add_executable(dfs dfs.cpp)
add_executable(top_sort top_sort.cpp)
add_executable(euler euler.cpp)
add_executable(kosaraju kosaraju.cpp)