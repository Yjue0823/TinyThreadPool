# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xdu/workplace/TinyThreadPool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xdu/workplace/TinyThreadPool/build

# Include any dependencies generated for this target.
include CMakeFiles/TinyThreadPool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TinyThreadPool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TinyThreadPool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TinyThreadPool.dir/flags.make

CMakeFiles/TinyThreadPool.dir/maintest.cpp.o: CMakeFiles/TinyThreadPool.dir/flags.make
CMakeFiles/TinyThreadPool.dir/maintest.cpp.o: ../maintest.cpp
CMakeFiles/TinyThreadPool.dir/maintest.cpp.o: CMakeFiles/TinyThreadPool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xdu/workplace/TinyThreadPool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TinyThreadPool.dir/maintest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TinyThreadPool.dir/maintest.cpp.o -MF CMakeFiles/TinyThreadPool.dir/maintest.cpp.o.d -o CMakeFiles/TinyThreadPool.dir/maintest.cpp.o -c /home/xdu/workplace/TinyThreadPool/maintest.cpp

CMakeFiles/TinyThreadPool.dir/maintest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyThreadPool.dir/maintest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xdu/workplace/TinyThreadPool/maintest.cpp > CMakeFiles/TinyThreadPool.dir/maintest.cpp.i

CMakeFiles/TinyThreadPool.dir/maintest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyThreadPool.dir/maintest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xdu/workplace/TinyThreadPool/maintest.cpp -o CMakeFiles/TinyThreadPool.dir/maintest.cpp.s

# Object files for target TinyThreadPool
TinyThreadPool_OBJECTS = \
"CMakeFiles/TinyThreadPool.dir/maintest.cpp.o"

# External object files for target TinyThreadPool
TinyThreadPool_EXTERNAL_OBJECTS =

bin/TinyThreadPool: CMakeFiles/TinyThreadPool.dir/maintest.cpp.o
bin/TinyThreadPool: CMakeFiles/TinyThreadPool.dir/build.make
bin/TinyThreadPool: CMakeFiles/TinyThreadPool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xdu/workplace/TinyThreadPool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/TinyThreadPool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TinyThreadPool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TinyThreadPool.dir/build: bin/TinyThreadPool
.PHONY : CMakeFiles/TinyThreadPool.dir/build

CMakeFiles/TinyThreadPool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TinyThreadPool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TinyThreadPool.dir/clean

CMakeFiles/TinyThreadPool.dir/depend:
	cd /home/xdu/workplace/TinyThreadPool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xdu/workplace/TinyThreadPool /home/xdu/workplace/TinyThreadPool /home/xdu/workplace/TinyThreadPool/build /home/xdu/workplace/TinyThreadPool/build /home/xdu/workplace/TinyThreadPool/build/CMakeFiles/TinyThreadPool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TinyThreadPool.dir/depend

