# 语言标准

## 指定project的语言标准

指定项目的语言标准，将设置范围内所有Target语言标准的默认属性。

```cmake
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF)
```

## set_target_properties：设置target的默认属性

指定特定target的语言标准，但不具备target依赖传递能力。

```cmake
set_target_properties(foo PROPERTIES 
  CXX_STANDARD 11 
  CXX_STANDARD_REQUIRED ON 
  CXX_EXTENSIONS OFF
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