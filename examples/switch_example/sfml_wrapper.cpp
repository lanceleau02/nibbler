#include "../libs/SFML/include/SFML/Graphics.hpp"
#include <iostream>

extern "C" void	createCircle(sf::CircleShape* circle) {
	circle->setPosition(0.0f, 0.0f);
	circle->setFillColor(sf::Color::Green);
}

extern "C" void createWindow() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML - Circle Example");

	sf::CircleShape*	circle = new sf::CircleShape(100.0f);
	createCircle(circle);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(*circle);
		window.display();
	}
	window.close();
}
