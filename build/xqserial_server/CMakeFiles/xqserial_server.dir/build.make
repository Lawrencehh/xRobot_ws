# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/andy/xRobot_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andy/xRobot_ws/build

# Include any dependencies generated for this target.
include xqserial_server/CMakeFiles/xqserial_server.dir/depend.make

# Include the progress variables for this target.
include xqserial_server/CMakeFiles/xqserial_server.dir/progress.make

# Include the compile flags for this target's objects.
include xqserial_server/CMakeFiles/xqserial_server.dir/flags.make

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o: xqserial_server/CMakeFiles/xqserial_server.dir/flags.make
xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o: /home/andy/xRobot_ws/src/xqserial_server/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andy/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xqserial_server.dir/src/main.cpp.o -c /home/andy/xRobot_ws/src/xqserial_server/src/main.cpp

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xqserial_server.dir/src/main.cpp.i"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andy/xRobot_ws/src/xqserial_server/src/main.cpp > CMakeFiles/xqserial_server.dir/src/main.cpp.i

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xqserial_server.dir/src/main.cpp.s"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andy/xRobot_ws/src/xqserial_server/src/main.cpp -o CMakeFiles/xqserial_server.dir/src/main.cpp.s

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.requires:

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.requires

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.provides: xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.requires
	$(MAKE) -f xqserial_server/CMakeFiles/xqserial_server.dir/build.make xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.provides.build
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.provides

xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.provides.build: xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o


xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o: xqserial_server/CMakeFiles/xqserial_server.dir/flags.make
xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o: /home/andy/xRobot_ws/src/xqserial_server/src/AsyncSerial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andy/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o -c /home/andy/xRobot_ws/src/xqserial_server/src/AsyncSerial.cpp

xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.i"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andy/xRobot_ws/src/xqserial_server/src/AsyncSerial.cpp > CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.i

xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.s"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andy/xRobot_ws/src/xqserial_server/src/AsyncSerial.cpp -o CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.s

xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.requires:

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.requires

xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.provides: xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.requires
	$(MAKE) -f xqserial_server/CMakeFiles/xqserial_server.dir/build.make xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.provides.build
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.provides

xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.provides.build: xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o


xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o: xqserial_server/CMakeFiles/xqserial_server.dir/flags.make
xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o: /home/andy/xRobot_ws/src/xqserial_server/src/DiffDriverController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andy/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o -c /home/andy/xRobot_ws/src/xqserial_server/src/DiffDriverController.cpp

xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.i"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andy/xRobot_ws/src/xqserial_server/src/DiffDriverController.cpp > CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.i

xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.s"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andy/xRobot_ws/src/xqserial_server/src/DiffDriverController.cpp -o CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.s

xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.requires:

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.requires

xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.provides: xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.requires
	$(MAKE) -f xqserial_server/CMakeFiles/xqserial_server.dir/build.make xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.provides.build
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.provides

xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.provides.build: xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o


xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o: xqserial_server/CMakeFiles/xqserial_server.dir/flags.make
xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o: /home/andy/xRobot_ws/src/xqserial_server/src/StatusPublisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andy/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o -c /home/andy/xRobot_ws/src/xqserial_server/src/StatusPublisher.cpp

xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.i"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andy/xRobot_ws/src/xqserial_server/src/StatusPublisher.cpp > CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.i

xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.s"
	cd /home/andy/xRobot_ws/build/xqserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andy/xRobot_ws/src/xqserial_server/src/StatusPublisher.cpp -o CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.s

xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.requires:

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.requires

xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.provides: xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.requires
	$(MAKE) -f xqserial_server/CMakeFiles/xqserial_server.dir/build.make xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.provides.build
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.provides

xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.provides.build: xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o


# Object files for target xqserial_server
xqserial_server_OBJECTS = \
"CMakeFiles/xqserial_server.dir/src/main.cpp.o" \
"CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o" \
"CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o" \
"CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o"

# External object files for target xqserial_server
xqserial_server_EXTERNAL_OBJECTS =

/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/build.make
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libtf.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libtf2_ros.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libactionlib.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libmessage_filters.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libtf2.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libroscpp.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/librosconsole.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/librostime.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /opt/ros/kinetic/lib/libcpp_common.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server: xqserial_server/CMakeFiles/xqserial_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andy/xRobot_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable /home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server"
	cd /home/andy/xRobot_ws/build/xqserial_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xqserial_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
xqserial_server/CMakeFiles/xqserial_server.dir/build: /home/andy/xRobot_ws/devel/lib/xqserial_server/xqserial_server

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/build

xqserial_server/CMakeFiles/xqserial_server.dir/requires: xqserial_server/CMakeFiles/xqserial_server.dir/src/main.cpp.o.requires
xqserial_server/CMakeFiles/xqserial_server.dir/requires: xqserial_server/CMakeFiles/xqserial_server.dir/src/AsyncSerial.cpp.o.requires
xqserial_server/CMakeFiles/xqserial_server.dir/requires: xqserial_server/CMakeFiles/xqserial_server.dir/src/DiffDriverController.cpp.o.requires
xqserial_server/CMakeFiles/xqserial_server.dir/requires: xqserial_server/CMakeFiles/xqserial_server.dir/src/StatusPublisher.cpp.o.requires

.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/requires

xqserial_server/CMakeFiles/xqserial_server.dir/clean:
	cd /home/andy/xRobot_ws/build/xqserial_server && $(CMAKE_COMMAND) -P CMakeFiles/xqserial_server.dir/cmake_clean.cmake
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/clean

xqserial_server/CMakeFiles/xqserial_server.dir/depend:
	cd /home/andy/xRobot_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andy/xRobot_ws/src /home/andy/xRobot_ws/src/xqserial_server /home/andy/xRobot_ws/build /home/andy/xRobot_ws/build/xqserial_server /home/andy/xRobot_ws/build/xqserial_server/CMakeFiles/xqserial_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xqserial_server/CMakeFiles/xqserial_server.dir/depend

