cmake_minimum_required(VERSION 3.26)
project(Bank)

set(HEADER_FILES
        Bank.h
        Account.h
        Client.h
        BankSystem.h
)

set(SOURCE_FILES
        Bank.cpp
        Account.cpp
        Client.cpp
        BankSystem.cpp
)

add_library(Bank_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})