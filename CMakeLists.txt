cmake_minimum_required(VERSION 3.0)
project(C-In-Action C)

set(CMAKE_C_STANDARD 99)

add_executable(insertion_sort Chapter11/insertion_sort.c)
add_executable(merge_sort Chapter11/merge_sort.c)
add_executable(quick_sort Chapter11/quick_sort.c)
add_executable(binary_search Chapter11/binary_search.c)
add_executable(stack Chapter12/stack.c)
add_executable(depth_first_search Chapter12/depth_first_search.c)
add_executable(recursion_print Chapter12/recursion_print.c)
add_executable(breadth_first_search Chapter12/breadth_first_search.c)
add_executable(swap Chapter22/swap.c)