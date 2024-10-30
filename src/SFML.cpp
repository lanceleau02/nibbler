/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:16:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 09:59:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SFML.hpp"

SFML::SFML() {}

// SFML::SFML(const SFML& other) {}

// SFML& SFML::operator=(const SFML& other) { return other; }

SFML::~SFML() {}

void	SFML::createWindow() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Nibbler (SFML)");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}
	window.close();
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new SFML();
	}
}
