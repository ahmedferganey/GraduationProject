##################################################################################
#                                     Resources                                  #
##################################################################################       
    #https://www.youtube.com/watch?v=SqkV7ifLME4&list=PLQMs5svASiXOraccrnEbkd_kVHbAdC2mp&index=6&t=267s
    #https://www.youtube.com/watch?v=6Ows5uZKqGQ&list=PLQMs5svASiXOraccrnEbkd_kVHbAdC2mp&index=10
    #https://cmake.org/cmake/help/v2.8.0/cpack.html
    #https://github.com/microsoft/vscode-cmake-tools/issues/1215
    #https://github.com/microsoft/vscode-cmake-tools/labels/Feature%3A%20configure
    #https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
    #https://github.com/moatasemelsayed/CMake_Lab/blob/master/CMakeLists.txt
    #https://nnarain.github.io/2016/03/29/AVR-CMake-Toolchain.html
    #https://github.com/Helius/pwm_fan_control/blob/master/CMakeLists.txt
    #https://github.com/ptrks/CMake-avr-example/blob/master/basic_example/CMakeLists.txt
    #https://github.com/fhorinek/SkyDrop/blob/master/skydrop/CMakeLists.txt
    #https://git.ok1kvk.cz/martin.vitek/nixie-clock/-/blob/26f3f9eefaba98d1a4d805093d310c1fab782c77/CMakeLists.txt 
          #https://github.com/crosstool-ng/crosstool-ng
          #https://crosstool-ng.github.io/docs/
          #https://askubuntu.com/questions/720678/what-does-export-path-somethingpath-mean
          #https://askubuntu.com/questions/300401/how-to-fix-ct-ng-menuconfig-failed-to-create-symbolic-link-config-permission
          #https://github.com/crosstool-ng/crosstool-ng/issues/680
    #https://stackoverflow.com/questions/45933732/how-to-specify-a-compiler-in-cmake
    #https://stackoverflow.com/questions/5098360/cmake-specifying-build-toolchain
    #https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/CrossCompiling
    #https://docs.zephyrproject.org/latest/develop/toolchains/custom_cmake.html
    #https://github.com/ARMmbed/mbed-os/issues/14446
    #https://discourse.cmake.org/t/tell-cmake-where-to-find-the-compiler-by-setting-either-the-environment-variable-cc-or-the-cmake-cache-entry-cmake-asm-compiler-to-the-full-path-to-the-compiler-or-to-the-compiler-name-if-it-is-in-the-path/7342/11
    #https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-linux



##################################################################################
#            CMakeLists.txt for a AVR project based on the toolchain             #
##################################################################################
cmake_minimum_required(VERSION 3.20)
    ##https://manpages.ubuntu.com/manpages/trusty/man1/cmake.1.html



##################################################################################
#                                name your project                               #
##################################################################################
#project(AutonomusVehicle)
#project(AutonomusVehicle C CXX ASM)
project(AutonomousVehicle C CXX ASM)
    ##https://cmake.org/cmake/help/latest/command/project.html#project
file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h *.cpp *.hpp)
    #https://cmake.org/cmake/help/latest/command/file.html
#message("${SRCS}")
string(REGEX REPLACE "build/[^;]+;?" "" SRCS "${SRCS}")
#message("${SRCS}")



##################################################################################
#                                      doxygen                                   #
##################################################################################
   ##https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
   ##https://www.youtube.com/watch?v=pXCWQdG1qOQ&list=PLkH1REggdbJpG8fHZvivt-5Hlg3UZcJrK&index=18
# first we can indicate the documentation build as an option and set it to ON by default
#option(BUILD_DOC "Build Documentation" ON)
#
## check if Doxygen is installed
#find_package(Doxygen)
#if (DOXYGEN_FOUND)
#    # set input and output files
#    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
#    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#
#    # request to configure the file
#    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#    message("Doxygen build started")
#
#    # note the option ALL which allows to build the docs together with the application
#    add_custom_target( doc_doxygen ALL
#        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#else (DOXYGEN_FOUND)
#  message("Doxygen need to be installed to generate the doxygen documentation")
#endif (DOXYGEN_FOUND)




