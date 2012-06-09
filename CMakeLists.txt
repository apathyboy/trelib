cmake_minimum_required(VERSION 2.8.6)

project(treLib CXX)

# set the path for custom cmake scripts
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build-aux/cmake")

# include common scripts
include(GroupSourcesByFilesystem)
include(CheckIncludeFiles)

option(BUILD_TOOLS
    "Explicitly force building of tools" OFF)

find_package(ZLib REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(treLib)

if(BUILD_TOOLS)
    add_subdirectory(tools)
endif()
