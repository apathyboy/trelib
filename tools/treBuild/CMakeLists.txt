file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

add_executable(treBuild
    ${SOURCES}
)

target_link_libraries(treBuild
    treLib
)

if(MSVC)
    configure_file(${PROJECT_SOURCE_DIR}/build-aux/user_project.vcxproj.in
        ${CMAKE_CURRENT_BINARY_DIR}/treBuild.vcxproj.user @ONLY)
endif()

