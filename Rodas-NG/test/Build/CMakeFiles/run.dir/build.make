# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /homes/doua/tdumont/odes/trunk/Rodas-NG/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/main.cc.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/main.cc.o: ../main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/main.cc.o"
	g++-4.9   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/main.cc.o -c /homes/doua/tdumont/odes/trunk/Rodas-NG/test/main.cc

CMakeFiles/run.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/main.cc.i"
	g++-4.9  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/doua/tdumont/odes/trunk/Rodas-NG/test/main.cc > CMakeFiles/run.dir/main.cc.i

CMakeFiles/run.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/main.cc.s"
	g++-4.9  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/doua/tdumont/odes/trunk/Rodas-NG/test/main.cc -o CMakeFiles/run.dir/main.cc.s

CMakeFiles/run.dir/main.cc.o.requires:
.PHONY : CMakeFiles/run.dir/main.cc.o.requires

CMakeFiles/run.dir/main.cc.o.provides: CMakeFiles/run.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/run.dir/main.cc.o.provides

CMakeFiles/run.dir/main.cc.o.provides.build: CMakeFiles/run.dir/main.cc.o

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/main.cc.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/main.cc.o
run: CMakeFiles/run.dir/build.make
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run
.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/main.cc.o.requires
.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/doua/tdumont/odes/trunk/Rodas-NG/test /homes/doua/tdumont/odes/trunk/Rodas-NG/test /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build /homes/doua/tdumont/odes/trunk/Rodas-NG/test/Build/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend

