# 变量

## 变量值

### string VS. list

cmake的值包括两种类型：

- string: 
  - 不包含空格，双引号可选
  - 包含空格，双引号必选
- list
  - 空格
  - 分号

注意：包含空格的值，必须使用双引号，否则默认处理为list

```cmake
set(var b c)    # "b;c"
set(var "b c")  # "b c"
```

可显式指定`;`分割多个值。

```cmake
set(var b c)    # "b;c"
set(var b;c)    # "b;c"
```

### 多行值

变量多行值，其内转义和变量替换生效。也就是说，如果其内容包括双引号，需要转义。

```cmake
set(multiLine "First line ${myVar} 
Second line with a \"quoted\" word")
```

```
First line content
Second line with a "quoted" word
```

可使用`[[ multi lines ]]`的多行表达，转义和变量替换失效。

```cmake
set(shellScript [=[ 
#!/bin/bash

[[ -n "${USER}" ]] && echo "Have USER" 
]=])
```

如果使用字符串，则需要显式地对内部的所有双引号进行转义。

```cmake
set(shellScript 
"#!/bin/bash

[[ -n \"\${USER}\" ]] && echo \"Have USER\"
")
```

### 变量替换

未定义变量替换为空字符串。

```
set(foo ab)               # foo = "ab" 
set(bar ${foo}cd)         # bar = "abcd" 
set(baz ${foo} cd)        # baz = "ab;cd" 
set(myVar ba)             # myVar = "ba" 
set(big "${${myVar}r}ef") # big = "${bar}ef" = "abcdef" 
set(${foo} xyz)           # ab = "xyz" 
set(bar ${notSetVar})     # bar = ""
```

## 普通变量

```
set(varName value... [PARENT_SCOPE])
```

名字可包含：数字，字母，下划线，中划线，点'.'，加号'+'。

### 作用域

### 生命周期

normal variables which have a lifetime limited to the processing of the CMakeLists.txt file.

normal variables where the set() command will always overwrite a pre-existing value.

## 环境变量

set(ENV{PATH} "$ENV{PATH}:/opt/myDir")

## Cache变量

cache variables are stored in the special file called CMakeCache.txt in the build directory and they persist between CMake runs. 

Once set, cache variables remain set until something explicitly removes them from the cache.

cache variables are primarily intended as a customization point for developers. Rather than hard-coding the value in the CMakeLists.txt file as a normal variable,

### 设置值

- set command acts more like set-if-not-set when used to define cache variables.

```
set(var value... CACHE type "docstring")        # set-if-not-set
```

- set command will only overwrite a cache variable if the FORCE keyword is present. 

```
set(var value... CACHE type "docstring" FORCE)  # force set
```

- cache variables to be manipulated directly via command line options

```
cmake -D myVar:type=someValue ...
```

The behavior is essentially as though the variable was being assigned using the set() command with the CACHE and FORCE options.

### 引用变量

- normal variables take precedence over cache variables.

normal and cache variables are two separate things. It is possible to have a normal variable and a cache variable with the same name but holding different values. In such cases, CMake will retrieve the normal variable’s value rather than the cache variable when using ${myVar}, 

when setting a cache variable’s value, if that cache variable did not exist before the call to set() or if the FORCE option was used, then any normal variable in the current scope is effectively removed. 

```
set(myVar foo)                   # Local myVar
set(result ${myVar})             # result = foo
set(myVar bar CACHE STRING "")   # Cache myVar

set(result ${myVar})             # First run: result = bar 
                                 # Subsequent runs: result = foo

set(myVar fred)                  # Local myVar
set(result ${myVar})             # result = fred
```

### 类型

- BOOL
- FILEPATH
- PATH
- STRING
- INTERNAL

特殊地，对于BOOL类型，常使用option的语法糖。

```
option(optVar "docstring" [initialValue]) # initialValue is OFF by default
set(optVar initialValue CACHE BOOL "docstring")
```
