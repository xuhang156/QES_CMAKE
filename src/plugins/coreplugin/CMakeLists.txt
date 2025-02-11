cmake_minimum_required(VERSION 3.10)

project(CorePlugin)
# 生成的动态库名称
set(TARGET_NAME core)

# 设置包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../3rdparty ${CMAKE_CURRENT_BINARY_DIR})

# 设置编译选项，添加必要的 Qt 库
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_AUTOMOC ON)

# 定义源文件和头文件
set(HEADERS
    coreplugin.h
)

set(SOURCES
    coreplugin.cpp
)
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# 设置插件类型
add_library(${TARGET_NAME} SHARED ${SOURCES} ${HEADERS} ${MOC_SOURCES})

# 链接外部库
target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui  Qt5::Widgets extensionsystem)

# 设置目标输出目录
set_target_properties(${TARGET_NAME}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/plugins
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/plugins
)
message("Library Output Directory: ${LIBRARY_OUTPUT_DIRECTORY_DEBUG}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message("Cmake modele path: ${CMAKE_MODULE_PATH}")
# 添加需要分发的文件
configure_file(coreplugin.json ${CMAKE_BINARY_DIR}/plugins/coreplugin.json COPYONLY)