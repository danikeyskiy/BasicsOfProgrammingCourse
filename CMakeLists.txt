cmake_minimum_required(VERSION 3.23)
project(git_project C)

set(CMAKE_C_STANDARD 23)

add_executable(git_project main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)
add_executable(git_prjct libs/data_structures/vector/vector.c)