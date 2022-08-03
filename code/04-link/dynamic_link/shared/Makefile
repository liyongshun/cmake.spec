main: foo
	$(CC) -o main.o -c main.c
	$(CC) main.o -o main -Wl,-rpath,$(PWD) libfoo.so

foo:
	$(CC) -fPIC -o foo.o -c foo.c
	$(CC) -fPIC -shared -o -Wl,-soname,libfoo.so -o libfoo.so foo.o

clean:
	rm -rf *.o *.a *.so main