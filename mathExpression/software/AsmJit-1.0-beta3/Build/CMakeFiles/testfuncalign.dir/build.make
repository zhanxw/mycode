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
include CMakeFiles/testfuncalign.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testfuncalign.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testfuncalign.dir/flags.make

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o: CMakeFiles/testfuncalign.dir/flags.make
CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o: ../Test/testfuncalign.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o -c /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncalign.cpp

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncalign.cpp > CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.i

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Test/testfuncalign.cpp -o CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.s

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.requires:
.PHONY : CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.requires

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.provides: CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.requires
	$(MAKE) -f CMakeFiles/testfuncalign.dir/build.make CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.provides.build
.PHONY : CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.provides

CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.provides.build: CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o
.PHONY : CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.provides.build

# Object files for target testfuncalign
testfuncalign_OBJECTS = \
"CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o"

# External object files for target testfuncalign
testfuncalign_EXTERNAL_OBJECTS =

testfuncalign: CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o
testfuncalign: libAsmJit.so
testfuncalign: CMakeFiles/testfuncalign.dir/build.make
testfuncalign: CMakeFiles/testfuncalign.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testfuncalign"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testfuncalign.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testfuncalign.dir/build: testfuncalign
.PHONY : CMakeFiles/testfuncalign.dir/build

CMakeFiles/testfuncalign.dir/requires: CMakeFiles/testfuncalign.dir/Test/testfuncalign.cpp.o.requires
.PHONY : CMakeFiles/testfuncalign.dir/requires

CMakeFiles/testfuncalign.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testfuncalign.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testfuncalign.dir/clean

CMakeFiles/testfuncalign.dir/depend:
	cd /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3 /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build /net/fantasia/home/zhanxw/mycode/mathExpression/software/AsmJit-1.0-beta3/Build/CMakeFiles/testfuncalign.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testfuncalign.dir/depend
