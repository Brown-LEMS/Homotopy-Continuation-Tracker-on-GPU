# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /oscar/rt/9.2/software/0.20-generic/0.20.1/opt/spack/linux-rhel9-x86_64_v3/gcc-11.3.1/cmake-3.26.3-xi6h36u7udrui6ecslslsh4gak4djiwq/bin/cmake

# The command to remove a file.
RM = /oscar/rt/9.2/software/0.20-generic/0.20.1/opt/spack/linux-rhel9-x86_64_v3/gcc-11.3.1/cmake-3.26.3-xi6h36u7udrui6ecslslsh4gak4djiwq/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build

# Utility rule file for NightlyMemCheck.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlyMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlyMemCheck.dir/progress.make

CMakeFiles/NightlyMemCheck:
	/oscar/rt/9.2/software/0.20-generic/0.20.1/opt/spack/linux-rhel9-x86_64_v3/gcc-11.3.1/cmake-3.26.3-xi6h36u7udrui6ecslslsh4gak4djiwq/bin/ctest -D NightlyMemCheck

NightlyMemCheck: CMakeFiles/NightlyMemCheck
NightlyMemCheck: CMakeFiles/NightlyMemCheck.dir/build.make
.PHONY : NightlyMemCheck

# Rule to build all files generated by this target.
CMakeFiles/NightlyMemCheck.dir/build: NightlyMemCheck
.PHONY : CMakeFiles/NightlyMemCheck.dir/build

CMakeFiles/NightlyMemCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyMemCheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyMemCheck.dir/clean

CMakeFiles/NightlyMemCheck.dir/depend:
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/CMakeFiles/NightlyMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NightlyMemCheck.dir/depend

