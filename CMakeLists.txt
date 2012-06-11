cmake_minimum_required(VERSION 2.8.6)

project(treLib CXX)

# set the path for custom cmake scripts
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build-aux/cmake")

# include common scripts
include(GroupSourcesByFilesystem)
include(CheckIncludeFiles)

option(BUILD_TRELIB_TOOLS
    "Explicitly force building of tools" OFF)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(AdditionalBoostLibs regex)
endif()

if(MSVC)
    add_definitions (/D BOOST_ALL_DYN_LINK)
    message(STATUS "BOOST: Enable dynamic linking")
    
    add_definitions(/D BOOST_ALL_NO_LIB)
    message(STATUS "BOOST: Disable automatic linking")
endif()

# Use the static/multithreaded libraries.
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost 1.49.0 COMPONENTS filesystem thread ${AdditionalBoostLibs} REQUIRED)
find_package(ZLib REQUIRED)

if(MSVC)
	get_filename_component(ZLIB_DLL_PATH ${ZLIB_LIBRARY_RELEASE} PATH)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(treLib)

if(BUILD_TRELIB_TOOLS)
    add_subdirectory(tools)
endif()
