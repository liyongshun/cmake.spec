```
target_link_libraries(main 
  PRIVATE 
    -Wl,--whole-archive foo -Wl,--no-whole-archive
)
```

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo2.c
    43: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    58: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    62: 00000000000011fa    47 FUNC    GLOBAL DEFAULT   16 foo2_f2
    65: 0000000000001258    47 FUNC    GLOBAL DEFAULT   16 bar_f2
    72: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 foo1_f2
    75: 00000000000011cb    47 FUNC    GLOBAL DEFAULT   16 foo2_f1
    78: 0000000000001229    47 FUNC    GLOBAL DEFAULT   16 bar_f1
```

```
target_link_libraries(main 
  PRIVATE 
    foo
)
```

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    55: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    61: 00000000000011fa    47 FUNC    GLOBAL DEFAULT   16 bar_f2
    68: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 foo1_f2
    73: 00000000000011cb    47 FUNC    GLOBAL DEFAULT   16 bar_f1
```

```
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-gc-sections")

target_link_libraries(main 
  PRIVATE 
    -Wl,--whole-archive foo -Wl,--no-whole-archive
)
```

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    39: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    41: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo2.c
    53: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    67: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 bar_f1
```