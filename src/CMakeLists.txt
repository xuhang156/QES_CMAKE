cmake_minimum_required(VERSION 3.10)

project(src)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_subdirectory(plugins)
add_subdirectory(app)
set_property(DIRECTORY APPEND PROPERTY CMAKE_ORDERED_DIRECTORIES TRUE)
