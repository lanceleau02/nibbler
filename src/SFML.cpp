/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:16:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 18:08:36 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SFML.hpp"

SFML::SFML() : _window(nullptr) {
	_event = sf::Event();
}

SFML::~SFML() {
	if (_window) delete _window;
}

int	SFML::handleEvents(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	
	if (_window->pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) return CLOSE_WINDOW;
		if (_event.type == sf::Event::KeyPressed) {
			switch (_event.key.code) {
				case sf::Keyboard::Escape:	return CLOSE_WINDOW;
				case sf::Keyboard::Num1:	return ONE;
				case sf::Keyboard::Num2:	return TWO;
				case sf::Keyboard::Num3:	return THREE;
				case sf::Keyboard::Up:		return UP;
				case sf::Keyboard::Down:	return DOWN;
				case sf::Keyboard::Left:	return LEFT;
				case sf::Keyboard::Right:	return RIGHT;
				default:					break;
			}
		}
	}
	return -1;
}

bool	SFML::isOpen(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	return _window->isOpen();
}

void	SFML::centerWindow(int width, int height, void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	sf::Vector2i pos((sf::VideoMode::getDesktopMode().width - width) / 2, (sf::VideoMode::getDesktopMode().height - (height + 75)) / 2);
	_window->setPosition(pos);
}

void	SFML::clearWindow(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	_window->clear(sf::Color::Black);
}

void	SFML::closeWindow(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	_window->close();
}

void	SFML::createSquare(int x, int y, int size, const Colors& color, void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	sf::RectangleShape square(sf::Vector2f((float)size, (float)size));
	square.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
	square.setPosition((float)x, (float)y);
	_window->draw(square);
}

void	SFML::display(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	_window->display();
}

void*   SFML::createWindow(int width, int height) {
	_window = new sf::RenderWindow(sf::VideoMode(width, height), "Nibbler (SFML)");
	return static_cast<void*>(_window);
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SFML();
	}
}
