/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/29 14:24:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SDL.hpp"

SDL::SDL() {}

// SDL::SDL(const SDL& other) {}

// SDL& SDL::operator=(const SDL& other) { return other; }

SDL::~SDL() {}

extern "C" {
	extern void	SDL::createWindow() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
			return ;
		}

		SDL_Window* window = SDL_CreateWindow("Nibbler (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
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
			SDL_RenderPresent(renderer);
		}
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
