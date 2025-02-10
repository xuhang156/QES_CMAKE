cmake_minimum_required(VERSION 3.16)
project(3rdparty)

set(SUBDIRS
    utils
    extensionsystem
)

foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()
