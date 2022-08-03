cmake_minimum_required(VERSION 3.14)

project(01-build-type VERSION 1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

if(CMAKE_CONFIGURATION_TYPES) 
  if(NOT "Profile" IN_LIST CMAKE_CONFIGURATION_TYPES)
    list(APPEND CMAKE_CONFIGURATION_TYPES Profile) 
  endif() 
else() 
  set(allow_build_types Debug Release RelWithDebInfo MinSizeRel Profile) 
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allow_build_types}")
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
  elseif(NOT CMAKE_BUILD_TYPE IN_LIST allow_build_types)
    message(FATAL_ERROR "Invalid cmake build type: ${CMAKE_BUILD_TYPE}")
  endif()
endif()

set(CMAKE_C_FLAGS_PROFILE
  "${CMAKE_C_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage" CACHE STRING "" FORCE
) 

set(CMAKE_CXX_FLAGS_PROFILE
  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage")

set(CMAKE_EXE_LINKER_FLAGS_PROFILE
  "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage")

set(CMAKE_SHARED_LINKER_FLAGS_PROFILE
  "${CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage")

set(CMAKE_STATIC_LINKER_FLAGS_PROFILE
  "${CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage")

set(CMAKE_MODULE_LINKER_FLAGS_PROFILE 
  "${CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO} -fprofile-arcs -ftest-coverage")

add_executable(main main.cc)