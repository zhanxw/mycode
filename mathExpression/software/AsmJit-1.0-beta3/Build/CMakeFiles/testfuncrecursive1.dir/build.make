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
include CMakeFiles/testfuncrecursive1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testfuncrecursive1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testfuncrecursive1.dir/flags.make

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o: CMakeFiles/testfuncrecursive1.dir/flags.make
CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o: ../Test/testfuncrecursive1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncrecursive1.cpp

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncrecursive1.cpp > CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.i

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncrecursive1.cpp -o CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.s

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.requires:
.PHONY : CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.requires

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.provides: CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.requires
	$(MAKE) -f CMakeFiles/testfuncrecursive1.dir/build.make CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.provides.build
.PHONY : CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.provides

CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.provides.build: CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o
.PHONY : CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.provides.build

# Object files for target testfuncrecursive1
testfuncrecursive1_OBJECTS = \
"CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o"

# External object files for target testfuncrecursive1
testfuncrecursive1_EXTERNAL_OBJECTS =

testfuncrecursive1: CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o
testfuncrecursive1: libAsmJit.so
testfuncrecursive1: CMakeFiles/testfuncrecursive1.dir/build.make
testfuncrecursive1: CMakeFiles/testfuncrecursive1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testfuncrecursive1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testfuncrecursive1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testfuncrecursive1.dir/build: testfuncrecursive1
.PHONY : CMakeFiles/testfuncrecursive1.dir/build

CMakeFiles/testfuncrecursive1.dir/requires: CMakeFiles/testfuncrecursive1.dir/Test/testfuncrecursive1.cpp.o.requires
.PHONY : CMakeFiles/testfuncrecursive1.dir/requires

CMakeFiles/testfuncrecursive1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testfuncrecursive1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testfuncrecursive1.dir/clean

CMakeFiles/testfuncrecursive1.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testfuncrecursive1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testfuncrecursive1.dir/depend

