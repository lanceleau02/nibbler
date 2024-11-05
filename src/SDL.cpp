/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 15:13:53 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SDL.hpp"

SDL::SDL() {}

// SDL::SDL(const SDL& other) {}

// SDL& SDL::operator=(const SDL& other) { return other; }

SDL::~SDL() {}

void	SDL::createSquare(void* r) {
	SDL_Rect square = { 350, 250, 100, 100 };
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(_renderer, &square);
	SDL_RenderDrawRect(_renderer, &square);
}

void    SDL::clearWindow(void* r) {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void	SDL::closeWindow(void* r) {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void    SDL::display(void* r) {
	SDL_RenderPresent(_renderer);
}

bool	SDL::isOpen(void* r) {
	return (_window != nullptr);
}

int	SDL::handleEvents(void* r) {
	SDL_Event   event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
			return CLOSE_WINDOW;
		}
	}
	return -1;
}

void*   SDL::createWindow() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	_window = SDL_CreateWindow("Nibbler (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
	if (!_window) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return nullptr;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return nullptr;
	}
	return static_cast<void*>(_window);
}

void    SDL::centerWindow(void* r) {
    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);
    SDL_SetWindowPosition(_window, (dm.w - 500) / 2, (dm.h - 500) / 2);
    SDL_ShowWindow(_window);
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SDL();
	}
}
