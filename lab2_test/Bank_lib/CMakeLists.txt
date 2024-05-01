cmake_minimum_required(VERSION 3.26)
project(Pueque)

set(HEADER_FILES
        Pueque.h
        PuqueException.h
)

set(SOURCE_FILES
        Pueque.cpp
        PuqueException.cpp
)

add_library(Pueque_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})