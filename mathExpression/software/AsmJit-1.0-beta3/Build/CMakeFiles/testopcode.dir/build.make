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
include CMakeFiles/testopcode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testopcode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testopcode.dir/flags.make

CMakeFiles/testopcode.dir/Test/testopcode.cpp.o: CMakeFiles/testopcode.dir/flags.make
CMakeFiles/testopcode.dir/Test/testopcode.cpp.o: ../Test/testopcode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testopcode.dir/Test/testopcode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testopcode.dir/Test/testopcode.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testopcode.cpp

CMakeFiles/testopcode.dir/Test/testopcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopcode.dir/Test/testopcode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testopcode.cpp > CMakeFiles/testopcode.dir/Test/testopcode.cpp.i

CMakeFiles/testopcode.dir/Test/testopcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopcode.dir/Test/testopcode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testopcode.cpp -o CMakeFiles/testopcode.dir/Test/testopcode.cpp.s

CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.requires:
.PHONY : CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.requires

CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.provides: CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.requires
	$(MAKE) -f CMakeFiles/testopcode.dir/build.make CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.provides.build
.PHONY : CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.provides

CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.provides.build: CMakeFiles/testopcode.dir/Test/testopcode.cpp.o
.PHONY : CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.provides.build

# Object files for target testopcode
testopcode_OBJECTS = \
"CMakeFiles/testopcode.dir/Test/testopcode.cpp.o"

# External object files for target testopcode
testopcode_EXTERNAL_OBJECTS =

testopcode: CMakeFiles/testopcode.dir/Test/testopcode.cpp.o
testopcode: libAsmJit.so
testopcode: CMakeFiles/testopcode.dir/build.make
testopcode: CMakeFiles/testopcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testopcode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testopcode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testopcode.dir/build: testopcode
.PHONY : CMakeFiles/testopcode.dir/build

CMakeFiles/testopcode.dir/requires: CMakeFiles/testopcode.dir/Test/testopcode.cpp.o.requires
.PHONY : CMakeFiles/testopcode.dir/requires

CMakeFiles/testopcode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testopcode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testopcode.dir/clean

CMakeFiles/testopcode.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testopcode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testopcode.dir/depend
