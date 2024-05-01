cmake_minimum_required(VERSION 3.26)
project(Bank)

set(HEADER_FILES
        Bank.h
)

set(SOURCE_FILES
        Bank.cpp
)

add_library(Bank_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})