## CMake输出

```
 Properties for TARGET bar:
   bar.INCLUDE_DIRECTORIES = "bar/include;bar/src"
   bar.INTERFACE_INCLUDE_DIRECTORIES = "bar/include"
   bar.COMPILE_DEFINITIONS = "PUBLIC_BAR=1;PRIVATE_BAR=3"
   bar.INTERFACE_COMPILE_DEFINITIONS = "PUBLIC_BAR=1;INTERFACE_BAR=2"
   bar.LINK_LIBRARIES = <NOTFOUND>
   bar.INTERFACE_LINK_LIBRARIES = <NOTFOUND>
 Properties for TARGET foo:
   foo.INCLUDE_DIRECTORIES = "foo/include;foo/src"
   foo.INTERFACE_INCLUDE_DIRECTORIES = "foo/include"
   foo.COMPILE_DEFINITIONS = <NOTFOUND>
   foo.INTERFACE_COMPILE_DEFINITIONS = <NOTFOUND>
   foo.LINK_LIBRARIES = <NOTFOUND>
   foo.INTERFACE_LINK_LIBRARIES = "bar"
 Properties for TARGET main:
   main.INCLUDE_DIRECTORIES = <NOTFOUND>
   main.INTERFACE_INCLUDE_DIRECTORIES = <NOTFOUND>
   main.COMPILE_DEFINITIONS = <NOTFOUND>
   main.INTERFACE_COMPILE_DEFINITIONS = <NOTFOUND>
   main.LINK_LIBRARIES = "foo;bar"
   main.INTERFACE_LINK_LIBRARIES = <NOTFOUND>
```

## 编译命令

```
$ mkdir -p build/{bar/src,foo/src,main}
```

```
$ cc -DPRIVATE_BAR=3 -DPUBLIC_BAR=1 -Ibar/include -Ibar/src  -std=c99 -o build/dir/src/bar.c.o   -c bar/src/bar.c
```

```
$ cc  -Ifoo/include -Ifoo/src  -std=c99 -o build/dir/src/foo.c.o   -c foo/src/foo.c
```

```
$ cc -DINTERFACE_BAR=2 -DPUBLIC_BAR=1 -Ifoo/include -Ibar/include  -std=c99 -o build/dir/main.c.o   -c main/main.c
$ cc    build/dir/main.c.o build/dir/src/foo.c.o build/dir/src/bar.c.o  -o build/main/main
```