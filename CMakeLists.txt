cmake_minimum_required(VERSION 3.0)
project(C-In-Action C)

set(CMAKE_C_STANDARD 99)

add_executable(insertion_sort Chapter11/insertion_sort.c)
add_executable(merge_sort Chapter11/merge_sort.c)
add_executable(quick_sort Chapter11/quick_sort.c)