project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories("../Bank_lib")
add_executable(Google_Tests_run BankTest.cpp)

target_link_libraries(Google_Tests_run Bank_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)