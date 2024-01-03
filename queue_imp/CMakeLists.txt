cmake_minimum_required(VERSION 3.25)
project(queue_imp C)

set(CMAKE_C_STANDARD 11)

add_executable(queue_imp main.c queue.c queue.h)
