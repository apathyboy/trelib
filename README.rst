===========================================================================================
treLib - A general purpose library for working with Star Wars Galaxies game client archives
===========================================================================================

This is a fork of the xunil treLib project primarily meant as a learning tool for myself as well as to preserve the original code.

Build Instructions
------------------

treLib now uses CMake to generate build files. Run the following commands from a command prompt inside the project directory.

::

    cmake -E make_directory build
    cd build
    cmake ..
    cmake --build .
    
.. note::

    treLib depends on zlib for compression/decompression. To specify a custom location for zlib use the -DZLIB_ROOT=<PATH> flag when generating the build files.
    
    ::
    
        cmake -DZLIB_ROOT=/opt/local/zlib ..
