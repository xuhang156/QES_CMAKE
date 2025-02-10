cmake_minimum_required(VERSION 3.10)

project(CorePlugin)

# 设置包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../3rdparty ${CMAKE_CURRENT_BINARY_DIR})

# 设置编译选项，添加必要的 Qt 库
find_package(Qt5 REQUIRED COMPONENTS Core Gui)
set(CMAKE_AUTOMOC ON)

# 定义源文件和头文件
set(HEADERS
    coreplugin.h
)

set(SOURCES
    coreplugin.cpp
)
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# 根据配置（debug 或 release）设置 DESTDIR 和链接库
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     set(DESTDIR "${CMAKE_SOURCE_DIR}/../../app/debug/plugins/")
#     link_directories(${CMAKE_SOURCE_DIR}/../../../3rdparty/extensionsystem/debug)
# else()
#     set(DESTDIR "${CMAKE_SOURCE_DIR}/../../app/debug/release/")
#     link_directories(${CMAKE_SOURCE_DIR}/../../../3rdparty/extensionsystem/release)
# endif()

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
configure_file(coreplugin.json ${CMAKE_BINARY_DIR}/plugins/coreplugin.json COPYONLY)

