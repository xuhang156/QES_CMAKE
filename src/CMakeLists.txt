cmake_minimum_required(VERSION 3.10)

project(src)

add_subdirectory(plugins)
add_subdirectory(app)
set_property(DIRECTORY APPEND PROPERTY CMAKE_ORDERED_DIRECTORIES TRUE)
