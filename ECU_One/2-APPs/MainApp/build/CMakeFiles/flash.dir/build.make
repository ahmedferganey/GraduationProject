# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/bin/cmake

# The command to remove a file.
RM = /opt/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp/build

# Utility rule file for flash.

# Include any custom commands dependencies for this target.
include CMakeFiles/flash.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/flash.dir/progress.make

CMakeFiles/flash: AutonomousVehicle.elf
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-objcopy -j .text -j .data -O ihex AutonomousVehicle.elf AutonomousVehicle.hex
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-size -t AutonomousVehicle.elf

flash: CMakeFiles/flash
flash: CMakeFiles/flash.dir/build.make
.PHONY : flash

# Rule to build all files generated by this target.
CMakeFiles/flash.dir/build: flash
.PHONY : CMakeFiles/flash.dir/build

CMakeFiles/flash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flash.dir/clean

CMakeFiles/flash.dir/depend:
	cd /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp/build /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp/build /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/ECU_One/2-APPs/MainApp/build/CMakeFiles/flash.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/flash.dir/depend

