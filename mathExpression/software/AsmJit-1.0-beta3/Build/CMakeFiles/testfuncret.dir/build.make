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
include CMakeFiles/testfuncret.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testfuncret.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testfuncret.dir/flags.make

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o: CMakeFiles/testfuncret.dir/flags.make
CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o: ../Test/testfuncret.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncret.cpp

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncret.cpp > CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.i

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncret.cpp -o CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.s

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.requires:
.PHONY : CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.requires

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.provides: CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.requires
	$(MAKE) -f CMakeFiles/testfuncret.dir/build.make CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.provides.build
.PHONY : CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.provides

CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.provides.build: CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o
.PHONY : CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.provides.build

# Object files for target testfuncret
testfuncret_OBJECTS = \
"CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o"

# External object files for target testfuncret
testfuncret_EXTERNAL_OBJECTS =

testfuncret: CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o
testfuncret: libAsmJit.so
testfuncret: CMakeFiles/testfuncret.dir/build.make
testfuncret: CMakeFiles/testfuncret.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testfuncret"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testfuncret.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testfuncret.dir/build: testfuncret
.PHONY : CMakeFiles/testfuncret.dir/build

CMakeFiles/testfuncret.dir/requires: CMakeFiles/testfuncret.dir/Test/testfuncret.cpp.o.requires
.PHONY : CMakeFiles/testfuncret.dir/requires

CMakeFiles/testfuncret.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testfuncret.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testfuncret.dir/clean

CMakeFiles/testfuncret.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testfuncret.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testfuncret.dir/depend
