# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/sovest/CLionProjects/KURSACH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sovest/CLionProjects/KURSACH/build

# Utility rule file for KURSACH_autogen.

# Include the progress variables for this target.
include CMakeFiles/KURSACH_autogen.dir/progress.make

CMakeFiles/KURSACH_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sovest/CLionProjects/KURSACH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target KURSACH"
	/usr/bin/cmake -E cmake_autogen /home/sovest/CLionProjects/KURSACH/build/CMakeFiles/KURSACH_autogen.dir/AutogenInfo.json Debug

KURSACH_autogen: CMakeFiles/KURSACH_autogen
KURSACH_autogen: CMakeFiles/KURSACH_autogen.dir/build.make

.PHONY : KURSACH_autogen

# Rule to build all files generated by this target.
CMakeFiles/KURSACH_autogen.dir/build: KURSACH_autogen

.PHONY : CMakeFiles/KURSACH_autogen.dir/build

CMakeFiles/KURSACH_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KURSACH_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KURSACH_autogen.dir/clean

CMakeFiles/KURSACH_autogen.dir/depend:
	cd /home/sovest/CLionProjects/KURSACH/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sovest/CLionProjects/KURSACH /home/sovest/CLionProjects/KURSACH /home/sovest/CLionProjects/KURSACH/build /home/sovest/CLionProjects/KURSACH/build /home/sovest/CLionProjects/KURSACH/build/CMakeFiles/KURSACH_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KURSACH_autogen.dir/depend

