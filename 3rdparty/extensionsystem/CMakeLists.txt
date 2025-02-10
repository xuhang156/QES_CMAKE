# 设置最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(extensionsystem)


# 设置 Qt 相关模块
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

# 设置库的目标
add_library(extensionsystem SHARED)
# 定义宏
target_compile_definitions(extensionsystem PRIVATE EXTENSIONSYSTEM_LIBRARY)

# 添加头文件目录
target_include_directories(extensionsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ ${CMAKE_CURRENT_BINARY_DIR})

# 添加源文件
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h")
file(GLOB_RECURSE UI_FILES "${CMAKE_CURRENT_LIST_DIR}/*.ui")
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
message("Ui files: ${UI_HEADERS} source files: ${SOURCES} heard files: ${HEADERS}")

# 将源文件和头文件添加到目标
target_sources(extensionsystem PRIVATE ${SOURCES} ${HEADERS} ${UI_HEADERS} ${MOC_SOURCES})
target_link_libraries(extensionsystem PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets utils)

set_target_properties(${PROJECT_NAME}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/
)