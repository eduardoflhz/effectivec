cmake_minimum_required(VERSION 3.17)
project(effectivec C)

set(CMAKE_C_STANDARD 11)

add_executable(effectivec main.c excercises/casting.c excercises/casting.h
    excercises/count.c excercises/count.h excercises/wrapflow.c
    excercises/wrapflow.h excercises/fclassification.c
    excercises/fclassification.h excercises/memory_management.c
    excercises/memory_management.h excercises/factorial.c excercises/factorial.h
    excercises/bubble.c excercises/bubble.h excercises/fibbonacci.c
    excercises/fibbonacci.h excercises/file.c excercises/file.h)
