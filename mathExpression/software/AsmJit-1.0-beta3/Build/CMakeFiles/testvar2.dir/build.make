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
include CMakeFiles/testvar2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testvar2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testvar2.dir/flags.make

CMakeFiles/testvar2.dir/Test/testvar2.cpp.o: CMakeFiles/testvar2.dir/flags.make
CMakeFiles/testvar2.dir/Test/testvar2.cpp.o: ../Test/testvar2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testvar2.dir/Test/testvar2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testvar2.dir/Test/testvar2.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testvar2.cpp

CMakeFiles/testvar2.dir/Test/testvar2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testvar2.dir/Test/testvar2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testvar2.cpp > CMakeFiles/testvar2.dir/Test/testvar2.cpp.i

CMakeFiles/testvar2.dir/Test/testvar2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testvar2.dir/Test/testvar2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testvar2.cpp -o CMakeFiles/testvar2.dir/Test/testvar2.cpp.s

CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.requires:
.PHONY : CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.requires

CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.provides: CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.requires
	$(MAKE) -f CMakeFiles/testvar2.dir/build.make CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.provides.build
.PHONY : CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.provides

CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.provides.build: CMakeFiles/testvar2.dir/Test/testvar2.cpp.o
.PHONY : CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.provides.build

# Object files for target testvar2
testvar2_OBJECTS = \
"CMakeFiles/testvar2.dir/Test/testvar2.cpp.o"

# External object files for target testvar2
testvar2_EXTERNAL_OBJECTS =

testvar2: CMakeFiles/testvar2.dir/Test/testvar2.cpp.o
testvar2: libAsmJit.so
testvar2: CMakeFiles/testvar2.dir/build.make
testvar2: CMakeFiles/testvar2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testvar2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testvar2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testvar2.dir/build: testvar2
.PHONY : CMakeFiles/testvar2.dir/build

CMakeFiles/testvar2.dir/requires: CMakeFiles/testvar2.dir/Test/testvar2.cpp.o.requires
.PHONY : CMakeFiles/testvar2.dir/requires

CMakeFiles/testvar2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testvar2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testvar2.dir/clean

CMakeFiles/testvar2.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testvar2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testvar2.dir/depend

