foo:
	$(CC) -fPIC -o foo.o -c foo.c
	$(CC) -shared -o libfoo.so foo.o

main: foo
	$(CC) -o main.o -c main.c
	$(CC) main.o -o main ./libfoo.so

clean:
	rm -rf *.o *.a *.so main