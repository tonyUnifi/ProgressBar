cmake_minimum_required(VERSION 4.0)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ProgressBar main.cpp
        FileLoader.h
        FileLoader.cpp
        ProgressBar.h
        ProgressBar.cpp
        Observer.h
        Observer.cpp
        Subject.h
        Subject.cpp)

target_link_libraries(ProgressBar
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

