# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/leha/RV_sim/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leha/RV_sim

# Include any dependencies generated for this target.
include CMakeFiles/fsim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fsim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fsim.dir/flags.make

CMakeFiles/fsim.dir/fsim.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/fsim.cpp.o: src/fsim.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fsim.dir/fsim.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/fsim.cpp.o -c /home/leha/RV_sim/src/fsim.cpp

CMakeFiles/fsim.dir/fsim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/fsim.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/fsim.cpp > CMakeFiles/fsim.dir/fsim.cpp.i

CMakeFiles/fsim.dir/fsim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/fsim.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/fsim.cpp -o CMakeFiles/fsim.dir/fsim.cpp.s

CMakeFiles/fsim.dir/fsim.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/fsim.cpp.o.requires

CMakeFiles/fsim.dir/fsim.cpp.o.provides: CMakeFiles/fsim.dir/fsim.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/fsim.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/fsim.cpp.o.provides

CMakeFiles/fsim.dir/fsim.cpp.o.provides.build: CMakeFiles/fsim.dir/fsim.cpp.o


CMakeFiles/fsim.dir/simulator.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/simulator.cpp.o: src/simulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fsim.dir/simulator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/simulator.cpp.o -c /home/leha/RV_sim/src/simulator.cpp

CMakeFiles/fsim.dir/simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/simulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/simulator.cpp > CMakeFiles/fsim.dir/simulator.cpp.i

CMakeFiles/fsim.dir/simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/simulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/simulator.cpp -o CMakeFiles/fsim.dir/simulator.cpp.s

CMakeFiles/fsim.dir/simulator.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/simulator.cpp.o.requires

CMakeFiles/fsim.dir/simulator.cpp.o.provides: CMakeFiles/fsim.dir/simulator.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/simulator.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/simulator.cpp.o.provides

CMakeFiles/fsim.dir/simulator.cpp.o.provides.build: CMakeFiles/fsim.dir/simulator.cpp.o


CMakeFiles/fsim.dir/proc_state.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/proc_state.cpp.o: src/proc_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fsim.dir/proc_state.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/proc_state.cpp.o -c /home/leha/RV_sim/src/proc_state.cpp

CMakeFiles/fsim.dir/proc_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/proc_state.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/proc_state.cpp > CMakeFiles/fsim.dir/proc_state.cpp.i

CMakeFiles/fsim.dir/proc_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/proc_state.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/proc_state.cpp -o CMakeFiles/fsim.dir/proc_state.cpp.s

CMakeFiles/fsim.dir/proc_state.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/proc_state.cpp.o.requires

CMakeFiles/fsim.dir/proc_state.cpp.o.provides: CMakeFiles/fsim.dir/proc_state.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/proc_state.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/proc_state.cpp.o.provides

CMakeFiles/fsim.dir/proc_state.cpp.o.provides.build: CMakeFiles/fsim.dir/proc_state.cpp.o


CMakeFiles/fsim.dir/instruction.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/instruction.cpp.o: src/instruction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fsim.dir/instruction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/instruction.cpp.o -c /home/leha/RV_sim/src/instruction.cpp

CMakeFiles/fsim.dir/instruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/instruction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/instruction.cpp > CMakeFiles/fsim.dir/instruction.cpp.i

CMakeFiles/fsim.dir/instruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/instruction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/instruction.cpp -o CMakeFiles/fsim.dir/instruction.cpp.s

CMakeFiles/fsim.dir/instruction.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/instruction.cpp.o.requires

CMakeFiles/fsim.dir/instruction.cpp.o.provides: CMakeFiles/fsim.dir/instruction.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/instruction.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/instruction.cpp.o.provides

CMakeFiles/fsim.dir/instruction.cpp.o.provides.build: CMakeFiles/fsim.dir/instruction.cpp.o


CMakeFiles/fsim.dir/vmemory.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/vmemory.cpp.o: src/vmemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fsim.dir/vmemory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/vmemory.cpp.o -c /home/leha/RV_sim/src/vmemory.cpp

CMakeFiles/fsim.dir/vmemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/vmemory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/vmemory.cpp > CMakeFiles/fsim.dir/vmemory.cpp.i

CMakeFiles/fsim.dir/vmemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/vmemory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/vmemory.cpp -o CMakeFiles/fsim.dir/vmemory.cpp.s

CMakeFiles/fsim.dir/vmemory.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/vmemory.cpp.o.requires

