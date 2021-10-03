## foreach

```cmake
foreach(loopVar IN [LISTS listVar1 ...] [ITEMS item1 ...])
  # ...
endforeach()
```

其中，

```cmake
foreach(i IN LISTS list-var)
foreach(i IN ITEMS ${list-var})
```

```cmake
foreach(loopVar RANGE start stop [step])
```

```
foreach(loopVar RANGE upper) # foreach(loopVar RANGE 0 upper 1)
```

## while

```cmake
while(cond)
  # ...
endwhile()
```

