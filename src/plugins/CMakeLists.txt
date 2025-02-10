cmake_minimum_required(VERSION 3.10)

project(plugins)

add_subdirectory(coreplugin)
add_subdirectory(helloworld)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT helloworld)
