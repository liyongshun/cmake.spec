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
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} cxx_std_11")
#
#add_definitions(
#  -DUSE_PTHREAD
#  -DUSEPCRE
#)
#
#include_directories(
#  include/public
#  include/private
#  src
#  ../util/include/public
#)
#
#set(regex_sources
#  src/regex/bitstate.cc
#  src/regex/compile.cc
#  src/regex/dfa.cc
#  src/regex/filtered_re2.cc
#  src/regex/mimics_pcre.cc
#  src/regex/nfa.cc
#  src/regex/onepass.cc
#  src/regex/parse.cc
#  src/regex/perl_groups.cc
#  src/regex/prefilter.cc
#  src/regex/prefilter_tree.cc
#  src/regex/prog.cc
#  src/regex/regex.cc
#  src/regex/regexp.cc
#  src/regex/set.cc
#  src/regex/simplify.cc
#  src/regex/stringpiece.cc
#  src/regex/tostring.cc
#  src/regex/unicode_casefold.cc
#  src/regex/unicode_groups.cc
#  ../util/src/rune.cc
#  ../util/src/strutil.cc
#)
#
#add_library(regex SHARED ${regex_sources})
#link_libraries(regex pthread)
#
#add_library(regex SHARED)
#
#target_sources(regex
#  PRIVATE
#    src/regex/regex.cc
#    # ...  
#)
#
#target_include_directories(regex
#  PUBLIC  include
#  PRIVATE src
#)
#
#target_link_libraries(regex
#  PRIVATE utils pthread
#)
#
#install(TARGETS lidar_a
#  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#)
#
#install(DIRECTORY include
#  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#)
#
#install(EXPORT libar_a_targets
#  NAMESPACE mdc::
#  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lidar_a
#)
#
#configure_package_config_file(
#  CMake/config.cmake.in
#  ${PROJECT_BINARY_DIR}/lidar_a_config.cmake
#  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lidar_a
#)
#
#install(FILES ${PROJECT_BINARY_DIR}/lidar_a_config.cmake
#  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lidar_a
#)
#
#-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
#
#add_library(util STATIC)
#
#target_sources(regex
#  PRIVATE
#    src/utils/rune.cc
#    # ...
#)
#
#target_include_directories(util
#  PUBLIC  include
#  PRIVATE src
#)
#
#
#mdc_cc_library_shared(regex
#  SRCS
#    src/*.cpp
#  CDEFS
#    USE_PCRE
#    USE_PTHREAD
#  DEPS
#    pthread
#    utils
#)
#
## Case 1: list used instead of a string 
#set(CMAKE_CXX_FLAGS -Wall -Werror)
#
## Case 2: Loss the value of Cache Variable 
#set(CMAKE_CXX_FLAGS "-Wall -Werror")
#
## Case 1: Only has an effect if the variable isn't already in the cache 
#set(CMAKE_CXX_FLAGS "-Wall -Werror" CACHE STRING "C++ flags")
#
## Case 2: Using FORCE to always update the cache variable, but this overwrites any changes a developer might make to the cache 
#set(CMAKE_CXX_FLAGS "-Wall -Werror" CACHE STRING "C++ flags" FORCE)
#
## Case 3: FORCE + append = recipe for disaster
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" CACHE STRING "C++ flags" FORCE)
#
#
## Correct 1: Preserves the cache variable contents, appends new flags safely 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
#
## Correct 2: Preserves the cache variable contents, appends new flags safely 
#string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")
#
## WARNING: '${CMAKE_CXX_FLAGS} -Wall -Werror' will append to CFLAGS or CXXFLAGS for gcc
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") 
#add_library(strictReq STATIC ...)
#add_library(relaxedReq STATIC ...)
#
## Save the original set of flags so we can restore them later 
#set(oldCxxFlags "${CMAKE_CXX_FLAGS}")
#
## This library has strong build requirements, so enforce them just for it alone 
## WARNING: This doesn't do what it may appear to do! 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") 
#add_library(strictReq STATIC ...)
#
## Less strict requirements from here, so restore the original set of compiler flags
#set(CMAKE_CXX_FLAGS "${oldCxxFlags}")
#add_library(relaxedReq STATIC ...)
#
##//Flags used by the CXX compiler during all build types.                                  
##CMAKE_CXX_FLAGS:STRING=
##
##//Flags used by the CXX compiler during DEBUG builds.
##CMAKE_CXX_FLAGS_DEBUG:STRING=-g
##
##//Flags used by the CXX compiler during MINSIZEREL builds.
##CMAKE_CXX_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG
##
##//Flags used by the CXX compiler during RELEASE builds.
##CMAKE_CXX_FLAGS_RELEASE:STRING=-O3 -DNDEBUG
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
#
#add_compile_options(
#  -Wmissing-declarations
#  -Wunused-local-typedefs
#)
#
#add_subdirectory(sub)
#
#add_executable(main main.cc)
#
#target_compile_options(main
#  PRIVATE
#    -Wconversion-null
#    -Wformat-security
#)
#
#set_source_files_properties(main.cc PROPERTIES
#  COMPILE_OPTIONS -Woverlength-strings
#)
#
#set_property(SOURCE main.cc APPEND PROPERTY
#  COMPILE_OPTIONS -Wunused-result
#)
#
##- 不带双引号的逻辑常量：大小写不敏感
##  - 0, FALSE, NO, N, OFF, IGNORE, -NOTFOUND结尾的字符串, 空字符串 => false
##  - 非零整数，TRUE, YES, Y, ON => true
#
##- 不带双引号的变量：
##  - 如果该变量的**值**为逻辑假的常量值 => false
##  - 否则 => true
##
##特殊地，**不带双引号的、且未定义的变量**，其值为空字符串，所以为false
#
##- 带双引号的字符串 => false
##- 除非字符串的值为真值常量 => true
#
#set(var1 OFF)
#set(var2 "var1")
#
#if(${var2}) # => false
#if(var2)    # => true
#
#target_include_directories(target_name PRIVATE)
#target_compile_definitions(target_name PRIVATE)
#target_compile_options(target_name PRIVATE)
#target_compile_features(target_name PRIVATE)
#target_link_directories(target_name PRIVATE)
#target_link_libraries(target_name PRIVATE)
#target_sources(target_name PRIVATE)
#
#add_library(toolkit_hdrs INTERFACE)
#
#target_include_directories(toolkit_hdrs
#  INTERFACE 
#    include
#)
#target_compile_definitions(toolkit_hdrs
#  INTERFACE 
#    COOL_FEATURE=1
#    $<$<COMPILE_FEATURES:cxx_std_11>:HAVE_CXX11>
#)
#
#add_executable(app)
#
#target_link_libraries(app 
#  PRIVATE 
#    toolkit_hdrs
#)
#
#
## regular library targets
#add_library(algo_fast STATIC)
#add_library(algo_accurate STATIC)
#add_library(algo_beta STATIC)
#
## convenience interface library
#add_library(algo_all INTERFACE)
#
#target_link_libraries(algo_all 
#  INTERFACE
#    algo_fast
#    algo_accurate
#    $<$<BOOL:${ENABLE_ALGO_BETA}>:algo_beta>
#)
#
## other targets link to the interface library
## instead of each of the real libraries
#add_executable(app)
#
#target_link_libraries(app PRIVATE algo_all)
#
#add_library(foo SHARED IMPORTED GLOBAL)
#
#set_target_properties(foo PROPERTIES
#  IMPORTED_LOCATION 
#    ${FOO_LIBS}
#  INTERFACE_INCLUDE_DIRECTORIES 
#    ${FOO_INCLUDE_DIRS}
#)
#
## imported object library for object files
#add_library(crt_objs OBJECT IMPORTED GLOBAL)
#
#set_target_properties(crt_objs PROPERTIES
#  IMPORTED_OBJECTS
#    ${CRT_DIR}/obj1.obj
#    ${CRT_DIR}/obj2.obj
#)
#
## regular executable target using imported object library.
#add_executable(app $<TARGET_SOURCES:crt_objs>)
#
#
## find imported targets from an installed package.
#find_package(soc_camera REQUIRED)
#
## define an executable that links to the imported
## library from the installed package
#add_executable(app)
#
#target_link_libraries(app 
#  PRIVATE
#    soc::camera
#)
#
#
## all targets directly available
#add_subdirectory(camera)
#
## define an executable that links to the imported
## library from the installed package
#add_executable(app)
#
#target_link_libraries(app 
#  PRIVATE
#    soc::camera
#)
#
#add_library(infra_utils SHARED)
#
#target_sources(infra_utils
#  PRIVATE
#    src/rune.cc
#    src/strutils.cc
#)
#
#target_include_directories(infra_utils
#  PUBLIC  
#    include
#  PRIVATE
#    src
#)
#
#target_link_libraries(infra_utils
#  PRIVATE infra::utils pthread
#)
#
#add_library(mdc::sensor_access::lidar_a ALIAS lidar_a)
