# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/louis/42/philosophers/philo_two

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/louis/42/philosophers/philo_two/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_two.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_two.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_two.dir/flags.make

CMakeFiles/philo_two.dir/srcs/philo_two.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/philo_two.c.o: ../srcs/philo_two.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_two.dir/srcs/philo_two.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/philo_two.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/philo_two.c

CMakeFiles/philo_two.dir/srcs/philo_two.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/philo_two.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/philo_two.c > CMakeFiles/philo_two.dir/srcs/philo_two.c.i

CMakeFiles/philo_two.dir/srcs/philo_two.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/philo_two.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/philo_two.c -o CMakeFiles/philo_two.dir/srcs/philo_two.c.s

CMakeFiles/philo_two.dir/srcs/errors/errors.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/errors/errors.c.o: ../srcs/errors/errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_two.dir/srcs/errors/errors.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/errors/errors.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/errors/errors.c

CMakeFiles/philo_two.dir/srcs/errors/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/errors/errors.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/errors/errors.c > CMakeFiles/philo_two.dir/srcs/errors/errors.c.i

CMakeFiles/philo_two.dir/srcs/errors/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/errors/errors.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/errors/errors.c -o CMakeFiles/philo_two.dir/srcs/errors/errors.c.s

CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o: ../srcs/parsing/parse_arguments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/parsing/parse_arguments.c

CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/parsing/parse_arguments.c > CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.i

CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/parsing/parse_arguments.c -o CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.s

CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o: ../srcs/parsing/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/parsing/utils.c

CMakeFiles/philo_two.dir/srcs/parsing/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/parsing/utils.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/parsing/utils.c > CMakeFiles/philo_two.dir/srcs/parsing/utils.c.i

CMakeFiles/philo_two.dir/srcs/parsing/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/parsing/utils.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/parsing/utils.c -o CMakeFiles/philo_two.dir/srcs/parsing/utils.c.s

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o: ../srcs/philosophers/philo_handler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler.c

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler.c > CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.i

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler.c -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.s

CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o: ../srcs/execution/execute_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/execution/execute_thread.c

CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/execution/execute_thread.c > CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.i

CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/execution/execute_thread.c -o CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.s

CMakeFiles/philo_two.dir/srcs/messages/alert.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/messages/alert.c.o: ../srcs/messages/alert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/philo_two.dir/srcs/messages/alert.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/messages/alert.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/messages/alert.c

CMakeFiles/philo_two.dir/srcs/messages/alert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/messages/alert.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/messages/alert.c > CMakeFiles/philo_two.dir/srcs/messages/alert.c.i

CMakeFiles/philo_two.dir/srcs/messages/alert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/messages/alert.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/messages/alert.c -o CMakeFiles/philo_two.dir/srcs/messages/alert.c.s

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o: ../srcs/philosophers/philo_handler_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_2.c

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_2.c > CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.i

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_2.c -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.s

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o: ../srcs/philosophers/philo_handler_3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o   -c /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_3.c

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_3.c > CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.i

CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/louis/42/philosophers/philo_two/srcs/philosophers/philo_handler_3.c -o CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.s

# Object files for target philo_two
philo_two_OBJECTS = \
"CMakeFiles/philo_two.dir/srcs/philo_two.c.o" \
"CMakeFiles/philo_two.dir/srcs/errors/errors.c.o" \
"CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o" \
"CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o" \
"CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o" \
"CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o" \
"CMakeFiles/philo_two.dir/srcs/messages/alert.c.o" \
"CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o" \
"CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o"

# External object files for target philo_two
philo_two_EXTERNAL_OBJECTS =

philo_two: CMakeFiles/philo_two.dir/srcs/philo_two.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/errors/errors.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/parsing/parse_arguments.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/parsing/utils.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/execution/execute_thread.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/messages/alert.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_2.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/philosophers/philo_handler_3.c.o
philo_two: CMakeFiles/philo_two.dir/build.make
philo_two: CMakeFiles/philo_two.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable philo_two"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_two.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_two.dir/build: philo_two

.PHONY : CMakeFiles/philo_two.dir/build

CMakeFiles/philo_two.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_two.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_two.dir/clean

CMakeFiles/philo_two.dir/depend:
	cd /Users/louis/42/philosophers/philo_two/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/louis/42/philosophers/philo_two /Users/louis/42/philosophers/philo_two /Users/louis/42/philosophers/philo_two/cmake-build-debug /Users/louis/42/philosophers/philo_two/cmake-build-debug /Users/louis/42/philosophers/philo_two/cmake-build-debug/CMakeFiles/philo_two.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_two.dir/depend

