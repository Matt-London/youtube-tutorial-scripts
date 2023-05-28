cmake_minimum_required(VERSION 3.22)

project(sudoku_solver)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(H_FILES
    include/Sudoku.hpp)

set(SRC_FILES
    src/main.cpp
    src/Sudoku.cpp)

add_executable(sudoku_solver ${H_FILES} ${SRC_FILES})