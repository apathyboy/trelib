
cmake_minimum_required(VERSION 3.10)

project(treLib VERSION 1.0.0 LANGUAGES C CXX)

find_package(ZLIB REQUIRED)

# lib

add_library(treLib STATIC
    treLib/md5.c
    treLib/treArchive.cpp
    treLib/treClass.cpp
    treLib/treDataBlock.cpp
    treLib/treFileRecord.cpp
)

add_library(treLib::treLib ALIAS treLib)

target_include_directories(treLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/treLib
)

target_link_libraries(treLib PRIVATE ZLIB::ZLIB)

# executables

add_executable(testArchive tools/testArchive/testArchive.cpp)
target_link_libraries(testArchive treLib)

add_executable(treBuild tools/treBuild/treBuild.cpp)
target_link_libraries(treBuild treLib)

add_executable(treDump tools/treDump/treDump.cpp)
target_link_libraries(treDump treLib)

# installation

include(GNUInstallDirs)

install(
    TARGETS
        testArchive
        treBuild
        treDump
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/treLib)

install(
    TARGETS
        treLib
    EXPORT
        treLibTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT treLibTargets
    FILE treLibTargets.cmake
    NAMESPACE treLib::
    DESTINATION ${INSTALL_CONFIGDIR}
)

install(DIRECTORY treLib/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/treLib
    FILES_MATCHING PATTERN "*.h*"
)

# ConfigVersion file

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/treLibConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/treLibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/treLibConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/treLibConfig.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/treLibConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)
