# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("speech")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/lib" "${CMAKE_CURRENT_LIST_DIR}/models")

# Include sub-projects.
add_subdirectory ("src")
