/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/31 15:50:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

// Raylib::Raylib(const Raylib& other) {}

// Raylib& Raylib::operator=(const Raylib& other) { return other; }

Raylib::~Raylib() {}

void	Raylib::createSquare(void* r) {
	(void)r;
	DrawRectangle(350, 250, 100, 100, GREEN);
}

void	Raylib::clearWindow(void* r) {
	(void)r;
	BeginDrawing();
	ClearBackground(BLACK);
}

void	Raylib::display(void* r) {
	(void)r;
	EndDrawing();
}

void*	Raylib::createWindow() {
	InitWindow(800, 600, "Nibbler (Raylib)");
	return nullptr;

/* 	while (!WindowShouldClose()) {
		BeginDrawing();
		createSquare(NULL);
		EndDrawing();
	}
	CloseWindow(); */
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
