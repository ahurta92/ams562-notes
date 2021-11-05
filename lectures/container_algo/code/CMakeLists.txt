cmake_minimum_required(VERSION 3.20)
project(Lecture)


# Create executables for example applications
#foreach (example ${EXAMPLE_SOURCES})
#    add_executable(${example} ${example}.cpp )
#endforeach ()
add_executable(vector_init vector_init.cpp )
add_executable(vector_push_back vector_push_back.cpp )
add_executable(vector_size_init vector_size_init.cpp )
add_executable(vector_print vector_print.cpp print_complex.cc Complex.cpp Vector.h VectorTpush_back.cpp)
add_executable(vector_print2 vector_print2.cpp print_complex.cc Complex.cpp)
add_executable(vector_range_checking vector_range_checking.cpp )
add_executable(vector_range_checking2 vector_range_checking2.cpp )

add_subdirectory(testing)