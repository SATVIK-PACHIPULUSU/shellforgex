CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude

SRC = src/main.c src/shell.c src/process.c

TARGET = shellforge

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
