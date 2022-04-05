cmake_minimum_required(VERSION 3.14)

project(static-deps-public VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED ON) 
set(CMAKE_C_EXTENSIONS OFF)

include(CMakePrintHelpers)

add_subdirectory(foo)
add_subdirectory(bar)
add_subdirectory(main)

cmake_print_properties(TARGETS bar foo main 
  PROPERTIES 
    INCLUDE_DIRECTORIES
    INTERFACE_INCLUDE_DIRECTORIES    
    LINK_LIBRARIES
    INTERFACE_LINK_LIBRARIES
)
