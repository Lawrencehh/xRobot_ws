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
include communication_test/CMakeFiles/gps_data_serialPort.dir/depend.make

# Include the progress variables for this target.
include communication_test/CMakeFiles/gps_data_serialPort.dir/progress.make

# Include the compile flags for this target's objects.
include communication_test/CMakeFiles/gps_data_serialPort.dir/flags.make

communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o: communication_test/CMakeFiles/gps_data_serialPort.dir/flags.make
communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o: /home/ubuntu/xRobot_ws/src/communication_test/src/~robot_data_serialPort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o"
	cd /home/ubuntu/xRobot_ws/build/communication_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o" -c "/home/ubuntu/xRobot_ws/src/communication_test/src/~robot_data_serialPort.cpp"

communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.i"
	cd /home/ubuntu/xRobot_ws/build/communication_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/xRobot_ws/src/communication_test/src/~robot_data_serialPort.cpp" > "CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.i"

communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.s"
	cd /home/ubuntu/xRobot_ws/build/communication_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/xRobot_ws/src/communication_test/src/~robot_data_serialPort.cpp" -o "CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.s"

# Object files for target gps_data_serialPort
gps_data_serialPort_OBJECTS = \
"CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o"

# External object files for target gps_data_serialPort
gps_data_serialPort_EXTERNAL_OBJECTS =

/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: communication_test/CMakeFiles/gps_data_serialPort.dir/src/~robot_data_serialPort.cpp.o
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: communication_test/CMakeFiles/gps_data_serialPort.dir/build.make
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/libserial.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/libroscpp.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/librosconsole.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/librostime.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /opt/ros/kinetic/lib/libcpp_common.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort: communication_test/CMakeFiles/gps_data_serialPort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort"
	cd /home/ubuntu/xRobot_ws/build/communication_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gps_data_serialPort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
communication_test/CMakeFiles/gps_data_serialPort.dir/build: /home/ubuntu/xRobot_ws/devel/lib/communication_test/gps_data_serialPort

.PHONY : communication_test/CMakeFiles/gps_data_serialPort.dir/build

communication_test/CMakeFiles/gps_data_serialPort.dir/clean:
	cd /home/ubuntu/xRobot_ws/build/communication_test && $(CMAKE_COMMAND) -P CMakeFiles/gps_data_serialPort.dir/cmake_clean.cmake
.PHONY : communication_test/CMakeFiles/gps_data_serialPort.dir/clean

communication_test/CMakeFiles/gps_data_serialPort.dir/depend:
	cd /home/ubuntu/xRobot_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/xRobot_ws/src /home/ubuntu/xRobot_ws/src/communication_test /home/ubuntu/xRobot_ws/build /home/ubuntu/xRobot_ws/build/communication_test /home/ubuntu/xRobot_ws/build/communication_test/CMakeFiles/gps_data_serialPort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : communication_test/CMakeFiles/gps_data_serialPort.dir/depend

