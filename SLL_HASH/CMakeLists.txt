cmake_minimum_required(VERSION 3.24)
project(SLL_HASH C)

set(CMAKE_C_STANDARD 11)

add_executable(SLL_HASH main.c operation.c op.h)
