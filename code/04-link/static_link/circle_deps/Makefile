main: foo bar
	$(CC) $(CFLAGS) -o main.o -c main.c
	$(CC) $(LDFLAGS) -o main main.o -L. -Wl,--start-group -lfoo -lbar -Wl,--end-group

# main: foo bar
# 	$(CC) $(CFLAGS) -o main.o -c main.c
# 	$(CC) $(LDFLAGS) -o main main.o -L. -lfoo -lbar -lfoo

foo:
	$(CC) $(CFLAGS) -o foo1.o -c foo1.c
	$(CC) $(CFLAGS) -o foo2.o -c foo2.c
	ar qc libfoo.a foo1.o foo2.o
	ranlib libfoo.a

bar:
	$(CC) $(CFLAGS) -o bar.o -c bar.c
	ar qc libbar.a bar.o
	ranlib libbar.a

clean:
	rm -rf *.o *.a *.so main