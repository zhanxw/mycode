# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build

# Include any dependencies generated for this target.
include CMakeFiles/testjit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testjit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testjit.dir/flags.make

CMakeFiles/testjit.dir/Test/testjit.cpp.o: CMakeFiles/testjit.dir/flags.make
CMakeFiles/testjit.dir/Test/testjit.cpp.o: ../Test/testjit.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testjit.dir/Test/testjit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testjit.dir/Test/testjit.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testjit.cpp

CMakeFiles/testjit.dir/Test/testjit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testjit.dir/Test/testjit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testjit.cpp > CMakeFiles/testjit.dir/Test/testjit.cpp.i

CMakeFiles/testjit.dir/Test/testjit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testjit.dir/Test/testjit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testjit.cpp -o CMakeFiles/testjit.dir/Test/testjit.cpp.s

CMakeFiles/testjit.dir/Test/testjit.cpp.o.requires:
.PHONY : CMakeFiles/testjit.dir/Test/testjit.cpp.o.requires

CMakeFiles/testjit.dir/Test/testjit.cpp.o.provides: CMakeFiles/testjit.dir/Test/testjit.cpp.o.requires
	$(MAKE) -f CMakeFiles/testjit.dir/build.make CMakeFiles/testjit.dir/Test/testjit.cpp.o.provides.build
.PHONY : CMakeFiles/testjit.dir/Test/testjit.cpp.o.provides

CMakeFiles/testjit.dir/Test/testjit.cpp.o.provides.build: CMakeFiles/testjit.dir/Test/testjit.cpp.o
.PHONY : CMakeFiles/testjit.dir/Test/testjit.cpp.o.provides.build

# Object files for target testjit
testjit_OBJECTS = \
"CMakeFiles/testjit.dir/Test/testjit.cpp.o"

# External object files for target testjit
testjit_EXTERNAL_OBJECTS =

testjit: CMakeFiles/testjit.dir/Test/testjit.cpp.o
testjit: libAsmJit.so
testjit: CMakeFiles/testjit.dir/build.make
testjit: CMakeFiles/testjit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testjit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testjit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testjit.dir/build: testjit
.PHONY : CMakeFiles/testjit.dir/build

CMakeFiles/testjit.dir/requires: CMakeFiles/testjit.dir/Test/testjit.cpp.o.requires
.PHONY : CMakeFiles/testjit.dir/requires

CMakeFiles/testjit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testjit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testjit.dir/clean

CMakeFiles/testjit.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testjit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testjit.dir/depend
