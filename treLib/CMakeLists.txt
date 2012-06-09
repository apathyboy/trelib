file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

include_directories(
    ${ZLIB_INCLUDE_DIR}
)

add_library(treLib
    ${SOURCES}
)

target_link_libraries(treLib
    treLib
    ${ZLIB_LIBRARIES}
)
