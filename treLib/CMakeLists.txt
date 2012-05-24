file(GLOB_RECURSE SOURCES *.h *.hpp *.cpp *.cc)

GroupSourcesByFilesystem("${SOURCES}")

include_directories(
    ${ZLIB_INCLUDE_DIRS}
)

add_library(treLib
    ${SOURCES}
)
