/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:16:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 15:43:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SFML.hpp"

SFML::SFML() : _window(nullptr) {
	_event = sf::Event();
}

SFML::SFML(const SFML& other) : _window(other._window), _event(other._event) {
	*this = other;
}

SFML& SFML::operator=(const SFML& other) {
	if (this != &other) {
		_window = other._window;
		_event = other._event;
	}
	return *this;
}

SFML::~SFML() {
	if (_window) delete _window;
}

int	SFML::handleEvents(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	
	if (_window->pollEvent(_event)) {
		if (_event.type == sf::Event::Closed || (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)) return CLOSE_WINDOW;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Num1) return ONE;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Num2) return TWO;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Num3) return THREE;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up) return UP;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down) return DOWN;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Left) return LEFT;
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Right) return RIGHT;
	}
	return -1;
}

bool	SFML::isOpen(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	return _window->isOpen();
}

void	SFML::centerWindow(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	sf::Vector2i pos((sf::VideoMode::getDesktopMode().width - _windowWidth) / 2, (sf::VideoMode::getDesktopMode().height - (_windowHeight + 75)) / 2);
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

void	SFML::createSquare(int x, int y, int width, int height, const Colors& color, void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	sf::RectangleShape square(sf::Vector2f((float)width, (float)height));
	square.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
	square.setPosition((float)x, (float)y);
	_window->draw(square);
}

void	SFML::display(void* r) {
	_window = static_cast<sf::RenderWindow*>(r);
	_window->display();
}

void*   SFML::createWindow() {
	_window = new sf::RenderWindow(sf::VideoMode(_windowWidth, _windowHeight), "Nibbler (SFML)");
	return static_cast<void*>(_window);
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SFML();
	}
}
