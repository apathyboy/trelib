file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

add_executable(treBuild
    ${SOURCES}
)

target_link_libraries(treBuild
    treLib
    ${ZLIB_LIBRARIES}
)

