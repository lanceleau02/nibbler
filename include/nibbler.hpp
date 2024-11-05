/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:39:31 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 10:59:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

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

#define MIN_WIDTH	800
#define MIN_HEIGHT	600
#define MAX_WIDTH	1920
#define MAX_HEIGHT	1080

enum Keys {
	CLOSE_WINDOW
};

class UsageException : public std::invalid_argument {
public:
	explicit UsageException(const std::string& message, const std::string& usage)
		: std::invalid_argument(message), usageMessage(usage) {}

	const std::string& getUsageMessage() const { return usageMessage; }

private:
	std::string usageMessage;
};

#endif