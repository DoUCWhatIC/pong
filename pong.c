#define SDL_INITS SDL_INIT_TIMER|| \
		SDL_INIT_VIDEO

#define PINK 200,120,120,120
#define WHITE 255,255,255,120

#include<SDL2/SDL.h>
#include<stdio.h>

void clear(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer,PINK);
	SDL_RenderClear(renderer);
}
		
void draw(SDL_Renderer *renderer, SDL_Rect *rect){
	SDL_SetRenderDrawColor(renderer,WHITE);
	SDL_RenderFillRect(renderer,rect);
	SDL_RenderPresent(renderer);
}

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
	flags = 0;
	my_renderer = SDL_CreateRenderer(my_window, index, flags);
	if(!my_renderer){
		perror("Creating renderer");	
		SDL_DestroyWindow(my_window);
		SDL_QuitSubSystem(SDL_INITS);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	
	ret = SDL_SetRenderDrawColor(my_renderer,PINK);
	if(ret < 0){
		perror("Drawind renderer draw color");	
		SDL_DestroyWindow(my_window);
		SDL_QuitSubSystem(SDL_INITS);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_RenderClear(my_renderer);

	SDL_Rect my_rect;
	my_rect.x = 150;
	my_rect.y = 250;
	my_rect.w = 5;
	my_rect.h = 25;

	SDL_SetRenderDrawColor(my_renderer,WHITE);
	draw(my_renderer,&my_rect);
	
	int quit = 0;
	while(!quit){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.scancode){
					case SDL_SCANCODE_UP:
						my_rect.y -= 10;
						break;
					case SDL_SCANCODE_DOWN:
						my_rect.y += 10;
						break;
					case SDL_SCANCODE_LEFT:
						my_rect.x -= 10;
						break;
					case SDL_SCANCODE_RIGHT:
						my_rect.x += 10;
						break;
					case SDL_SCANCODE_Q:
						quit = 1;
						break;
				}
			}
			clear(my_renderer);
			draw(my_renderer, &my_rect);
		}
	}


	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	SDL_QuitSubSystem(SDL_INITS);
	SDL_Quit();
	return 0;
}
