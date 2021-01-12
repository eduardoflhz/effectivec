cmake_minimum_required(VERSION 3.17)
project(effectivec C)

set(CMAKE_C_STANDARD 11)

add_executable(effectivec main.c 
    excercises/count.c excercises/count.h excercises/wrapflow.c
    excercises/wrapflow.h excercises/fclassification.c
    excercises/fclassification.h excercises/memory_management.c
    excercises/memory_management.h algorithms/factorial.c algorithms/factorial.h
    algorithms/bubble.c algorithms/bubble.h algorithms/fibbonacci.c
    algorithms/fibbonacci.h excercises/file.c excercises/file.h
    algorithms/quicksort.c algorithms/quicksort.h algorithms/reverse_linked.c
    algorithms/reverse_linked.h)
