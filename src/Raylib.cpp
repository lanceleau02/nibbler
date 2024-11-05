/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 14:03:04 by laprieur         ###   ########.fr       */
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

void	Raylib::closeWindow(void* r) {
	EndDrawing();
	CloseWindow();
}

void	Raylib::display(void* r) {
	(void)r;
	EndDrawing();
}

int	Raylib::handleEvents(void* r) {
	if (IsKeyPressed(KEY_ESCAPE)) {
		return CLOSE_WINDOW;
	}
	return -1;
}

bool	Raylib::isOpen(void* r) {
	return !WindowShouldClose();
}

void*	Raylib::createWindow() {
    SetTraceLogLevel(LOG_ERROR);
	InitWindow(800, 600, "Nibbler (Raylib)");
	return nullptr;
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
