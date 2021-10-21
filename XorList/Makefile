CC=gcc
CFLAGS=-I. -g
DEPS = base_list.h list.h
OBJ = main.o base_list.o list.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

clean:
	rm *.o
	rm list
