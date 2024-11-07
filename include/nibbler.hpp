/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:39:31 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 20:51:49 by hsebille         ###   ########.fr       */
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

struct Colors {
    int r, g, b, a;
    
    Colors(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) {};
};

#define MIN_WIDTH	5
#define MIN_HEIGHT	5
#define MAX_WIDTH	30
#define MAX_HEIGHT	20

struct Nibbler {
    int windowWidth;
    int windowHeight;
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
