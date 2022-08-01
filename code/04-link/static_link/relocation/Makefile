CFLAGS = -fno-pic
LDFLAGS = -no-pie

main:
	$(CC) $(CFLAGS) -o main.o -c main.c 
	$(CC) $(CFLAGS) -o sum.o -c sum.c
	$(CC) $(LDFLAGS) -o main main.o sum.o

clean:
	rm -rf *.o *.a *.so main