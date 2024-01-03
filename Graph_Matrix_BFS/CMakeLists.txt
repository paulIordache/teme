cmake_minimum_required(VERSION 3.25)
project(Graph_Matrix_BFS C)

set(CMAKE_C_STANDARD 11)

add_executable(Graph_Matrix_BFS main.c graph.h graph.c queue.c)
