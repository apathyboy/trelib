file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

include_directories(
    ${Boost_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIR}
)

add_library(treLib
    ${SOURCES}
)

target_link_libraries(treLib
    treLib
    ${Boost_LIBRARIES}
    ${ZLIB_LIBRARY_RELEASE}
)
