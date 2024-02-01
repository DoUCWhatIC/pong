#define SDL_INITS SDL_INIT_TIMER | \
		SDL_INIT_VIDEO
#define DELTA_T 500

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

	Uint32 time_out = 0;
	Uint32 vel_x = 0;
	Uint32 vel_y = 0;

	ret = SDL_Init(SDL_INITS);
	if(ret < 0){
		perror("Init");
		exit(EXIT_FAILURE);
	}

	my_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,\
		SDL_WINDOWPOS_CENTERED,900,900,\
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

	//making the object in the scene
	SDL_Rect left_paddle;
	left_paddle.x = 100;
	left_paddle.y = 450;
	left_paddle.w = 5;
	left_paddle.h = 25;

	SDL_Rect right_paddle;
	right_paddle.x = 800;
	right_paddle.y = 450;
	right_paddle.w = 5;
	right_paddle.h = 25;

	SDL_Rect ball;
	ball.x = 450;
	ball.y = 450;
	ball.w = 5;
	ball.h = 5;

	//drawing the objects
	SDL_SetRenderDrawColor(my_renderer,WHITE);
	draw(my_renderer,&left_paddle);
	draw(my_renderer,&right_paddle);
	draw(my_renderer,&ball);
	
	int quit = 0;

	time_out = SDL_GetTicks() + DELTA_T;
	while(!quit){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			//getting players inputs
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.scancode){
					case SDL_SCANCODE_UP:
						left_paddle.y -= 10;
						break;
					case SDL_SCANCODE_DOWN:
						left_paddle.y += 10;
						break;
					case SDL_SCANCODE_E:
						right_paddle.y -= 10;
						break;
					case SDL_SCANCODE_D:
						right_paddle.y += 10;
						break;
					case SDL_SCANCODE_Q:
						quit = 1;
						break;
				}
			}
			//drawing the stuff
			clear(my_renderer);
			draw(my_renderer, &ball);
			draw(my_renderer, &left_paddle);
			draw(my_renderer,&right_paddle);
		}
		//updating ball's velocity
		if(SDL_TICKS_PASSED(SDL_GetTicks(),time_out)){
			//check to see if we hit the ceiling or floor
			//check to see if we hit a wall
			//check to see if we hit a paddle
			ball.x += 5;
			time_out = SDL_GetTicks() + DELTA_T;
		}
	}


	//cleaning up
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	SDL_QuitSubSystem(SDL_INITS);
	SDL_Quit();
	return 0;
}
