# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/xRobot_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/xRobot_ws/build

# Include any dependencies generated for this target.
include turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/depend.make

# Include the progress variables for this target.
include turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/progress.make

# Include the compile flags for this target's objects.
include turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/flags.make

turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o: turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/flags.make
turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o: /home/ubuntu/xRobot_ws/src/turtlebot/turtlebot_teleop/src/logitech_joy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o"
	cd /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o -c /home/ubuntu/xRobot_ws/src/turtlebot/turtlebot_teleop/src/logitech_joy.cpp

turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.i"
	cd /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/xRobot_ws/src/turtlebot/turtlebot_teleop/src/logitech_joy.cpp > CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.i

turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.s"
	cd /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/xRobot_ws/src/turtlebot/turtlebot_teleop/src/logitech_joy.cpp -o CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.s

# Object files for target logitech_joy
logitech_joy_OBJECTS = \
"CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o"

# External object files for target logitech_joy
logitech_joy_EXTERNAL_OBJECTS =

/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/src/logitech_joy.cpp.o
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/build.make
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/libroscpp.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/librosconsole.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/librostime.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /opt/ros/kinetic/lib/libcpp_common.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy: turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy"
	cd /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logitech_joy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/build: /home/ubuntu/xRobot_ws/devel/lib/turtlebot_teleop/logitech_joy

.PHONY : turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/build

turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/clean:
	cd /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop && $(CMAKE_COMMAND) -P CMakeFiles/logitech_joy.dir/cmake_clean.cmake
.PHONY : turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/clean

turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/depend:
	cd /home/ubuntu/xRobot_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/xRobot_ws/src /home/ubuntu/xRobot_ws/src/turtlebot/turtlebot_teleop /home/ubuntu/xRobot_ws/build /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop /home/ubuntu/xRobot_ws/build/turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : turtlebot/turtlebot_teleop/CMakeFiles/logitech_joy.dir/depend

