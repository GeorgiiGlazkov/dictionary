CC = gcc
CFLAGS = -Wall -Werror
SRC = $(wildcard common/src/*.c) $(wildcard src/*.c) $(wildcard include/src/*.c) $(wildcard test/src/*.c) main.c
OUT = main

$(OUT): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm main

test:
	./main