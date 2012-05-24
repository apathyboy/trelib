file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

add_executable(testArchive
    ${SOURCES}
)

target_link_libraries(testArchive
    treLib
    ${ZLIB_LIBRARIES}
)
