#https://google.github.io/googletest/
#https://www.youtube.com/watch?v=_Kd1pew04LQ
#https://www.youtube.com/watch?v=1Q2KhIqMork&list=PLkH1REggdbJpmAxNH0atSjhZX2cRzf3B_&index=1
#https://stackoverflow.com/questions/24295876/cmake-cannot-find-googletest-required-library-in-ubuntu
#https://stackoverflow.com/questions/62910867/how-to-run-tests-and-debug-google-test-project-in-vs-code
#https://stackoverflow.com/questions/17469843/cmake-cannot-find-a-required-library?newreg=32ea5311077040eda121a40fe91d8fbf
#https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
#https://stackoverflow.com/questions/69409951/why-cant-libgtest-a-be-moved-to-a-different-location
#https://github.com/apache/tvm/issues/2374


cmake_minimum_required(VERSION 3.5)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test cpp file
add_executable(mytests mytests.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(mytests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)