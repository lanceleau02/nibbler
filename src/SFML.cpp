/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:16:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/31 15:50:18 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SFML.hpp"

SFML::SFML() {}

// SFML::SFML(const SFML& other) {}

// SFML& SFML::operator=(const SFML& other) { return other; }

SFML::~SFML() {}

void	SFML::createSquare(void* r) {
	sf::RenderWindow* window = static_cast<sf::RenderWindow*>(r);
	sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
	square.setFillColor(sf::Color::Green);
	square.setPosition(350.f, 250.f);
	window->draw(square);
}

void	SFML::clearWindow(void* r) {
	sf::RenderWindow* window = static_cast<sf::RenderWindow*>(r);
	window->clear(sf::Color::Black);
}

void	SFML::display(void* r) {
	sf::RenderWindow* window = static_cast<sf::RenderWindow*>(r);
	window->display();
}

void*   SFML::createWindow() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Nibbler (SFML)");
	return static_cast<void*>(window);

	/* while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		createSquare(&window);
		window.display();
	}
	window.close(); */
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SFML();
	}
}
