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

# Include any dependencies generated for this target.
include cmd/CMakeFiles/magmaHC-main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cmd/CMakeFiles/magmaHC-main.dir/compiler_depend.make

# Include the progress variables for this target.
include cmd/CMakeFiles/magmaHC-main.dir/progress.make

# Include the compile flags for this target's objects.
include cmd/CMakeFiles/magmaHC-main.dir/flags.make

cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o: cmd/CMakeFiles/magmaHC-main.dir/flags.make
cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o: /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/cmd/magmaHC-main.cpp
cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o: cmd/CMakeFiles/magmaHC-main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o"
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o -MF CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o.d -o CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o -c /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/cmd/magmaHC-main.cpp

cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.i"
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/cmd/magmaHC-main.cpp > CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.i

cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.s"
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/cmd/magmaHC-main.cpp -o CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.s

# Object files for target magmaHC-main
magmaHC__main_OBJECTS = \
"CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o"

# External object files for target magmaHC-main
magmaHC__main_EXTERNAL_OBJECTS =

cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o
cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: cmd/CMakeFiles/magmaHC-main.dir/build.make
cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: lib/libmagmaHC.a
cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: cmd/CMakeFiles/magmaHC-main.dir/deviceLinkLibs.rsp
cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: cmd/CMakeFiles/magmaHC-main.dir/deviceObjects1.rsp
cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o: cmd/CMakeFiles/magmaHC-main.dir/dlink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA device code CMakeFiles/magmaHC-main.dir/cmake_device_link.o"
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magmaHC-main.dir/dlink.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cmd/CMakeFiles/magmaHC-main.dir/build: cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o
.PHONY : cmd/CMakeFiles/magmaHC-main.dir/build

# Object files for target magmaHC-main
magmaHC__main_OBJECTS = \
"CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o"

# External object files for target magmaHC-main
magmaHC__main_EXTERNAL_OBJECTS =

bin/magmaHC-main: cmd/CMakeFiles/magmaHC-main.dir/magmaHC-main.cpp.o
bin/magmaHC-main: cmd/CMakeFiles/magmaHC-main.dir/build.make
bin/magmaHC-main: lib/libmagmaHC.a
bin/magmaHC-main: cmd/CMakeFiles/magmaHC-main.dir/cmake_device_link.o
bin/magmaHC-main: cmd/CMakeFiles/magmaHC-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/magmaHC-main"
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magmaHC-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cmd/CMakeFiles/magmaHC-main.dir/build: bin/magmaHC-main
.PHONY : cmd/CMakeFiles/magmaHC-main.dir/build

cmd/CMakeFiles/magmaHC-main.dir/clean:
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd && $(CMAKE_COMMAND) -P CMakeFiles/magmaHC-main.dir/cmake_clean.cmake
.PHONY : cmd/CMakeFiles/magmaHC-main.dir/clean

cmd/CMakeFiles/magmaHC-main.dir/depend:
	cd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/cmd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd /gpfs/data/bkimia/cchien3/Homotopy-Continuation-Tracker-on-GPU/GPU-HC/build/cmd/CMakeFiles/magmaHC-main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cmd/CMakeFiles/magmaHC-main.dir/depend

