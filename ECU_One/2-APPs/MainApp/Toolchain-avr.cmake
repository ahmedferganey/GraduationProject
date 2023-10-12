##################################################################################
#                                Important URL                                   #
##################################################################################
#https://medium.com/@stonepreston/how-to-cross-compile-a-cmake-c-application-for-the-raspberry-pi-4-on-ubuntu-20-04-bac6735d36df
#https://www.kitware.com//cross-compiling-for-raspberry-pi/
#https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling
#https://cmake.org/cmake/help/latest/manual/cmake.1.html#generate-a-project-buildsystem
#https://stackoverflow.com/questions/75968820/cmake-make-passing-isysroot-to-avr-as
#https://stackoverflow.com/questions/28026256/how-to-build-a-library-while-link-to-a-testing-executable-in-the-same-project-us
#https://github.com/crosstool-ng/crosstool-ng
#https://blog.feabhas.com/2021/07/cmake-part-1-the-dark-arts/#Cross_Compiling
#https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-toolchain
#https://crosstool-ng.github.io/docs/configuration/
#https://medium.com/@stonepreston/how-to-cross-compile-a-cmake-c-application-for-the-raspberry-pi-4-on-ubuntu-20-04-bac6735d36df
#https://www.kitware.com//cross-compiling-for-raspberry-pi/
#https://stackoverflow.com/questions/52624386/cross-compilation-of-libraries-that-dynamically-or-statically-linked-with-system
#https://gcc.gnu.org/onlinedocs/libstdc++/manual/configure.html
#https://www.quora.com/What-is-a-sysroot#:~:text=A%20sysroot%20is%20a%20directory,Simon%20Martin


##################################################################################
#                                Sets the compiler                               #
##################################################################################
#setting for Host & Target
set(CMAKE_SYSTEM_NAME                   Generic)    #mandatory
SET(CMAKE_SYSTEM_VERSION                1)
set(CMAKE_SYSTEM_PROCESSOR              avr)

set(CMAKE_HOST_SYSTEM_NAME              Linux)      
set(CMAKE_HOST_SYSTEM_PROCESSOR         x86_64)     

#the next steps must be declered
set(CMAKE_SYSROOT                       /home/ahmed-ferganey/avr/toolchain_staging/avr/avr/include)   #mandatory 
SET(CMAKE_C_COMPILER                    /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-gcc)   #mandatory
SET(CMAKE_CXX_COMPILER                  /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-g++)   #mandatory
set(CMAKE_ASM_COMPILER                  /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-g++)
set(CMAKE_OBJCOPY                       /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-objcopy)
set(CMAKE_OBJDUMP                       /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-objdump)
set(AVR_SIZE                            /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-size)
set(CMAKE_LINKER                        /home/ahmed-ferganey/avr/toolchain_staging/avr/bin/avr-ld)
set(CMAKE_C_COMPILER_FORCED             1)
set(CMAKE_CXX_COMPILER_FORCED           1)


     #where is the target environment.
     #absolute or relative path to a cmake script which sets up all the toolchain related variables mentioned above.
SET(CMAKE_FIND_ROOT_PATH                /home/ahmed-ferganey/avr/toolchain_staging/avr)

     #Search for programs only in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM   NEVER)

     #Search for libraries and headers only in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY   ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE   ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE   ONLY)


#Note that these need to be absolute paths. Now that we have a toolchain file, we can pass it to the cmake command. 
#Assuming you have a CMakeLists.txt file for your project you wish to build (creating that is outside the scope of 
#this article), you can generate the build files with the following command:
#$ cmake -B build-raspberry -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=Toolchain-RaspberryPi.cmake
#Then we can build:
#cmake --build build-raspberry/






