cmake_minimum_required(VERSION 3.24)
project(LL C)

set(CMAKE_C_STANDARD 11)

add_executable(LL main.c operations.c op.h operations.c)
