CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = bin/tp02

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o bin/