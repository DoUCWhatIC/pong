#define SDL_INITS 0

#include<SDL/SDL.h>
#include<stdio.h>

int main(){
		Uint32 ret;
		ret = SDL_Init(SDL_INITS);

		return 0;
}
