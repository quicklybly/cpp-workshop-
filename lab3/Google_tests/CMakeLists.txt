project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories("../List_lib")
add_executable(Google_Tests_run ListTest.cpp)

target_link_libraries(Google_Tests_run List_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)