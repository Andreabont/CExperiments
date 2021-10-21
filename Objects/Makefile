CC=gcc
CFLAGS=-I. -g
DEPS = objects.h point.h
OBJ = main.o objects.o point.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

object: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

clean:
	rm *.o
	rm object

