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
include CMakeFiles/testdummy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testdummy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testdummy.dir/flags.make

CMakeFiles/testdummy.dir/Test/testdummy.cpp.o: CMakeFiles/testdummy.dir/flags.make
CMakeFiles/testdummy.dir/Test/testdummy.cpp.o: ../Test/testdummy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testdummy.dir/Test/testdummy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testdummy.dir/Test/testdummy.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testdummy.cpp

CMakeFiles/testdummy.dir/Test/testdummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testdummy.dir/Test/testdummy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testdummy.cpp > CMakeFiles/testdummy.dir/Test/testdummy.cpp.i

CMakeFiles/testdummy.dir/Test/testdummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testdummy.dir/Test/testdummy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testdummy.cpp -o CMakeFiles/testdummy.dir/Test/testdummy.cpp.s

CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.requires:
.PHONY : CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.requires

CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.provides: CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.requires
	$(MAKE) -f CMakeFiles/testdummy.dir/build.make CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.provides.build
.PHONY : CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.provides

CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.provides.build: CMakeFiles/testdummy.dir/Test/testdummy.cpp.o
.PHONY : CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.provides.build

# Object files for target testdummy
testdummy_OBJECTS = \
"CMakeFiles/testdummy.dir/Test/testdummy.cpp.o"

# External object files for target testdummy
testdummy_EXTERNAL_OBJECTS =

testdummy: CMakeFiles/testdummy.dir/Test/testdummy.cpp.o
testdummy: libAsmJit.so
testdummy: CMakeFiles/testdummy.dir/build.make
testdummy: CMakeFiles/testdummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testdummy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testdummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testdummy.dir/build: testdummy
.PHONY : CMakeFiles/testdummy.dir/build

CMakeFiles/testdummy.dir/requires: CMakeFiles/testdummy.dir/Test/testdummy.cpp.o.requires
.PHONY : CMakeFiles/testdummy.dir/requires

CMakeFiles/testdummy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testdummy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testdummy.dir/clean

CMakeFiles/testdummy.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testdummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testdummy.dir/depend

