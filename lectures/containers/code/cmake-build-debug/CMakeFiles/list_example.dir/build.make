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
include CMakeFiles/list_example.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/list_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list_example.dir/flags.make

CMakeFiles/list_example.dir/list_example.cpp.o: CMakeFiles/list_example.dir/flags.make
CMakeFiles/list_example.dir/list_example.cpp.o: ../list_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/list_example.dir/list_example.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list_example.dir/list_example.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/list_example.cpp

CMakeFiles/list_example.dir/list_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list_example.dir/list_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/list_example.cpp > CMakeFiles/list_example.dir/list_example.cpp.i

CMakeFiles/list_example.dir/list_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list_example.dir/list_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/list_example.cpp -o CMakeFiles/list_example.dir/list_example.cpp.s

# Object files for target list_example
list_example_OBJECTS = \
"CMakeFiles/list_example.dir/list_example.cpp.o"

# External object files for target list_example
list_example_EXTERNAL_OBJECTS =

list_example: CMakeFiles/list_example.dir/list_example.cpp.o
list_example: CMakeFiles/list_example.dir/build.make
list_example: CMakeFiles/list_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable list_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list_example.dir/build: list_example
.PHONY : CMakeFiles/list_example.dir/build

CMakeFiles/list_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/list_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/list_example.dir/clean

CMakeFiles/list_example.dir/depend:
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/projects/ams562/ams562-notes/lectures/containers/code /home/adrian/projects/ams562/ams562-notes/lectures/containers/code /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles/list_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list_example.dir/depend

