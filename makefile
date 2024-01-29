all: pong.c
	gcc -g -o pong -lSDL2

clean: 
	rm pong
