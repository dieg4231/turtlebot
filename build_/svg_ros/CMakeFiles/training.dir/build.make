# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/diego/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/catkin_ws/build

# Include any dependencies generated for this target.
include svg_ros/CMakeFiles/training.dir/depend.make

# Include the progress variables for this target.
include svg_ros/CMakeFiles/training.dir/progress.make

# Include the compile flags for this target's objects.
include svg_ros/CMakeFiles/training.dir/flags.make

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o: svg_ros/CMakeFiles/training.dir/flags.make
svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o: /home/diego/catkin_ws/src/svg_ros/src/training/training.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/diego/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o"
	cd /home/diego/catkin_ws/build/svg_ros && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/training.dir/src/training/training.cpp.o -c /home/diego/catkin_ws/src/svg_ros/src/training/training.cpp

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/training.dir/src/training/training.cpp.i"
	cd /home/diego/catkin_ws/build/svg_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/diego/catkin_ws/src/svg_ros/src/training/training.cpp > CMakeFiles/training.dir/src/training/training.cpp.i

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/training.dir/src/training/training.cpp.s"
	cd /home/diego/catkin_ws/build/svg_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/diego/catkin_ws/src/svg_ros/src/training/training.cpp -o CMakeFiles/training.dir/src/training/training.cpp.s

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.requires:
.PHONY : svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.requires

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.provides: svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.requires
	$(MAKE) -f svg_ros/CMakeFiles/training.dir/build.make svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.provides.build
.PHONY : svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.provides

svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.provides.build: svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o

# Object files for target training
training_OBJECTS = \
"CMakeFiles/training.dir/src/training/training.cpp.o"

# External object files for target training
training_EXTERNAL_OBJECTS =

/home/diego/catkin_ws/devel/lib/svg_ros/training: svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o
/home/diego/catkin_ws/devel/lib/svg_ros/training: svg_ros/CMakeFiles/training.dir/build.make
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/libroscpp.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/librosconsole.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/liblog4cxx.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/librostime.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /opt/ros/indigo/lib/libcpp_common.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/diego/catkin_ws/devel/lib/svg_ros/training: svg_ros/CMakeFiles/training.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/diego/catkin_ws/devel/lib/svg_ros/training"
	cd /home/diego/catkin_ws/build/svg_ros && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/training.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
svg_ros/CMakeFiles/training.dir/build: /home/diego/catkin_ws/devel/lib/svg_ros/training
.PHONY : svg_ros/CMakeFiles/training.dir/build

svg_ros/CMakeFiles/training.dir/requires: svg_ros/CMakeFiles/training.dir/src/training/training.cpp.o.requires
.PHONY : svg_ros/CMakeFiles/training.dir/requires

svg_ros/CMakeFiles/training.dir/clean:
	cd /home/diego/catkin_ws/build/svg_ros && $(CMAKE_COMMAND) -P CMakeFiles/training.dir/cmake_clean.cmake
.PHONY : svg_ros/CMakeFiles/training.dir/clean

svg_ros/CMakeFiles/training.dir/depend:
	cd /home/diego/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/catkin_ws/src /home/diego/catkin_ws/src/svg_ros /home/diego/catkin_ws/build /home/diego/catkin_ws/build/svg_ros /home/diego/catkin_ws/build/svg_ros/CMakeFiles/training.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : svg_ros/CMakeFiles/training.dir/depend

