/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 15:52:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

Raylib::~Raylib() {}

int	Raylib::handleEvents(void* r) {
	if (IsKeyPressed(KEY_ESCAPE)) return CLOSE_WINDOW;
	if (IsKeyPressed(KEY_ONE)) return ONE;
	if (IsKeyPressed(KEY_TWO)) return TWO;
	if (IsKeyPressed(KEY_THREE)) return THREE;
	if (IsKeyPressed(KEY_UP)) return UP;
	if (IsKeyPressed(KEY_DOWN)) return DOWN;
	if (IsKeyPressed(KEY_LEFT)) return LEFT;
	if (IsKeyPressed(KEY_RIGHT)) return RIGHT;
	return -1;
}

bool	Raylib::isOpen(void* r) {
	return !WindowShouldClose();
}

void    Raylib::centerWindow(void* r) {
	int monitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(monitor);
	int monitorHeight = GetMonitorHeight(monitor);
	SetWindowPosition((int)(monitorWidth / 2) - (int)(_windowWidth / 2), (int)(monitorHeight / 2) - (int)(_windowHeight / 2));
}

void	Raylib::clearWindow(void* r) {
	BeginDrawing();
	ClearBackground(BLACK);
}

void	Raylib::closeWindow(void* r) {
	EndDrawing();
	CloseWindow();
}

void	Raylib::createSquare(int x, int y, int width, int height, const Colors& color, void* r) {
	unsigned char   red = static_cast<unsigned char>(color.r);
	unsigned char   green = static_cast<unsigned char>(color.g);
	unsigned char   blue = static_cast<unsigned char>(color.b);
	unsigned char   alpha = static_cast<unsigned char>(color.a);
    DrawRectangle(x, y, width, height, (Color){ red, green, blue, alpha });
}

void	Raylib::display(void* r) {
	EndDrawing();
}

void*	Raylib::createWindow() {
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(_windowWidth, _windowHeight, "Nibbler (Raylib)");
	return nullptr;
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
