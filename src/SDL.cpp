/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/06 17:51:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SDL.hpp"

SDL::SDL() : _window(nullptr), _renderer(nullptr) {}

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
	if (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT || (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_ESCAPE)) return CLOSE_WINDOW;
		if (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_1) return ONE;
		if (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_2) return TWO;
		if (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_3) return THREE;
	}
	return -1;
}

void*   SDL::createWindow() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error(std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError());
    
	_window = SDL_CreateWindow("Nibbler (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
	if (!_window) {
		SDL_Quit();
		throw std::runtime_error(std::string("the window could not be created! SDL_Error: ") + SDL_GetError());
    }

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer) {
		SDL_DestroyWindow(_window);
		SDL_Quit();
		throw std::runtime_error(std::string("the renderer could not be created! SDL_Error: ") + SDL_GetError());
	}
	return static_cast<void*>(_window);
}

void    SDL::centerWindow(void* r) {
	SDL_GetDesktopDisplayMode(0, &_displayMode);
	SDL_SetWindowPosition(_window, (_displayMode.w - _windowWidth) / 2, (_displayMode.h - _windowHeight) / 2);
	SDL_ShowWindow(_window);
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SDL();
	}
}
