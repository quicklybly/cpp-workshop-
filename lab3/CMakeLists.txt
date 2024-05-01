cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lab3 main.cpp
)

add_subdirectory(List_lib)
add_subdirectory(Google_tests)

include_directories(List_lib Google_tests)

target_link_libraries(List_lib gtest gtest_main)
