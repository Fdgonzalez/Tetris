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
CMAKE_COMMAND = /home/facundo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/facundo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/facundo/CLionProjects/Tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/facundo/CLionProjects/Tetris/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/src/main.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tetris.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/main.c.o   -c /home/facundo/CLionProjects/Tetris/src/main.c

CMakeFiles/Tetris.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/main.c > CMakeFiles/Tetris.dir/src/main.c.i

CMakeFiles/Tetris.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/main.c -o CMakeFiles/Tetris.dir/src/main.c.s

CMakeFiles/Tetris.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/main.c.o.requires

CMakeFiles/Tetris.dir/src/main.c.o.provides: CMakeFiles/Tetris.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/main.c.o.provides

CMakeFiles/Tetris.dir/src/main.c.o.provides.build: CMakeFiles/Tetris.dir/src/main.c.o


CMakeFiles/Tetris.dir/src/block.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/block.c.o: ../src/block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tetris.dir/src/block.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/block.c.o   -c /home/facundo/CLionProjects/Tetris/src/block.c

CMakeFiles/Tetris.dir/src/block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/block.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/block.c > CMakeFiles/Tetris.dir/src/block.c.i

CMakeFiles/Tetris.dir/src/block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/block.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/block.c -o CMakeFiles/Tetris.dir/src/block.c.s

CMakeFiles/Tetris.dir/src/block.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/block.c.o.requires

CMakeFiles/Tetris.dir/src/block.c.o.provides: CMakeFiles/Tetris.dir/src/block.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/block.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/block.c.o.provides

CMakeFiles/Tetris.dir/src/block.c.o.provides.build: CMakeFiles/Tetris.dir/src/block.c.o


CMakeFiles/Tetris.dir/src/grid.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/grid.c.o: ../src/grid.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Tetris.dir/src/grid.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/grid.c.o   -c /home/facundo/CLionProjects/Tetris/src/grid.c

CMakeFiles/Tetris.dir/src/grid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/grid.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/grid.c > CMakeFiles/Tetris.dir/src/grid.c.i

CMakeFiles/Tetris.dir/src/grid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/grid.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/grid.c -o CMakeFiles/Tetris.dir/src/grid.c.s

CMakeFiles/Tetris.dir/src/grid.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/grid.c.o.requires

CMakeFiles/Tetris.dir/src/grid.c.o.provides: CMakeFiles/Tetris.dir/src/grid.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/grid.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/grid.c.o.provides

CMakeFiles/Tetris.dir/src/grid.c.o.provides.build: CMakeFiles/Tetris.dir/src/grid.c.o


CMakeFiles/Tetris.dir/src/tetromino.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/tetromino.c.o: ../src/tetromino.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Tetris.dir/src/tetromino.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/tetromino.c.o   -c /home/facundo/CLionProjects/Tetris/src/tetromino.c

CMakeFiles/Tetris.dir/src/tetromino.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/tetromino.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/tetromino.c > CMakeFiles/Tetris.dir/src/tetromino.c.i

CMakeFiles/Tetris.dir/src/tetromino.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/tetromino.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/tetromino.c -o CMakeFiles/Tetris.dir/src/tetromino.c.s

CMakeFiles/Tetris.dir/src/tetromino.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/tetromino.c.o.requires

CMakeFiles/Tetris.dir/src/tetromino.c.o.provides: CMakeFiles/Tetris.dir/src/tetromino.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/tetromino.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/tetromino.c.o.provides

CMakeFiles/Tetris.dir/src/tetromino.c.o.provides.build: CMakeFiles/Tetris.dir/src/tetromino.c.o


CMakeFiles/Tetris.dir/src/score.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/score.c.o: ../src/score.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Tetris.dir/src/score.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/score.c.o   -c /home/facundo/CLionProjects/Tetris/src/score.c

CMakeFiles/Tetris.dir/src/score.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/score.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/score.c > CMakeFiles/Tetris.dir/src/score.c.i

CMakeFiles/Tetris.dir/src/score.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/score.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/score.c -o CMakeFiles/Tetris.dir/src/score.c.s

CMakeFiles/Tetris.dir/src/score.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/score.c.o.requires

CMakeFiles/Tetris.dir/src/score.c.o.provides: CMakeFiles/Tetris.dir/src/score.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/score.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/score.c.o.provides

CMakeFiles/Tetris.dir/src/score.c.o.provides.build: CMakeFiles/Tetris.dir/src/score.c.o


CMakeFiles/Tetris.dir/src/sound.c.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/sound.c.o: ../src/sound.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Tetris.dir/src/sound.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tetris.dir/src/sound.c.o   -c /home/facundo/CLionProjects/Tetris/src/sound.c

CMakeFiles/Tetris.dir/src/sound.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/src/sound.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/facundo/CLionProjects/Tetris/src/sound.c > CMakeFiles/Tetris.dir/src/sound.c.i

CMakeFiles/Tetris.dir/src/sound.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/src/sound.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/facundo/CLionProjects/Tetris/src/sound.c -o CMakeFiles/Tetris.dir/src/sound.c.s

CMakeFiles/Tetris.dir/src/sound.c.o.requires:

.PHONY : CMakeFiles/Tetris.dir/src/sound.c.o.requires

CMakeFiles/Tetris.dir/src/sound.c.o.provides: CMakeFiles/Tetris.dir/src/sound.c.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/src/sound.c.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/src/sound.c.o.provides

CMakeFiles/Tetris.dir/src/sound.c.o.provides.build: CMakeFiles/Tetris.dir/src/sound.c.o


# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/src/main.c.o" \
"CMakeFiles/Tetris.dir/src/block.c.o" \
"CMakeFiles/Tetris.dir/src/grid.c.o" \
"CMakeFiles/Tetris.dir/src/tetromino.c.o" \
"CMakeFiles/Tetris.dir/src/score.c.o" \
"CMakeFiles/Tetris.dir/src/sound.c.o"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris: CMakeFiles/Tetris.dir/src/main.c.o
Tetris: CMakeFiles/Tetris.dir/src/block.c.o
Tetris: CMakeFiles/Tetris.dir/src/grid.c.o
Tetris: CMakeFiles/Tetris.dir/src/tetromino.c.o
Tetris: CMakeFiles/Tetris.dir/src/score.c.o
Tetris: CMakeFiles/Tetris.dir/src/sound.c.o
Tetris: CMakeFiles/Tetris.dir/build.make
Tetris: /usr/lib64/libSDL2.so
Tetris: /usr/lib64/libSDL2_image.so
Tetris: /usr/lib64/libSDL2_ttf.so
Tetris: /usr/lib64/libSDL2_mixer.so
Tetris: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris

.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/main.c.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/block.c.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/grid.c.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/tetromino.c.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/score.c.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/src/sound.c.o.requires

.PHONY : CMakeFiles/Tetris.dir/requires

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	cd /home/facundo/CLionProjects/Tetris/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/facundo/CLionProjects/Tetris /home/facundo/CLionProjects/Tetris /home/facundo/CLionProjects/Tetris/cmake-build-debug /home/facundo/CLionProjects/Tetris/cmake-build-debug /home/facundo/CLionProjects/Tetris/cmake-build-debug/CMakeFiles/Tetris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend

