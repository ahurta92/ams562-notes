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
include testing/CMakeFiles/Solutions.dir/depend.make
# Include the progress variables for this target.
include testing/CMakeFiles/Solutions.dir/progress.make

# Include the compile flags for this target's objects.
include testing/CMakeFiles/Solutions.dir/flags.make

testing/CMakeFiles/Solutions.dir/main.cpp.o: testing/CMakeFiles/Solutions.dir/flags.make
testing/CMakeFiles/Solutions.dir/main.cpp.o: ../testing/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object testing/CMakeFiles/Solutions.dir/main.cpp.o"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Solutions.dir/main.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/main.cpp

testing/CMakeFiles/Solutions.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Solutions.dir/main.cpp.i"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/main.cpp > CMakeFiles/Solutions.dir/main.cpp.i

testing/CMakeFiles/Solutions.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Solutions.dir/main.cpp.s"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/main.cpp -o CMakeFiles/Solutions.dir/main.cpp.s

testing/CMakeFiles/Solutions.dir/tests.cpp.o: testing/CMakeFiles/Solutions.dir/flags.make
testing/CMakeFiles/Solutions.dir/tests.cpp.o: ../testing/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object testing/CMakeFiles/Solutions.dir/tests.cpp.o"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Solutions.dir/tests.cpp.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/tests.cpp

testing/CMakeFiles/Solutions.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Solutions.dir/tests.cpp.i"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/tests.cpp > CMakeFiles/Solutions.dir/tests.cpp.i

testing/CMakeFiles/Solutions.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Solutions.dir/tests.cpp.s"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/tests.cpp -o CMakeFiles/Solutions.dir/tests.cpp.s

testing/CMakeFiles/Solutions.dir/solutions.cc.o: testing/CMakeFiles/Solutions.dir/flags.make
testing/CMakeFiles/Solutions.dir/solutions.cc.o: ../testing/solutions.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object testing/CMakeFiles/Solutions.dir/solutions.cc.o"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Solutions.dir/solutions.cc.o -c /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/solutions.cc

testing/CMakeFiles/Solutions.dir/solutions.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Solutions.dir/solutions.cc.i"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/solutions.cc > CMakeFiles/Solutions.dir/solutions.cc.i

testing/CMakeFiles/Solutions.dir/solutions.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Solutions.dir/solutions.cc.s"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing/solutions.cc -o CMakeFiles/Solutions.dir/solutions.cc.s

# Object files for target Solutions
Solutions_OBJECTS = \
"CMakeFiles/Solutions.dir/main.cpp.o" \
"CMakeFiles/Solutions.dir/tests.cpp.o" \
"CMakeFiles/Solutions.dir/solutions.cc.o"

# External object files for target Solutions
Solutions_EXTERNAL_OBJECTS =

testing/Solutions: testing/CMakeFiles/Solutions.dir/main.cpp.o
testing/Solutions: testing/CMakeFiles/Solutions.dir/tests.cpp.o
testing/Solutions: testing/CMakeFiles/Solutions.dir/solutions.cc.o
testing/Solutions: testing/CMakeFiles/Solutions.dir/build.make
testing/Solutions: testing/CMakeFiles/Solutions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Solutions"
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Solutions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
testing/CMakeFiles/Solutions.dir/build: testing/Solutions
.PHONY : testing/CMakeFiles/Solutions.dir/build

testing/CMakeFiles/Solutions.dir/clean:
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing && $(CMAKE_COMMAND) -P CMakeFiles/Solutions.dir/cmake_clean.cmake
.PHONY : testing/CMakeFiles/Solutions.dir/clean

testing/CMakeFiles/Solutions.dir/depend:
	cd /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/projects/ams562/ams562-notes/lectures/containers/code /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/testing /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing /home/adrian/projects/ams562/ams562-notes/lectures/containers/code/cmake-build-debug/testing/CMakeFiles/Solutions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testing/CMakeFiles/Solutions.dir/depend

