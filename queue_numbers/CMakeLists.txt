cmake_minimum_required(VERSION 3.25)
project(queue_numbers C)

set(CMAKE_C_STANDARD 11)

add_executable(queue_numbers main.c operations.c header.h)


include_directories("/Paul/Downloads/Teme cv gen/stack_imp")
link_directories(/Paul/Downloads/Teme cv gen/stack_imp)
target_link_libraries(queue_numbers st4ck.h)
