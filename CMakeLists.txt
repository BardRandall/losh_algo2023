cmake_minimum_required(VERSION 3.25)
project(losh_algo2023)

set(CMAKE_CXX_STANDARD 20)

add_executable(dfs day2/dfs.cpp)
add_executable(top_sort day2/top_sort.cpp)
add_executable(euler day2/euler.cpp)
add_executable(kosaraju day2/kosaraju.cpp)

add_executable(prefix_function day3/prefix_function.cpp)
add_executable(z_function day3/z_function.cpp)
add_executable(manaker day3/manaker.cpp)