##################################################################################
#                   tools to be used for programming the AVR                     #
##################################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER usbasp)
#set(AVR_UPLOADTOOL_PORT usb)



##################################################################################
#                        Variables regarding the AVR chip                        #
##################################################################################
set(MCU   atmega32a)
set(F_CPU "16000000UL")
set(BAUD  9600)
add_definitions(-DF_CPU=${F_CPU})



##################################################################################
#                                   program names                                #
##################################################################################
    ##for default ToolChain "can not compile c++ with new standard"
#set(AVRCPP   avr-g++)
#set(AVRC     avr-gcc)
#set(AVRSTRIP avr-strip)
#set(OBJCOPY  avr-objcopy)
#set(OBJDUMP  avr-objdump)
#set(LD avr-ld)
#set(AS avr-as)
#set(AVRSIZE  avr-size)
#set(AVRDUDE  avrdude)
    ##Usage: avr-strip <option(s)> in-file(s)Removes symbols and sections from files
    ##https://www.nongnu.org/avrdude/user-manual/avrdude_3.html

        ##for Custom ToolChain "can compile c++ with new standard"
set(AVR                  "${CMAKE_CURRENT_SOURCE_DIR}/avr/bin/")
set(AVRCPP               "${AVR}avr-g++")
set(AVRC                 "${AVR}avr-gcc")
set(AVRSTRIP             "${AVR}avr-strip")
set(OBJCOPY              "${AVR}avr-objcopy")
set(OBJDUMP              "${AVR}avr-objdump")
set(AVRSIZE              "${AVR}avr-size")
set(AVRDUDE              "${AVR}avrdude")
set(LD                   "${AVR}avr-ld")



##################################################################################
#                                Sets the compiler                               #
##################################################################################
# https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-linux

#                                  First Step                                    #


# Sets the compiler
# Needs to come before the project function
set(CMAKE_SYSTEM_NAME  Generic)   ##Generic to make default compilier --> this .exe will run on cross platform
#set(CMAKE_SYSTEM_NAME Linux)
#set(CMAKE_SYSTEM_NAME avr)
    
#                                  Second Step                                  #


     ## setting default tool-chain  to make compilier --> this .exe will run on cross platform##   
