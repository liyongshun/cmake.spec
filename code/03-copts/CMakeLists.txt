cmake_minimum_required(VERSION 3.14)

project(03-copts VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_compile_options(
  -Wmissing-declarations
  -Wunused-local-typedefs
)

add_subdirectory(sub)
