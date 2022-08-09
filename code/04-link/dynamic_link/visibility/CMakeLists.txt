cmake_minimum_required(VERSION 3.14)

project(pub_pkg VERSION 1.0)

include(GenerateExportHeader)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

include(CTest)
enable_testing()

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

include(external/gtest)

set(CMAKE_C_VISIBILITY_PRESET       hidden)
set(CMAKE_CXX_VISIBILITY_PRESET     hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

add_subdirectory(src)
add_subdirectory(test)