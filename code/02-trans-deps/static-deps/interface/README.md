
```
 Properties for TARGET bar:
   bar.INCLUDE_DIRECTORIES = "bar/include;bar/src"
   bar.INTERFACE_INCLUDE_DIRECTORIES = "bar/include"
   bar.LINK_LIBRARIES = <NOTFOUND>
   bar.INTERFACE_LINK_LIBRARIES = <NOTFOUND>
 Properties for TARGET foo:
   foo.INCLUDE_DIRECTORIES = "foo/include;foo/src"
   foo.INTERFACE_INCLUDE_DIRECTORIES = "foo/include"
   foo.LINK_LIBRARIES = <NOTFOUND>
   foo.INTERFACE_LINK_LIBRARIES = "bar"
 Properties for TARGET main:
   main.INCLUDE_DIRECTORIES = <NOTFOUND>
   main.INTERFACE_INCLUDE_DIRECTORIES = <NOTFOUND>
   main.LINK_LIBRARIES = "foo"
   main.INTERFACE_LINK_LIBRARIES = <NOTFOUND>
```

- libbar.a

```
$ cc  -Ibar/include -Ibar/src -std=c99 -o build/bar/src/bar.c.o -c bar/src/bar.c
$ ar qc build/bar/libbar.a build/bar/src/bar.c.o
$ ranlib build/bar/libbar.a
```

- libfoo.a

```
$ cc  -Ifoo/include -Ifoo/src -std=c99 -o build/foo/src/foo.c.o -c foo/src/foo.c
$ ar qc build/foo/libfoo.a build/foo/src/foo.c.o
$ ranlib build/foo/libfoo.a
```

- main

```
$ cc  -Ifoo/include -Ibar/include -std=c99 -o build/main/main.c.o -c main/main.c
$ cc build/main/main.c.o -o build/main/main build/foo/libfoo.a build/bar/libbar.a
```