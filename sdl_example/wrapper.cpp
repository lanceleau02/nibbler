#include "../SDL/include/SDL.h"
#include <iostream>

extern "C" void	createCircle(SDL_Renderer* renderer) {
	for (int w = 0; w < 100 * 2; w++) {
		for (int h = 0; h < 100 * 2; h++) {
			int dx = 100 - w;
			int dy = 100 - h;
			if ((dx*dx + dy*dy) <= (100 * 100))
				SDL_RenderDrawPoint(renderer, 100 + dx, 100 + dy);
		}
	}
}

extern "C" void createWindow() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return ;
	}

	SDL_Window* window = SDL_CreateWindow("SDL Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return ;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return ;
	}

	bool        quit = false;
	SDL_Event   event;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT)
				quit = true;
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		createCircle(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}