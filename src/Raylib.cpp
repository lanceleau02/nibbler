/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 11:57:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

// Raylib::Raylib(const Raylib& other) {}

// Raylib& Raylib::operator=(const Raylib& other) { return other; }

Raylib::~Raylib() {}

/* void	Raylib::createSquare() {
	DrawRectangle(350, 250, 100, 100, GREEN);
} */

void	Raylib::createWindow() {
	InitWindow(800, 600, "Nibbler (Raylib)");

	while (!WindowShouldClose()) {
		BeginDrawing();
		// createSquare();
		EndDrawing();
	}
	CloseWindow();
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
