
# project

```cmake
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>]]]
        [LANGUAGES <language-name>...])
```

## 名称

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

## 版本

如果指定`VERSION`属性，则设置如下两个变量:

```cmake
PROJECT_VERSION, <PROJECT-NAME>_VERSION
```

如果该项目为顶级项目(TOP_LEVEL)，则设置变量`CMAKE_PROJECT_VERSION`。

## 语言列表

`LANGUAGES`属性，默认为`C CXX`。

## Example

