CC = gcc
CFLAGS = -c -fPIC -Wall
LDFLAGS = -shared
RM = rm -f

all: calculator

func.so: sum.o dev.o diff.o mult.o
	$(CC) $(LDFLAGS) sum.o dev.o diff.o mult.o -o func.so

sum.o: sum.c
	$(CC) $(CFLAGS) -rdynamic sum.c -o sum.o

dev.o: dev.c
	$(CC) $(CFLAGS) -rdynamic dev.c -o dev.o

diff.o: diff.c
	$(CC) $(CFLAGS) -rdynamic diff.c -o diff.o

mult.o: mult.c
	$(CC) $(CFLAGS) -rdynamic mult.c -o mult.o

calc.o: calc.c
	$(CC) -c -rdynamic -ldl calc.c -o calc.o

calculator: calc.o func.so
	$(CC) calc.o -Wl,-rpath=. func.so -o calculator -ldl

clean:
	$(RM) sum.o dev.o diff.o mult.o calc.o func.so calculator

.PHONY: all clean