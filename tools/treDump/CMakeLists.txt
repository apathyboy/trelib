file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

add_executable(treDump
    ${SOURCES}
)

target_link_libraries(treDump
    treLib
)

if(MSVC)
    configure_file(${PROJECT_SOURCE_DIR}/build-aux/user_project.vcxproj.in
        ${CMAKE_CURRENT_BINARY_DIR}/treDump.vcxproj.user @ONLY)
endif()
