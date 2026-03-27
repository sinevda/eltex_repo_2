CC=gcc
FLAGS=-Wall
TARGET=phonebook

all:$(TARGET)

$(TARGET): pbook.c func_book.h func_book.c
	$(CC) $(FLAGS) -g -o $(TARGET) func_book.c pbook.c

clean:
	rm -f $(TARGET)

.PHONY: all clean