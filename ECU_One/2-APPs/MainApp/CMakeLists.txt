##################################################################################
#                                       Info                                    #
##################################################################################
## hello, if you have a basic knowladge about CMake & ct-ng, you will find 
## some of articles, websites and a links of some pages for the documentation 
## of CMake & ct-ng. also you will find other websites will help you to create
## cmakelists integrated with your custom tool chain. it is sure you will face
## some obstacles during your journey to learn anything. but, make sure you will
## get your goal by giving your trust in allah and then continous development.
## Never Give Up..


##################################################################################
#            CMakeLists.txt for a AVR project based on the toolchain             #
##################################################################################
cmake_minimum_required(VERSION 3.20  FATAL_ERROR)



##################################################################################
#                                name your project                               #
##################################################################################
project(AutonomousVehicle LANGUAGES C CXX ASM)

file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h *.cpp *.hpp)

string(REGEX REPLACE "build/[^;]+;?" "" SRCS "${SRCS}")



##################################################################################
#                                      doxygen                                   #
##################################################################################
option(BUILD_DOC "Build Documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

##https://wiki.duke.edu/pages/viewpage.action?pageId=302815982
##https://medium.com/practical-coding/c-documentation-with-doxygen-cmake-sphinx-breathe-for-those-of-use-who-are-totally-lost-7d555386fe13
##https://cmake.org/cmake/help/latest/module/FindDoxygen.html

##################################################################################
#                   tools to be used for programming the AVR                     #
##################################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER usbasp)



##################################################################################
#                        Variables regarding the AVR chip                        #
##################################################################################
set(MCU   atmega32a)
set(F_CPU "16000000UL")
set(BAUD  9600)



##################################################################################
#                                Sets the compiler                               #
##################################################################################
#setting for Host & Target
set(CMAKE_SYSTEM_NAME                   Generic)    #mandatory

     #find CMAKE_TOOLCHAIN_FILE "optional"
set(CMAKE_TOOLCHAIN_FILE                /home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/*.cmake)


set(AVR                  /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/)
set(AVR_FIND_ROOT_PATH   /home/ahmed-ferganey/avr/toolchain_staging/avr)
set(CROSSTOOL_DIR        /home/ahmed-ferganey/avr/toolchain_staging/avr)
set(CROSSTOOL_NAME       avr)

set(AVRCPP               ${CROSSTOOL_DIR}/bin/${CROSSTOOL_NAME}-g++   )
#set(AVRC                 ${CROSSTOOL_DIR}/bin/${CROSSTOOL_NAME}-gcc   )
set(AVRSTRIP             ${AVR}avr-strip                              )
set(OBJCOPY              ${AVR}avr-objcopy                            )
set(OBJDUMP              ${AVR}avr-objdump                            )        
set(AVRSIZE              ${AVR}avr-size                               )
#set(AVRDUDE              ${AVR}avrdude                                )
set(AVRDUDE              /usr/bin/avrdude                             )
set(LD                   ${AVR}avr-ld                                 )
    
#the next steps are optional 
set(CMAKE_EXPORT_COMPILE_COMMANDS       ON)
set(CMAKE_C_EXTENSIONS                  OFF)
set(CMAKE_C_STANDARD_REQUIRED           ON)
set(CMAKE_CXX_EXTENSIONS                OFF)
set(CMAKE_CXX_STANDARD_REQUIRED         ON)
set(CMAKE_C_STANDARD                    99)
set(CMAKE_CXX_STANDARD                  11)


##################################################################################
#                       set compiler options for build types                     #
##################################################################################
set(COPT            "-Os -lm -lprintf_flt")
set(CMCU            "-mmcu=${MCU}")
set(CDEFS           "-DF_CPU=${F_CPU} -DBAUD=${BAUD}")
set(CWARNING        "-Wall")
set(CERROR          "-Werror")
set(CISO            "-pedantic-errors")
set(CCLASS          "-Wextra")
set(CCONV           "-Wconversion")
set(CCA             "-c")                                  #compiles and assembles files but doesn’t link them. 
set(CUNREACH        "-Wunreachable-code")
set(CVERSION        "-std=c++11")


set(CXX_FLAGS       ${CMCU}  ${CDEFS} ${COPT} ${CWARNING} ${CUNREACH} ${CERROR} ${CISO} ${CCLASS} ${CCONV} ${CCA})
set(CMAKE_CXX_FLAGS ${CXXFLAGS})
set(CMAKE_ASM_FLAGS ${CXXFLAGS})


##################################################################################
#                               status messages                                  #
##################################################################################
message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current MCU is set to: ${MCU}")



##################################################################################
#                      some cmake cross-compile necessities                      #
##################################################################################
if(DEFINED ENV{AVR_FIND_ROOT_PATH})
     set(CMAKE_FIND_ROOT_PATH $ENV{AVR_FIND_ROOT_PATH})
else(DEFINED ENV{AVR_FIND_ROOT_PATH})
     if(EXISTS "/home/ahmed-ferganey/avr/toolchain_staging/avr/bin")
       set(CMAKE_FIND_ROOT_PATH "/home/ahmed-ferganey/avr/toolchain_staging/avr/bin")
     else(1)
       message(FATAL_ERROR "Please set AVR_FIND_ROOT_PATH in your environment.")
     endif()
endif(DEFINED ENV{AVR_FIND_ROOT_PATH})


     ## not added automatically, since CMAKE_SYSTEM_NAME is "generic"
set(CMAKE_SYSTEM_INCLUDE_PATH "/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include")
set(CMAKE_SYSTEM_INCLUDE_PATH "/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include/util")
set(CMAKE_SYSTEM_LIBRARY_PATH "/home/ahmed-ferganey/avr/toolchain_staging/avr/avr/lib")


##################################################################################
#                       status messages for generating                           #
##################################################################################
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")



##################################################################################
#                              add_executable                                    #
##################################################################################
add_executable(${PROJECT_NAME}.elf ${SRCS})




##################################################################################
#                              add_custom_target                                 #
##################################################################################
add_custom_target(flash ALL
     DEPENDS ${PROJECT_NAME}.elf
     COMMAND ${OBJCOPY} -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
     COMMAND ${AVRSIZE} -t   ${PROJECT_NAME}.elf
     ) 

add_custom_target(burn 
     DEPENDS flash
     COMMAND ${AVRDUDE} -c ${AVR_PROGRAMMER} -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a
     ) 
#https://askubuntu.com/questions/725068/where-is-my-keyboard-mouse-and-other-hci-devices-mounted-in-linux
#avrdude -c avr910 -p m168 -b 115200 -P /dev/ttyUSB0 -U flash:w:initialload.hex:a
#        -c usbasp -p m32 -U flash:w:$(ProjectDir)Debug\$(TargetName).hex:i 


#https://www.youtube.com/watch?v=jcDS8iaYS_Q
#https://www.onworks.net/software/windows/app-winavr
#https://askubuntu.com/questions/1148019/create-a-dev-ttyusb-no-such-file-or-directory
#https://itecnote.com/tecnote/linux-identify-which-usb-device-is-dev-ttyusb0/
# $ lsusb
#https://askubuntu.com/questions/725068/where-is-my-keyboard-mouse-and-other-hci-devices-mounted-in-linux
#https://installati.one/install-avrdude-ubuntu-22-04/
#https://medium.com/@ppatil/avr-programing-using-avrdude-in-ubuntu-93734c26ad19
#https://www.quora.com/How-can-we-burn-a-program-to-an-AVR-microcontroller-on-Linux


##################################################################################
#                                  Resources                                     #
##################################################################################
#https://www.youtube.com/@moatasemelsayed6226
#https://github.com/crosstool-ng/crosstool-ng
#https://blog.feabhas.com/2021/07/cmake-part-1-the-dark-arts/#Cross_Compiling
#https://stackoverflow.com/questions/77206998/cross-compiling-with-crosstool-ng-and-cmake-missing-3rd-party-libraries
#https://stackoverflow.com/questions/27188116/cross-build-third-party-library-locations-on-linux
#https://stackoverflow.com/questions/23856544/makefile-generator-specification-at-cross-compilation-with-cmake
#https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/CrossCompiling
#https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#manual:cmake-presets(7)
#https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#macro-expansion
#https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-toolchain
#https://developer.nvidia.com/blog/building-cuda-applications-cmake/
#https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
#https://bytes.usc.edu/cs104/wiki/gcc/
#https://cmake.org/cmake/help/latest/variable/CMAKE_HOST_SYSTEM_PROCESSOR.html
#https://github.com/android/ndk/issues/912#issuecomment-464363696
#https://amgaera.github.io/blog/2014/04/10/cross-compiling-for-raspberry-pi-on-64-bit-linux/
#https://cmake.org/cmake/help/latest/manual/cmake.1.html#generate-a-project-buildsystem
#https://learn.microsoft.com/en-us/vcpkg/users/buildsystems/cmake-integration
#https://stackoverflow.com/questions/63024006/cross-compiling-with-cmake-linker-errors
#https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-toolchain
#https://crosstool-ng.github.io/docs/configuration/
#https://medium.com/@stonepreston/how-to-cross-compile-a-cmake-c-application-for-the-raspberry-pi-4-on-ubuntu-20-04-bac6735d36df
#https://www.kitware.com//cross-compiling-for-raspberry-pi/
#https://stackoverflow.com/questions/52624386/cross-compilation-of-libraries-that-dynamically-or-statically-linked-with-system
#https://gcc.gnu.org/onlinedocs/libstdc++/manual/configure.html
#https://www.quora.com/What-is-a-sysroot#:~:text=A%20sysroot%20is%20a%20directory,Simon%20Martin


#cmake -B . -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=Toolchain-avr.cmake ..


#cmake -D CMAKE_TOOLCHAIN_FILE=/home/ahmed-ferganey/Desktop/Autovehicle/crosstool-ng.cmake ..
#cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_TOOLCHAIN_FILE=$HOME/rpi/Toolchain-RaspberryPi.cmake path/to/your/project
#cmake -DCMAKE_TOOLCHAIN_FILE=/home/ahmed-ferganey/Desktop/Autovehicle/crosstool-ng.cmake  -G  "Unix Makefiles"  ..
#./ct-ng build
#/home/ahmed-ferganey/Desktop/Autovehicle/crosstool-ng/

