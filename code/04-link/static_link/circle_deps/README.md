
## -lfoo -lbar

```
$(CC) $(LDFLAGS) -o main main.o -L. -lfoo -lbar

/usr/bin/ld: ./libbar.a(bar.o): in function `bar_f1':
bar.c:(.text+0x32): undefined reference to `foo2_f1'
```

## -lbar -lfoo

```
$(CC) $(LDFLAGS) -o main main.o -L. -lbar -lfoo

/usr/bin/ld: ./libfoo.a(foo1.o): in function `foo1_f1':
foo1.c:(.text+0x2d): undefined reference to `bar_f1'
```

## -lfoo -lbar -lfoo

```
$(CC) $(LDFLAGS) -o main main.o -L. -lfoo -lbar -lfoo
```

## -Wl,--start-group -lfoo -lbar -Wl,--end-group

```
$(CC) $(LDFLAGS) -o main main.o -L. -Wl,--start-group -lfoo -lbar -Wl,--end-group
```

```
$ readelf -a main | grep "foo\|bar"
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo1.c
    40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS bar.c
    43: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS foo2.c
    58: 0000000000001168    52 FUNC    GLOBAL DEFAULT   16 foo1_f1
    62: 0000000000001262    47 FUNC    GLOBAL DEFAULT   16 foo2_f2
    65: 0000000000001204    47 FUNC    GLOBAL DEFAULT   16 bar_f2
    72: 000000000000119c    47 FUNC    GLOBAL DEFAULT   16 foo1_f2
    75: 0000000000001233    47 FUNC    GLOBAL DEFAULT   16 foo2_f1
    78: 00000000000011cb    57 FUNC    GLOBAL DEFAULT   16 bar_f1
```