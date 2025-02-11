cmake_minimum_required(VERSION 3.16)
project(utils CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建静态或动态库
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/mimetypes/*.cpp" )
file(GLOB_RECURSE HEARDS "${CMAKE_CURRENT_LIST_DIR}/*.h" 
                        "${CMAKE_CURRENT_LIST_DIR}/mimetypes/*.h" 
                        "../3rdparty/optional/optional.hpp" 
                        "../3rdparty/variant/variant.hpp")
# 添加 Qt 依赖
find_package(Qt5 REQUIRED COMPONENTS Core Gui)
set(CMAKE_AUTOMOC ON)
QT5_WRAP_CPP(HEADERS_MOC ${HEARDS})

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS_MOC})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui)

# 头文件包含目录
set(UTILS_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
)

# 头文件列表
target_include_directories(${PROJECT_NAME} PUBLIC ${UTILS_INCLUDE_DIRS})

# 目标编译选项
target_compile_definitions(${PROJECT_NAME} PRIVATE UTILS_LIBRARY)
if (NOT BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE QTCREATOR_UTILS_STATIC_LIB)
endif()


# Windows 额外依赖库
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE user32 shell32 iphlpapi ws2_32)
endif()

# 目标头文件
target_sources(${PROJECT_NAME} PRIVATE ${HEARDS})
set_target_properties(${PROJECT_NAME}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
)