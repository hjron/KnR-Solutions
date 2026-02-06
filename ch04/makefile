CC=gcc
CFLAGS=-I.
DEPS = calc.h
OBJ = main.o getop.o getch.o stack.o atof.o

# $@ put the output of the compilation in the file named on the left side of :
# $^ refers to the file named on the right side of :
# $< is the first item in the DEPS list

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean clobber

clean:
	rm -f *.o

clobber:
	rm -f *.o calc
