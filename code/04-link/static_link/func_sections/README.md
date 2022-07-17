## Disable -ffunction-sections

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    55: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    61: 00000000000011fa    47 FUNC    GLOBAL DEFAULT   16 bar_f2
    68: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 foo1_f2
    73: 00000000000011cb    47 FUNC    GLOBAL DEFAULT   16 bar_f1
```

## Enable -ffunction-sections

```
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-gc-sections")
```

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    39: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    52: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    66: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 bar_f1
```