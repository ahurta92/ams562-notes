cmake_minimum_required(VERSION 3.20)
project(Lecture_Examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tests main.cpp tests.cpp problems.cc)
add_executable(Solutions main.cpp tests.cpp solutions.cc)
add_executable(vector vector_main.cpp vector_main.cpp)
