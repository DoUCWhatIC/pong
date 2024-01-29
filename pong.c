#define SDL_INITS SDL_INIT_TIMER|| \
		SDL_INIT_VIDEO

#include<SDL2/SDL.h>
#include<stdio.h>

int main(){
		Uint32 ret;
		Uint32 timmer;
		SDL_Window *my_window;
		const char title[20] = {"MY WINDOW"};

		ret = SDL_Init(SDL_INITS);
		if(ret < 0){
				perror("Init");
				exit(EXIT_FAILURE);
		}

		my_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,\
						SDL_WINDOWPOS_CENTERED,0,0,\
						SDL_WINDOW_FULLSCREEN);
		if(!my_window){
				SDL_QuitSubSystem(SDL_INITS);
				SDL_Quit();
				exit(EXIT_FAILURE);
		}
		

		printf("Shaaa dude\n");
		timmer = SDL_GetTicks() + 1000;
		while(!SDL_TICKS_PASSED(SDL_GetTicks(),timmer));
		printf("Shaaa\n");

		SDL_DestroyWindow(my_window);

		SDL_QuitSubSystem(SDL_INITS);
		SDL_Quit();
		return 0;
}
