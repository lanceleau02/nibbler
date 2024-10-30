/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 09:49:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

// Raylib::Raylib(const Raylib& other) {}

// Raylib& Raylib::operator=(const Raylib& other) { return other; }

Raylib::~Raylib() {}

void	Raylib::createWindow() {
	InitWindow(800, 600, "Nibbler (Raylib)");

	while (!WindowShouldClose()) {
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
