cmake_minimum_required(VERSION 3.26)
project(List)

set(HEADER_FILES
        List.h
)

set(SOURCE_FILES
        List.cpp
)

add_library(List_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})