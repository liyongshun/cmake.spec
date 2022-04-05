## 变量

## Host Build

CMake automatically determines the toolchain for host builds based on system introspection and defaults.

### Cache变量

- CMAKE_HOST_SYSTEM

```
set(CMAKE_HOST_SYSTEM ${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_VERSION}
```

- CMAKE_HOST_SYSTEM_NAME:

```
$ uname -s
- Linux
- Windows
- Darwin
```

- CMAKE_HOST_SYSTEM_PROCESSOR

工作原理：

```
uname -m  # Linux, Cygwin, Android
arch      # OpenBSD, or
uname -p  # Others
```

可能的值：

```
x86_64
```

- CMAKE_HOST_SYSTEM_VERSION

```
uname -r
```

## Crossing Compile

In cross-compiling scenarios, a toolchain file may be specified with information about compiler and utility paths.

### Cache变量

- CMAKE_SYSTEM

```
set(CMAKE_SYSTEM ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_VERSION})
```

- CMAKE_<LANG>_COMPILER

```
CMAKE_C_COMPILER
CMAKE_CXX_COMPILER
```

- CMAKE_<LANG>_COMPILER_ID

```
CMAKE_C_COMPILER_ID
CMAKE_CXX_COMPILER_ID
```

- CMAKE_<LANG>_COMPILER_VERSION

```
CMAKE_C_COMPILER_VERSION
CMAKE_CXX_COMPILER_VERSION
```



