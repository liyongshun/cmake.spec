
## 构建类型

### 命令行的可移植

```
$ cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=DEBUG \
        -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux-arm64-toolchain.cmake
$ cmake -S . -B build/release -DCMAKE_BUILD_TYPE=RELEASE \
        -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux-arm64-toolchain.cmake
```

```
$ cmake --build build/debug --config DEBUG
$ cmake --build build/release --config RELEASE
```

### 代码可移植性

问题：对于Multi Config Generators，${CMAKE_BUILD_TYPE}为空字符串。

```
if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
  add_compile_definitions(
    DEBUG
  )
endif()
```

方案：使用生成表达式

```
add_compile_definitions(
  $<$<CONFIG:DEBUG>:DEBUG>
)
```

### 新增构建类型

```
cmake_minimum_required(VERSION 3.14)

project(04-build-type VERSION 1.0 LANGUAGES C CXX)

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
    message(FATAL_ERROR "Invalid cmake build type: ${CMAKE_BUILD_TYPE}"  
  endif()
endif()

set(CMAKE_C_FLAGS_PROFILE
  "${CMAKE_C_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "") 
set(CMAKE_CXX_FLAGS_PROFILE
  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "") 
set(CMAKE_EXE_LINKER_FLAGS_PROFILE
  "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS_PROFILE
  "${CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "")
set(CMAKE_STATIC_LINKER_FLAGS_PROFILE
  "${CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "")
set(CMAKE_MODULE_LINKER_FLAGS_PROFILE 
  "${CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO} -p" CACHE STRING "")
```


