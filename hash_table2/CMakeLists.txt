cmake_minimum_required(VERSION 3.25)
project(hash_table2 C)

set(CMAKE_C_STANDARD 11)

add_executable(hash_table2 main.c hash.h hash.c)
