# 条件表达式

```
if(cond)
elseif(cond)
while(cond)
```

求值优先级：

1. 内部嵌套的`()`
2. 一元测试：EXISTS, COMMAND, DEFINED等
3. 二元测试：EQUAL, LESS, LESS_EQUAL, GREATER, GREATER_EQUAL等
4. NOT
5. AND
6. OR

一个条件表达式可由基本的逻辑常量表达式，或复合的逻辑条件表达式组成。

## 基本表达式

```cmake
if(<unquoted_constant>)
```

- 不带双引号的逻辑常量：大小写不敏感
  - 0, FALSE, NO, N, OFF, IGNORE, -NOTFOUND结尾的字符串, 空字符串 => false
  - 非零整数，TRUE, YES, Y, ON => true

```cmake
if(<unquoted_variable>)
```

- 不带双引号的变量：
  - 如果该变量的**值**为逻辑假的常量值 => false
  - 否则 => true

特殊地，**不带双引号的、且未定义的变量**，其值为空字符串，所以为false. 

```cmake
if(<quoted_string>)
```

- 带双引号的字符串 => false
- 除非字符串的值为真值常量 => true


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

```cmake
set(var1 OFF)
set(var2 "var1")

if(${var2}) # => false
if(var2)    # => true
```

## 逻辑操作符

```cmake
if(NOT <cond>)
if(<cond1> AND <cond2>)
if(<cond1> OR <cond2>)
```

## 比较测试

```cmake
if(<unquoted_variable|quoted_string> OPERATOR <unquoted_variable|quoted_string>)
```

如果使用`unquoted_variable`，则自动使用变量的值。操作符包括如下三类：

- Numeric: LESS, GREATER, EQUAL, LESS_EQUAL, GREATER_EQUAL
- String: STRLESS, STRGREATER, STREQUAL, STRLESS_EQUAL, STRGREATER_EQUAL
- Version: VERSION_LESS, VERSION_GREATER, VERSION_EQUAL, VERSION_LESS_EQUAL, VERSION_GREATER_EQUAL

例1：

```cmake
# Valid numeric expressions, all evaluating as true
if(2 GREATER 1)
if("23" EQUAL 23)

set(val 42)
if(val EQUAL 42)
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
if(<unquoted_variable|quoted_string> MATCHES regex)
```

例1：

```cmake
if("Hi from ${who}" MATCHES "Hi from (Fred|Barney).*")
  message("${CMAKE_MATCH_1} says hello")
endif()
```

## 文件测试

```cmake
if(EXISTS path-to-file-or-directory)
if(IS_DIRECTORY path-to-directory)
if(IS_SYMLINK file-name)
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

## 包含测试

```cmake
if(<unquoted_variable|quoted_string> IN_LIST list-var)
```
