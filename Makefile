CC = gcc
CFLAGS = -Wall -Werror
SRC = $(wildcard src/*.c) main.c
OUT = main

$(OUT): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm main

test:
	./main