# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrian/projects/ams562/ams562-notes/lectures/containers/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vector_print.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/vector_print.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector_print.dir/flags.make

CMakeFiles/vector_print.dir/vector_print.cpp.o: CMakeFiles/vector_print.dir/flags.make
CMakeFiles/vector_print.dir/vector_print.cpp.o: ../vector_print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector_print.dir/vector_print.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_print.dir/vector_print.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/vector_print.cpp

CMakeFiles/vector_print.dir/vector_print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_print.dir/vector_print.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/vector_print.cpp > CMakeFiles/vector_print.dir/vector_print.cpp.i

CMakeFiles/vector_print.dir/vector_print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_print.dir/vector_print.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/vector_print.cpp -o CMakeFiles/vector_print.dir/vector_print.cpp.s

CMakeFiles/vector_print.dir/print_complex.cc.o: CMakeFiles/vector_print.dir/flags.make
CMakeFiles/vector_print.dir/print_complex.cc.o: ../print_complex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vector_print.dir/print_complex.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_print.dir/print_complex.cc.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/print_complex.cc

CMakeFiles/vector_print.dir/print_complex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_print.dir/print_complex.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/print_complex.cc > CMakeFiles/vector_print.dir/print_complex.cc.i

CMakeFiles/vector_print.dir/print_complex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_print.dir/print_complex.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/print_complex.cc -o CMakeFiles/vector_print.dir/print_complex.cc.s

CMakeFiles/vector_print.dir/Complex.cpp.o: CMakeFiles/vector_print.dir/flags.make
CMakeFiles/vector_print.dir/Complex.cpp.o: ../Complex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/vector_print.dir/Complex.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_print.dir/Complex.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/Complex.cpp

CMakeFiles/vector_print.dir/Complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_print.dir/Complex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/Complex.cpp > CMakeFiles/vector_print.dir/Complex.cpp.i

CMakeFiles/vector_print.dir/Complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_print.dir/Complex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/Complex.cpp -o CMakeFiles/vector_print.dir/Complex.cpp.s

CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o: CMakeFiles/vector_print.dir/flags.make
CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o: ../VectorTpush_back.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/VectorTpush_back.cpp

CMakeFiles/vector_print.dir/VectorTpush_back.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_print.dir/VectorTpush_back.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/VectorTpush_back.cpp > CMakeFiles/vector_print.dir/VectorTpush_back.cpp.i

CMakeFiles/vector_print.dir/VectorTpush_back.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_print.dir/VectorTpush_back.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/VectorTpush_back.cpp -o CMakeFiles/vector_print.dir/VectorTpush_back.cpp.s

# Object files for target vector_print
vector_print_OBJECTS = \
"CMakeFiles/vector_print.dir/vector_print.cpp.o" \
"CMakeFiles/vector_print.dir/print_complex.cc.o" \
"CMakeFiles/vector_print.dir/Complex.cpp.o" \
"CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o"

# External object files for target vector_print
vector_print_EXTERNAL_OBJECTS =

vector_print: CMakeFiles/vector_print.dir/vector_print.cpp.o
vector_print: CMakeFiles/vector_print.dir/print_complex.cc.o
vector_print: CMakeFiles/vector_print.dir/Complex.cpp.o
vector_print: CMakeFiles/vector_print.dir/VectorTpush_back.cpp.o
vector_print: CMakeFiles/vector_print.dir/build.make
vector_print: CMakeFiles/vector_print.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable vector_print"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_print.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector_print.dir/build: vector_print
.PHONY : CMakeFiles/vector_print.dir/build

CMakeFiles/vector_print.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector_print.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector_print.dir/clean

CMakeFiles/vector_print.dir/depend:
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/projects/ams562/ams562-notes/lectures/containers/code /home/adrian/projects/ams562/ams562-notes/lectures/containers/code /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles/vector_print.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector_print.dir/depend

