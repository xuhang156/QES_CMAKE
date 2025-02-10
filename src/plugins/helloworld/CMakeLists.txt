cmake_minimum_required(VERSION 3.10)

project(HelloWorldlugin)

# 设置包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../3rdparty ${CMAKE_CURRENT_BINARY_DIR})

# 设置编译选项，添加必要的 Qt 库
find_package(Qt5 REQUIRED COMPONENTS Core Gui)
set(CMAKE_AUTOMOC ON)

# 定义源文件和头文件
set(HEADERS
    helloservice.h
    helloserviceimpl.h
    helloplugin.h
)

set(SOURCES
    helloserviceimpl.cpp
    helloplugin.cpp
)
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.rc
  @ONLY)

if(WIN32)
    list(APPEND SOURCES ${CMAKE_CURRENT_BINARY_DIR}/version.rc)
endif()

message("Version rc file path: ${TSP_VERSION_MAJ} ${CMAKE_CURRENT_BINARY_DIR}/version.rc")
# 设置插件类型
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS} ${MOC_SOURCES})

# 链接外部库
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui extensionsystem)

# 设置目标输出目录
set_target_properties(${PROJECT_NAME}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
)
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
# 添加需要分发的文件
configure_file(hello.json ${CMAKE_BINARY_DIR}/plugins/hello.json COPYONLY)

