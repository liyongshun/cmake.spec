# add_subdirectory

```
add_subdirectory(sourceDir [ binaryDir ] [ EXCLUDE_FROM_ALL ])
```

If `sourceDir` is a path outside the source tree, CMake requires the `binaryDir` to be specified since a corresponding relative path can no longer be constructed automatically.

## CMAKE_CURRENT_SOURCE_DIR

The directory of the CMakeLists.txt file currently being processed by CMake. It is updated each time a new file is processed as a result of an add_subdirectory() call and is restored back again when processing of that directory is complete.

## CMAKE_CURRENT_BIANRY_DIR

The build directory corresponding to the CMakeLists.txt file currently being processed by CMake. It changes for every call to add_subdirectory() and is restored again when add_subdirectory() returns.

- Top level CMakeLists.txt

```
cmake_minimum_required(VERSION 3.0)

project(MyApp)

message("top: CMAKE_SOURCE_DIR         = ${CMAKE_SOURCE_DIR}")
message("top: CMAKE_BINARY_DIR         = ${CMAKE_BINARY_DIR}")
message("top: CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("top: CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(mysub)

message("top:   CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("top:   CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
```

- mysub/CMakeLists.txt

```
message("mysub: CMAKE_SOURCE_DIR         = ${CMAKE_SOURCE_DIR}")
message("mysub: CMAKE_BINARY_DIR         = ${CMAKE_BINARY_DIR}")
message("mysub: CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("mysub: CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
```

- 结果

```
top:   CMAKE_SOURCE_DIR         = /somewhere/src
top:   CMAKE_BINARY_DIR         = /somewhere/build
top:   CMAKE_CURRENT_SOURCE_DIR = /somewhere/src
top:   CMAKE_CURRENT_BINARY_DIR = /somewhere/build
mysub: CMAKE_SOURCE_DIR         = /somewhere/src
mysub: CMAKE_BINARY_DIR         = /somewhere/build
mysub: CMAKE_CURRENT_SOURCE_DIR = /somewhere/src/mysub
mysub: CMAKE_CURRENT_BINARY_DIR = /somewhere/build/mysub
top:   CMAKE_CURRENT_SOURCE_DIR = /somewhere/src
top:   CMAKE_CURRENT_BINARY_DIR = /somewhere/build
```