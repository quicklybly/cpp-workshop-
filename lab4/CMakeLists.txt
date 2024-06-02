cmake_minimum_required(VERSION 3.26)
project(lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(
        lab4
        main.cpp
        MainWindow.h
        MainWindow.cpp
        MainWindowModel.h
        MainWindowModel.cpp
        Url.h
        Url.cpp
        ui_mainwindow.h
)
target_link_libraries(lab4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

