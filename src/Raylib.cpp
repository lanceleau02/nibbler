/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/10 17:04:55 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

Raylib::~Raylib() {}

int	Raylib::handleEvents(void*) {
	if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) return CLOSE_WINDOW;
	if (IsKeyPressed(KEY_ONE)) return ONE;
	if (IsKeyPressed(KEY_TWO)) return TWO;
	if (IsKeyPressed(KEY_THREE)) return THREE;
	if (IsKeyPressed(KEY_UP)) return UP;
	if (IsKeyPressed(KEY_DOWN)) return DOWN;
	if (IsKeyPressed(KEY_LEFT)) return LEFT;
	if (IsKeyPressed(KEY_RIGHT)) return RIGHT;
	return -1;
}

bool	Raylib::isOpen(void*) {
	return !WindowShouldClose();
}

void    Raylib::centerWindow(int width, int height, void*) {
	int monitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(monitor);
	int monitorHeight = GetMonitorHeight(monitor);
	SetWindowPosition((int)(monitorWidth / 2) - (int)(width / 2), (int)(monitorHeight / 2) - (int)(height / 2));
}

void	Raylib::clearWindow(void*) {
	BeginDrawing();
	ClearBackground(BLACK);
}

void	Raylib::closeWindow(void*) {
	EndDrawing();
	CloseWindow();
}

void	Raylib::createSquare(int x, int y, int size, const Colors& color, void*) {
	unsigned char   red = static_cast<unsigned char>(color.r);
	unsigned char   green = static_cast<unsigned char>(color.g);
	unsigned char   blue = static_cast<unsigned char>(color.b);
	unsigned char   alpha = static_cast<unsigned char>(color.a);
	DrawRectangle(x, y, size, size, (Color){ red, green, blue, alpha });
}

void	Raylib::display(void*) {
	EndDrawing();
}

void*	Raylib::createWindow(int width, int height) {
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(width, height, "Nibbler (Raylib)");
	return nullptr;
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
