cmake_minimum_required(VERSION 3.20)
project(Lecture)


# Create executables for example applications
#foreach (example ${EXAMPLE_SOURCES})
#    add_executable(${example} ${example}.cpp )
#endforeach ()
add_executable(sort_entry sort_entry.cpp entries.cpp)
add_executable(sort_entry1 sort_entry_val.cpp entries.cpp)
add_executable(sort_entry2 sort_entry2.cpp entries.cpp)
add_executable(find find.cpp entries.cpp)
add_executable(find2 find2.cpp entries.cpp)
add_executable(find3 find3.cpp entries.cpp)
add_executable(predicates predicates.cpp entries.cpp)

add_subdirectory(testing)