#set(CMAKE_CXX_COMPILER ${AVRCPP} CACHE STRING "C++ compilier" FORCE)
#set(CMAKE_C_COMPILER   ${AVRC} CACHE STRING "C compilier" FORCE)
#set(CMAKE_OBJCOPY   ${OBJCOPY} CACHE STRING "avr-objcopy" FORCE)
#set(CMAKE_ASM_COMPILER   ${AVRC} FORCE)
#set(CMAKE_OBJDUMP      ${OBJDUMP} CACHE STRING "objdump" FORCE)
#set(AVR_SIZE           ${AVRSIZE} CACHE STRING "size"    FORCE)
#set(CMAKE_LINKER       ${LD} CACHE STRING "linker"  FORCE)
      #set(CMAKE_AR           ${}"${TOOLCHAIN_ROOT}/${TRIPLE}-ar${OS_SUFFIX}"      CACHE PATH "ar"      FORCE)
      #set(CMAKE_NM           ${}"${TOOLCHAIN_ROOT}/${TRIPLE}-nm${OS_SUFFIX}"      CACHE PATH "nm"      FORCE)
      ##set(CMAKE_STRIP        ${}"${TOOLCHAIN_ROOT}/${TRIPLE}-strip${OS_SUFFIX}"   CACHE PATH "strip"   FORCE)
      #set(CMAKE_RANLIB       ${}"${TOOLCHAIN_ROOT}/${TRIPLE}-ranlib${OS_SUFFIX}"  CACHE PATH "ranlib"  FORCE)


    ## setting custom tool-chain  to make compilier --> this .exe will run on cross platform
          ##https://discourse.cmake.org/t/tell-cmake-where-to-find-the-compiler-by-setting-either-the-environment-variable-cc-or-the-cmake-cache-entry-cmake-asm-compiler-to-the-full-path-to-the-compiler-or-to-the-compiler-name-if-it-is-in-the-path/7342/11
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/avr/bin")
set(PATH_TO_SOURCE       "${CMAKE_CURRENT_SOURCE_DIR}")
set(PATH_TO_BUILD        "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(CMAKE_CXX_COMPILER ${AVRCPP}  FORCE )
set(CMAKE_C_COMPILER   ${AVRCPP}  FORCE )
set(CMAKE_ASM_COMPILER ${AVRCPP}  FORCE )
set(CMAKE_OBJCOPY      ${OBJCOPY} FORCE )
set(CMAKE_OBJDUMP      ${OBJDUMP} FORCE )
set(AVR_SIZE           ${AVRSIZE} FORCE )
set(CMAKE_LINKER       ${LD}      FORCE )
      # avr-addr2line  avr-c++      avr-cpp           avr-g++         avr-gcc-ar      avr-gcov       avr-gdb            
      # avr-ar         avr-cc       avr-ct-ng.config  avr-gcc         avr-gcc-nm      avr-gcov-dump  avr-gdb-add-index  
      # avr-as         avr-c++filt  avr-elfedit       avr-gcc-13.2.0  avr-gcc-ranlib  avr-gcov-tool  avr-gprof          
      # avr-ld        avr-man      avr-objdump  avr-size   avr-ld.bfd    avr-nm       avr-ranlib   avr-strings
      # avr-lto-dump  avr-objcopy  avr-readelf  avr-strip
if(FALSE) # fake a block comment
#New in version 3.13.
#Uses <path-to-build> as the build tree and <path-to-source> as the source tree. The specified paths 
#may be absolute or relative to the current working directory. The source tree must contain a CMakeLists.txt file. 
#The build tree will be created automatically if it does not already exist. For example:
endif()
     


##################################################################################
#                       set compiler options for build types                     #
##################################################################################
#if(CMAKE_BUILD_TYPE MATCHES Release)
#   set(CMAKE_C_FLAGS_RELEASE "-Os")
#   set(CMAKE_CXX_FLAGS_RELEASE "-Os")
#endif(CMAKE_BUILD_TYPE MATCHES Release)
#
#if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
#   set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
#   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
#endif(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
#
#if(CMAKE_BUILD_TYPE MATCHES Debug)
#   set(CMAKE_C_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
#   set(CMAKE_CXX_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
#endif(CMAKE_BUILD_TYPE MATCHES Debug)


    ##https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#build-configurations
       ## Compiler flags
       ##set(CSTANDARD "-std=gnu99")
       ##set(CDEBUG    "-gstabs -g -ggdb")
       ##set(CWARN     "-Wall -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
       ##set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
       ##set(COPT      "-Os -lm -lprintf_flt")
       ##set(CMCU      "-mmcu=${MCU}")
       ##set(CDEFS     "-DF_CPU=${F_CPU} -DBAUD=${BAUD}")
       ##
       ##set(CFLAGS   "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING}")
       ##set(CXXFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CTUNING}")
       ##
       ##set(CMAKE_C_FLAGS   "${CFLAGS}")
       ##set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
       ##set(CMAKE_ASM_FLAGS   "${CFLAGS}")



##################################################################################
#                               status messages                                  #
##################################################################################
message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
#message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${MCU}")



##################################################################################
#                               set build type                                   #
##################################################################################
                #         in case using generator         #
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)



##################################################################################
#                      some cmake cross-compile necessities                      #
##################################################################################
     ## setting default tool-chain  to make compilier --> this .exe will run on cross platform##   
