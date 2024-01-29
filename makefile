all: pong.c
	gcc -g -o pong pong.c -lSDL2

clean: 
	rm pong
