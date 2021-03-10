RM  =   -rm
CFLAGS = -Wall -g

all: testInput

testInput: testInput.c inputHandler.o
	gcc $(CFLAGS) testInput.c inputHandler.o -o testInput.exe

inputHandler.o: inputHandler.c inputHandler.h
	gcc $(CFLAGS) -c inputHandler.c

clean:
	$(RM) *.o  *~
