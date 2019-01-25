all: main.c
	gcc -g -Wall -std=c99 -o main main.c

clean:
	rm main
