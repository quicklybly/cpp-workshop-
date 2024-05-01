cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(main.cpp
        Bank_lib/Bank.cpp)

add_subdirectory(Bank_lib)
add_subdirectory(Google_tests)

include_directories(Bank_lib Google_tests)

target_link_libraries(Bank_lib gtest gtest_main)
