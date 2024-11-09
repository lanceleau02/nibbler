/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 18:07:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SDL.hpp"

SDL::SDL() : _window(nullptr), _renderer(nullptr) {}

SDL::~SDL() {}

int	SDL::handleEvents(void* r) {
	if (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) return CLOSE_WINDOW;
		if (_event.type == SDL_KEYDOWN) {
			switch (_event.key.keysym.sym) {
				case SDLK_ESCAPE:	return CLOSE_WINDOW;
				case SDLK_1:		return ONE;
				case SDLK_2:		return TWO;
				case SDLK_3:		return THREE;
				case SDLK_UP:		return UP;
				case SDLK_DOWN:		return DOWN;
				case SDLK_LEFT:		return LEFT;
				case SDLK_RIGHT:	return RIGHT;
				default:			break;
			}
		}
	}
	return -1;
}

bool	SDL::isOpen(void* r) {
	return (_window != nullptr);
}

void	SDL::centerWindow(int width, int height, void* r) {
	SDL_GetDesktopDisplayMode(0, &_displayMode);
	SDL_SetWindowPosition(_window, (_displayMode.w - width) / 2, (_displayMode.h - height) / 2);
	SDL_ShowWindow(_window);
}

void	SDL::clearWindow(void* r) {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void	SDL::closeWindow(void* r) {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void	SDL::createSquare(int x, int y, int size, const Colors& color, void* r) {
	SDL_Rect square = { x, y, size, size };
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(_renderer, &square);
	SDL_RenderDrawRect(_renderer, &square);
}

void    SDL::display(void* r) {
	SDL_RenderPresent(_renderer);
}

void*   SDL::createWindow(int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error(std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError());
	
	_window = SDL_CreateWindow("Nibbler (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SDL();
	}
}
