# CMake基础

## cmake_minimum_required

```cmake
cmake_minimum_required(VERSION major.minor[.patch])
```

设置`CMAKE_MINIMUM_REQUIRED_VERSION`变量。

## project

```
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>]]]
        [LANGUAGES <language-name>...])
```

- 名称

自动设置如下变量值。

```cmake
# Absolute path to the source directory for the project.
PROJECT_SOURCE_DIR, <PROJECT-NAME>_SOURCE_DIR

# Absolute path to the binary directory for the project.
PROJECT_BINARY_DIR, <PROJECT-NAME>_BINARY_DIR

# New in version 3.21. Boolean value indicating whether the project is top-level.
PROJECT_IS_TOP_LEVEL, <PROJECT-NAME>_IS_TOP_LEVEL
```

如果该项目为顶级项目(TOP_LEVEL)，则设置变量`CMAKE_PROJECT_NAME`。

- 版本

如果指定`VERSION`属性，则设置如下两个变量:

```cmake
PROJECT_VERSION, <PROJECT-NAME>_VERSION
```

如果该项目为顶级项目(TOP_LEVEL)，则设置变量`CMAKE_PROJECT_VERSION`。

- 语言列表

`LANGUAGES`属性，默认设置为`C CXX`。

## 语言标准

### 指定project或target的语言标准

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

### target_compile_features

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

## 变量

### 普通变量

```
set(varName value... [PARENT_SCOPE])
```

#### string VS. list

包含空格的值，必须是由双引号，否则默认处理为list

```cmake
set(var b c)    # "b;c"
set(var "b c")  # "b c"
```

可显式指定`;`分割多个值。

```cmake
set(var b c)    # "b;c"
set(var b;c)    # "b;c"
```

#### 多行值

变量多行值，双引号需要转义。

```cmake
set(multiLine "First line ${myVar} 
Second line with a \"quoted\" word")
```

可使用`[[ multi lines ]]`的多行表达，则无需对其内部的双引号转译，但不能实现变量替换。

```cmake
set(shellScript [=[ 
#!/bin/bash

[[ -n "${USER}" ]] && echo "Have USER" 
]=])
```

```cmake
set(shellScript 
"#!/bin/bash

[[ -n \"\${USER}\" ]] && echo \"Have USER\"
")
```

### 逻辑表达式

- 未引用的逻辑常量：
  - 逻辑负的常量：0, FALSE, NO, N, OFF, IGNORE, -NOTFOUND
  - 逻辑正的常量：非零整数，TRUE, YES, Y, ON
- 未引用的变量：
  - 如果该变量为逻辑负的常量 => false
  - 如果该变量为逻辑正的常量 => true
- 引用了的字符串 => false

特殊地，**未引用的、且未定义的变量**，其值为""，所以为false. 

```cmake
macro(assert_true exp)
  if(NOT ${exp})
    message(FATAL_ERROR "expect ${exp} be true, but got false")
  endif()
endmacro()

macro(assert_false exp)
  if(${exp})
    message(FATAL_ERROR "expect ${exp} be false, but got true")
  endif()
endmacro()

## unquoted constant(1, TRUE, YES, Y, ON) => true
assert_true(1 AND 2)
assert_true(TRUE AND True AND true)
assert_true(YES AND Yes AND yes)
assert_true(Y AND y)
assert_true(ON AND on AND On)

## unquoted constant(0, FALSE, NO, N, OFF, IGNORE, -NOTFOUND, "") => false
assert_false(0)
assert_false(false OR False OR FALSE)
assert_false(No OR no OR NO)
assert_false(N OR n)
assert_false(OFF OR off OR Off)

assert_false(IGNORE OR Ignore OR ignore)
assert_false(NOTFOUND OR NotFound OR notfound)

## unquoted variable: (N, false, off, "") => false
set(var N)
assert_false(var)

set(var false)
assert_false(var)

option(enable_xxx "enable xxx" OFF)
assert_false(enable_xxx)

set(var "")
assert_false(var)

# non_defined_var is ""
assert_false(non_defined_var)

set(var "xxx-NOTFOUND")
assert_false(var)

set(var "non-empty-value")
assert_true(var)

option(enable_yyy "enable yyy" ON)
assert_true(enable_yyy)

# quoted string => false, using STREQUAL and so on
assert_false("string")
assert_false("")

set(defined_var "non-empty-value")
assert_false("${defined_var}")

set(defined_var "")
assert_false("${defined_var}")

assert_false("${non_defined_var}")

set(defined_var "non-empty-value")
assert_false(${defined_var})
```


### 环境变量

### 缓存变量







