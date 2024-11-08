/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:39:31 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/08 10:57:18 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <raylib.h>
#include <SDL2/SDL.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <termios.h>
#include <vector>
#include <deque>
#include <chrono>
#include <random>

#define SQUARE_SIZE		50

#define NIBBLER_GREEN	Colors(0, 255, 0, 255)
#define NIBBLER_RED		Colors(255, 0, 0, 255)
#define NIBBLER_BLUE	Colors(0, 0, 255, 255)
#define NIBBLER_ORANGE	Colors(255, 165, 0, 255)

#define MIN_WIDTH	5
#define MIN_HEIGHT	5
#define MAX_WIDTH	20
#define MAX_HEIGHT	20

struct Nibbler {
	int windowWidth;
	int windowHeight;
};

struct Colors {
	int r, g, b, a;
	
	Colors(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) {};
};

enum Keys {
	CLOSE_WINDOW,
	ONE,
	TWO,
	THREE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum Libraries {
	NO_LIB,
	RAYLIB_LIB,
	SDL_LIB,
	SFML_LIB
};

class UsageException : public std::invalid_argument {
public:
	explicit UsageException(const std::string& message, const std::string& usage)
		: std::invalid_argument(message), usageMessage(usage) {}

	const std::string& getUsageMessage() const { return usageMessage; }

private:
	std::string usageMessage;
};

#include "ILibraries.hpp"
#include "Game.hpp"

class ILibraries;
class Game;

using createLibraryInstance_t = ILibraries* (*)();

createLibraryInstance_t	loadSymbol(void* handle);
void					openLibrary(void** handle, const std::string& library);
void					switchLibrary(int windowWidth, int windowHeight, ILibraries*& libraryInstance, void*& handle, void*& renderer, const std::string& libraryName);
void					parsing(Nibbler& nibbler, char* w, char* h);
