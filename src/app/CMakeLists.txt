cmake_minimum_required(VERSION 3.10)

project(app)

find_package(Qt5 REQUIRED COMPONENTS Core Gui)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/
    ${CMAKE_CURRENT_SOURCE_DIR}/../plugins/
)

# 添加源文件
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(${PROJECT_NAME} 
    Qt5::Core
    Qt5::Gui
    extensionsystem
)

message("CMAKE_BINARY_DIR is: ${CMAKE_BINARY_DIR}")
# 设置输出路径
set_target_properties(${PROJECT_NAME}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
)