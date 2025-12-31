CC = gcc
CFLAGS = -Wall -Werror
SRC = $(wildcard common/src/*.c) $(wildcard src/*.c) $(wildcard test/src/*.c) main.c
OUT = dictionary

$(OUT): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm $(OUT)