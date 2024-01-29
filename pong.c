#define SDL_INITS SDL_INIT_TIMER|| \
		SDL_INIT_VIDEO

#include<SDL2/SDL.h>
#include<stdio.h>

int main(){
		Uint32 ret = 0;
		Uint32 timmer = 0;
		SDL_Window *my_window = NULL;
		const char title[20] = {"MY WINDOW"};
		SDL_Renderer *my_renderer = NULL;
		int index;
		Uint32 flags = 0;

		ret = SDL_Init(SDL_INITS);
		if(ret < 0){
				perror("Init");
				exit(EXIT_FAILURE);
		}

		my_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,\
						SDL_WINDOWPOS_CENTERED,0,0,\
						SDL_WINDOW_FULLSCREEN || \
						SDL_WINDOW_ALLOW_HIGHDPI);
		if(!my_window){
				perror("Creating window");	
				SDL_QuitSubSystem(SDL_INITS);
				SDL_Quit();
				exit(EXIT_FAILURE);
		}

		index = -1;
		//flags = SDL_RENDERER_SOFTWARE;
		flags = 0;
		my_renderer = SDL_CreateRenderer(my_window, index, flags);
		if(!my_renderer){
				perror("Creating renderer");	
				SDL_DestroyWindow(my_window);
				SDL_QuitSubSystem(SDL_INITS);
				SDL_Quit();
				exit(EXIT_FAILURE);
		}
		
		ret = SDL_SetRenderDrawColor(my_renderer,200,120,120,120);
		if(ret < 0){
				perror("Drawind renderer draw color");	
				SDL_DestroyWindow(my_window);
				SDL_QuitSubSystem(SDL_INITS);
				SDL_Quit();
				exit(EXIT_FAILURE);
		}
		SDL_RenderClear(my_renderer);
		SDL_RenderPresent(my_renderer);

		printf("Shaaa dude\n");
		SDL_Delay(5000);
		//timmer = SDL_GetTicks() + 1000;
		//while(!SDL_TICKS_PASSED(SDL_GetTicks(),timmer));
		printf("Shaaa\n");

		SDL_DestroyRenderer(my_renderer);

		SDL_DestroyWindow(my_window);

		SDL_QuitSubSystem(SDL_INITS);
		SDL_Quit();
		return 0;
}