#if(DEFINED ENV{AVR_FIND_ROOT_PATH})
#    set(CMAKE_FIND_ROOT_PATH $ENV{AVR_FIND_ROOT_PATH})
#else(DEFINED ENV{AVR_FIND_ROOT_PATH})
#    if(EXISTS "/opt/local/avr")
#      set(CMAKE_FIND_ROOT_PATH "/opt/local/avr")
#    elseif(EXISTS "/usr/avr")
#      set(CMAKE_FIND_ROOT_PATH "/usr/avr")
#    elseif(EXISTS "/usr/lib/avr")
#      set(CMAKE_FIND_ROOT_PATH "/usr/lib/avr")
#    elseif(EXISTS "/usr/local/CrossPack-AVR")
#      set(CMAKE_FIND_ROOT_PATH "/usr/local/CrossPack-AVR")
#    else(EXISTS "/opt/local/avr")
#      message(FATAL_ERROR "Please set AVR_FIND_ROOT_PATH in your environment.")
#    endif(EXISTS "/opt/local/avr")
#endif(DEFINED ENV{AVR_FIND_ROOT_PATH})
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


     ## setting custom tool-chain  to make compilier --> this .exe will run on cross platform##   
if(DEFINED ENV{AVR_FIND_ROOT_PATH})
     set(CMAKE_FIND_ROOT_PATH $ENV{AVR_FIND_ROOT_PATH})
else(DEFINED ENV{AVR_FIND_ROOT_PATH})
     if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/avr/bin")
       set(CMAKE_FIND_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/avr/bin")
     else(1)
       message(FATAL_ERROR "Please set AVR_FIND_ROOT_PATH in your environment.")
     endif()
endif(DEFINED ENV{AVR_FIND_ROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

     ## not added automatically, since CMAKE_SYSTEM_NAME is "generic"
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/avr/avr/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/avr/avr/lib")



##################################################################################
#                       status messages for generating                           #
##################################################################################
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")



##################################################################################
#                    compiler options for all build types                        #
##################################################################################
add_definitions("-DF_CPU=${F_CPU}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
# http://gcc.gnu.org/onlinedocs/gcc-4.8.2/gcc/Alternate-Keywords.html#Alternate-Keywords
# [...]-pedantic and other options cause warnings for many GNU C extensions. You can prevent such warnings within
# one expression by writing __extension__ before the expression. __extension__ has no effect aside from this.[...] 
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
#add_definitions("-c")
#add_definitions("-std=gnu99")
add_definitions("-std=c++20")

#add_compile_options()

##################################################################################
#                              add_executable                                    #
##################################################################################
add_executable(${PROJECT_NAME}.elf ${SRCS})

#                           in case custom tool chain                            #

#target_include_directories(${PROJECT_NAME} PUPLIC include/)
    ##https://stackoverflow.com/questions/57671273/cmake-cannot-specify-include-directories-when-use-target-target-include-director
#~/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/avr/bin/avr-g++ main.cpp -I ~/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp/avr/avr/include/  -mmcu=atmega32a  -std=c++20
#https://cmake.org/cmake/help/latest/command/target_link_directories.html
#https://cmake.org/cmake/help/latest/command/target_include_directories.html


##################################################################################
#                              add_custom_target                                 #
##################################################################################
     ## setting default target by default tool chain##   

#add_custom_target(flash ALL
#    DEPENDS ${PROJECT_NAME}.elf
#    COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
#    ) 
#
#add_custom_target(burn 
#    DEPENDS flash
#    COMMAND avrdude.exe -c usbasp -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a
#    ) 



     ## setting custom target  by custom tool chain ##   
            #   Important for cmake generator to custom tool chain #
#  https://cmake.org/cmake/help/latest/manual/cmake.1.html#generate-a-project-buildsystem  #
#  ahmed-ferganey@ahmedferganey:~/Desktop/MyGitHub/GraduationProject/2-APPs/MainApp$ cmake -B ./build
add_custom_target(flash ALL
     DEPENDS ${PROJECT_NAME}.elf
     COMMAND OBJCOPY -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
     ) 

add_custom_target(burn 
     DEPENDS flash
     COMMAND AVRDUDE.exe -c usbasp -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a
     ) 
