# 语言标准

## 指定project或target的语言标准

指定项目的语言标准。

```cmake
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF)
```

指定特定target的语言标准，但不具备target依赖传递能力。

```cmake
set_target_properties(foo PROPERTIES 
  C_STANDARD 99 
  C_STANDARD_REQUIRED ON 
  C_EXTENSIONS OFF
)
```

## target_compile_features

指定target的编译特性，由cmake自行指定语言标准，其优势在于可以传递target的编译特性到依赖方。

```cmake
target_compile_features(cub PUBLIC cxx_std_14)
```

查看当前系统cmake支持的语言特性。

```cmake
include(CMakePrintHelpers)

get_property(cmake_cxx_known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)

cmake_print_variables(cmake_cxx_known_features)
cmake_print_variables(CMAKE_CXX_COMPILE_FEATURES)
```