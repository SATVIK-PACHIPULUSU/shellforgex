CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude

SRC = src/main.c src/shell.c src/process.c src/parser.c src/builtin.c src/history.c src/signals.c src/pipeline.c src/redirection.c src/jobs.c

TARGET = shellforge

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
