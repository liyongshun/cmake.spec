# 变量

## 普通变量

```
set(varName value... [PARENT_SCOPE])
```

### string VS. list

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

### 多行值

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
