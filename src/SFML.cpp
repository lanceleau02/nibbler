/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:16:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 12:08:44 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SFML.hpp"

SFML::SFML() {}

// SFML::SFML(const SFML& other) {}

// SFML& SFML::operator=(const SFML& other) { return other; }

SFML::~SFML() {}

/* void	SFML::createSquare(sf::RenderWindow window) override {
	sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
	square.setFillColor(sf::Color::Green);
	square.setPosition(350.f, 250.f);
	window.draw(square);
} */

void	SFML::createWindow() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Nibbler (SFML)");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		// createSquare(window);
		window.display();
	}
	window.close();
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SFML();
	}
}
