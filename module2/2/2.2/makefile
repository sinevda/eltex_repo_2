CC=gcc
CFLAGS=-Wall
TARGET=calculator

all: $(TARGET)

$(TARGET): main.c func.c func.h
	$(CC) $(CFLAGS) -o $(TARGET) main.c func.c

clean:
	rm -f $(TARGET)

.PHONY: all clean