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
CMAKE_SOURCE_DIR = /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build

# Include any dependencies generated for this target.
include CMakeFiles/AutonomousVehicle.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AutonomousVehicle.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AutonomousVehicle.elf.dir/flags.make

CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/APP.c
CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/APP.c

CMakeFiles/AutonomousVehicle.elf.dir/APP.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/APP.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/APP.c > CMakeFiles/AutonomousVehicle.elf.dir/APP.c.i

CMakeFiles/AutonomousVehicle.elf.dir/APP.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/APP.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/APP.c -o CMakeFiles/AutonomousVehicle.elf.dir/APP.c.s

CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DIO_program.c
CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DIO_program.c

CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DIO_program.c > CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.i

CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DIO_program.c -o CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.s

CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DISPLAY_program.c
CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DISPLAY_program.c

CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DISPLAY_program.c > CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.i

CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/DISPLAY_program.c -o CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.s

CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/LCD_program.c
CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/LCD_program.c

CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/LCD_program.c > CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.i

CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/LCD_program.c -o CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.s

CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/TIMER_program.c
CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/TIMER_program.c

CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/TIMER_program.c > CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.i

CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/TIMER_program.c -o CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.s

CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/flags.make
CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj: /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/ULTRASONIC_program.c
CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj: CMakeFiles/AutonomousVehicle.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj -MF CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj.d -o CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj -c /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/ULTRASONIC_program.c

CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.i"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/ULTRASONIC_program.c > CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.i

CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.s"
	/home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc --sysroot=/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/ULTRASONIC_program.c -o CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.s

# Object files for target AutonomousVehicle.elf
AutonomousVehicle_elf_OBJECTS = \
"CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj" \
"CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj" \
"CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj" \
"CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj" \
"CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj" \
"CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj"

# External object files for target AutonomousVehicle.elf
AutonomousVehicle_elf_EXTERNAL_OBJECTS =

AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/APP.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/DIO_program.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/DISPLAY_program.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/LCD_program.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/TIMER_program.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/ULTRASONIC_program.c.obj
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/build.make
AutonomousVehicle.elf: CMakeFiles/AutonomousVehicle.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable AutonomousVehicle.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AutonomousVehicle.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AutonomousVehicle.elf.dir/build: AutonomousVehicle.elf
.PHONY : CMakeFiles/AutonomousVehicle.elf.dir/build

CMakeFiles/AutonomousVehicle.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AutonomousVehicle.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AutonomousVehicle.elf.dir/clean

CMakeFiles/AutonomousVehicle.elf.dir/depend:
	cd /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/build/CMakeFiles/AutonomousVehicle.elf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AutonomousVehicle.elf.dir/depend

