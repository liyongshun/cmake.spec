cmake_minimum_required(VERSION 3.14)

project(sub_pkg VERSION 1.0)

include(CTest)
enable_testing()

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

include(external/gtest)
include(external/foo)

add_subdirectory(src)