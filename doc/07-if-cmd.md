# if命令

## 基本表达式

```cmake
if(<unquoted_constant | unquoted_variable | "quoted_string(empty or non-empty)">)
```

- 不带双引号的逻辑常量(unquoted_constants)：
  - 逻辑负的常量：0, FALSE, NO, N, OFF, IGNORE, -NOTFOUND, 空字符串(unquoted)
  - 逻辑正的常量：非零整数，TRUE, YES, Y, ON
- 不带双引号的变量(unquoted_variables)：
  - 如果该变量的值为逻辑负 => false
  - 如果该变量的值为逻辑正 => true
- 带双引号的字符串 => false

特殊地，**不带双引号的、且未定义的变量**，其值为""，所以为false. 

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

## 逻辑操作符

```cmake
# Logical operators
if(NOT expr)
if(expre AND expre)
if(expre OR expre)

# Example with parentheses
if(NOT (expre AND (expre OR expre)))
```

## 比较测试

```cmake
if(value1 OPERATOR value2)
```

- Numeric: LESS, GREATER, EQUAL, LESS_EQUAL, GREATER_EQUAL
- String: STRLESS, STRGREATER, STREQUAL, STRLESS_EQUAL, STRGREATER_EQUAL
- Version: VERSION_LESS, VERSION_GREATER, VERSION_EQUAL, VERSION_LESS_EQUAL, VERSION_GREATER_EQUAL

例1：

```cmake
# Valid numeric expressions, all evaluating as true
if(2 GREATER 1)
if("23" EQUAL 23)

set(val 42)
if(${val} EQUAL 42)
if("${val}" EQUAL 42)
```

例2：

```cmake
if(1.2 VERSION_EQUAL 1.2.0)
if(1.2 VERSION_LESS 1.2.3)
if(1.2.3 VERSION_GREATER 1.2 )
if(2.0.1 VERSION_GREATER 1.9.7)
if(1.8.2 VERSION_LESS 2 )
```

## 正则匹配

```cmake
if(value MATCHES regex)
```

例1：

```cmake
if("Hi from ${who}" MATCHES "Hi from (Fred|Barney).*")
  message("${CMAKE_MATCH_1} says hello")
endif()
```

## 文件测试

```cmake
if(EXISTS pathToFileOrDir)
if(IS_DIRECTORY pathToDir)
if(IS_SYMLINK fileName)
if(IS_ABSOLUTE path)
if(file1 IS_NEWER_THAN file2)
```

## 存在性测试

```cmake
if(DEFINED name)
if(COMMAND name)   # 测试command, function, macro是否存在
if(POLICY name)    # 测试CMPxxxx是否存在
if(TARGET name)    # add_executable(), add_library(), add_custom_target()
if(TEST name)      # add_test
```

例子：

```cmake
if(DEFINED var)
if(DEFINED ENV{var})
```