CMakeFiles/fsim.dir/vmemory.cpp.o.provides: CMakeFiles/fsim.dir/vmemory.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/vmemory.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/vmemory.cpp.o.provides

CMakeFiles/fsim.dir/vmemory.cpp.o.provides.build: CMakeFiles/fsim.dir/vmemory.cpp.o


CMakeFiles/fsim.dir/decoder.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/decoder.cpp.o: src/decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fsim.dir/decoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/decoder.cpp.o -c /home/leha/RV_sim/src/decoder.cpp

CMakeFiles/fsim.dir/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/decoder.cpp > CMakeFiles/fsim.dir/decoder.cpp.i

CMakeFiles/fsim.dir/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/decoder.cpp -o CMakeFiles/fsim.dir/decoder.cpp.s

CMakeFiles/fsim.dir/decoder.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/decoder.cpp.o.requires

CMakeFiles/fsim.dir/decoder.cpp.o.provides: CMakeFiles/fsim.dir/decoder.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/decoder.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/decoder.cpp.o.provides

CMakeFiles/fsim.dir/decoder.cpp.o.provides.build: CMakeFiles/fsim.dir/decoder.cpp.o


CMakeFiles/fsim.dir/memory.cpp.o: CMakeFiles/fsim.dir/flags.make
CMakeFiles/fsim.dir/memory.cpp.o: src/memory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/fsim.dir/memory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsim.dir/memory.cpp.o -c /home/leha/RV_sim/src/memory.cpp

CMakeFiles/fsim.dir/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsim.dir/memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leha/RV_sim/src/memory.cpp > CMakeFiles/fsim.dir/memory.cpp.i

CMakeFiles/fsim.dir/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsim.dir/memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leha/RV_sim/src/memory.cpp -o CMakeFiles/fsim.dir/memory.cpp.s

CMakeFiles/fsim.dir/memory.cpp.o.requires:

.PHONY : CMakeFiles/fsim.dir/memory.cpp.o.requires

CMakeFiles/fsim.dir/memory.cpp.o.provides: CMakeFiles/fsim.dir/memory.cpp.o.requires
	$(MAKE) -f CMakeFiles/fsim.dir/build.make CMakeFiles/fsim.dir/memory.cpp.o.provides.build
.PHONY : CMakeFiles/fsim.dir/memory.cpp.o.provides

CMakeFiles/fsim.dir/memory.cpp.o.provides.build: CMakeFiles/fsim.dir/memory.cpp.o


# Object files for target fsim
fsim_OBJECTS = \
"CMakeFiles/fsim.dir/fsim.cpp.o" \
"CMakeFiles/fsim.dir/simulator.cpp.o" \
"CMakeFiles/fsim.dir/proc_state.cpp.o" \
"CMakeFiles/fsim.dir/instruction.cpp.o" \
"CMakeFiles/fsim.dir/vmemory.cpp.o" \
"CMakeFiles/fsim.dir/decoder.cpp.o" \
"CMakeFiles/fsim.dir/memory.cpp.o"

# External object files for target fsim
fsim_EXTERNAL_OBJECTS =

fsim: CMakeFiles/fsim.dir/fsim.cpp.o
fsim: CMakeFiles/fsim.dir/simulator.cpp.o
fsim: CMakeFiles/fsim.dir/proc_state.cpp.o
fsim: CMakeFiles/fsim.dir/instruction.cpp.o
fsim: CMakeFiles/fsim.dir/vmemory.cpp.o
fsim: CMakeFiles/fsim.dir/decoder.cpp.o
fsim: CMakeFiles/fsim.dir/memory.cpp.o
fsim: CMakeFiles/fsim.dir/build.make
fsim: CMakeFiles/fsim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leha/RV_sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable fsim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fsim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fsim.dir/build: fsim

.PHONY : CMakeFiles/fsim.dir/build

CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/fsim.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/simulator.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/proc_state.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/instruction.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/vmemory.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/decoder.cpp.o.requires
CMakeFiles/fsim.dir/requires: CMakeFiles/fsim.dir/memory.cpp.o.requires

.PHONY : CMakeFiles/fsim.dir/requires

CMakeFiles/fsim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fsim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fsim.dir/clean

CMakeFiles/fsim.dir/depend:
	cd /home/leha/RV_sim && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leha/RV_sim/src /home/leha/RV_sim/src /home/leha/RV_sim /home/leha/RV_sim /home/leha/RV_sim/CMakeFiles/fsim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fsim.dir/depend
