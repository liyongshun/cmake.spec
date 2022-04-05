# 目标

## add_executable

```cmake
add_executable(targetName 
  [EXCLUDE_FROM_ALL] 
	source1 [source2 ...]
)
```

选项`EXCLUDE_FROM_ALL`制式，该目标不在`make all`目标之内。


## add_library

```cmake
add_library(targetName [STATIC | SHARED | MODULE]  
  [EXCLUDE_FROM_ALL] 
  source1 [source2 ...]
)
```

- 如果未指定，由`BUILD_SHARED_LIBS`指定；
- `MODULE`表示在运行时动态加载，而不是连接到可执行程序或库的共享库。常用于插件或可选组件。









