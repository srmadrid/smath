cmake_minimum_required(VERSION 3.10)
project(smath VERSION 1.0.1)

# Set the include directories
include_directories(include)
include_directories(include/linear-algebra)

# Compile the library into a global smath.a file
file(GLOB_RECURSE SMATH_SOURCES "src/*.cpp")
add_library(smath STATIC ${SMATH_SOURCES})

# Compile the submodules into separate .a files
file(GLOB_RECURSE LINEAR_ALGEBRA_SOURCES "src/linear-algebra/*.cpp")
add_library(linear-algebra STATIC ${LINEAR_ALGEBRA_SOURCES})
target_link_libraries(linear-algebra smath)

# Set the output directories for the libraries
set_target_properties(smath PROPERTIES PREFIX "")
set_target_properties(linear-algebra PROPERTIES PREFIX "")

set_target_properties(smath PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set_target_properties(linear-algebra PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Set the output directory for the build files
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

