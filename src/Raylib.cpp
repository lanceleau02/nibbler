/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:08:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 11:10:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Raylib.hpp"

Raylib::Raylib() {}

Raylib::~Raylib() {}

void	Raylib::createSquare(void* r) {
	DrawRectangle(350, 250, 100, 100, GREEN);
}

void	Raylib::clearWindow(void* r) {
	BeginDrawing();
	ClearBackground(BLACK);
}

void	Raylib::closeWindow(void* r) {
	EndDrawing();
	CloseWindow();
}

void	Raylib::display(void* r) {
	EndDrawing();
}

int	Raylib::handleEvents(void* r) {
	if (IsKeyPressed(KEY_ESCAPE)) return CLOSE_WINDOW;
	if (IsKeyPressed(KEY_ONE)) return ONE;
	if (IsKeyPressed(KEY_TWO)) return TWO;
	if (IsKeyPressed(KEY_THREE)) return THREE;
	return -1;
}

bool	Raylib::isOpen(void* r) {
	return !WindowShouldClose();
}

void*	Raylib::createWindow() {
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(_windowWidth, _windowHeight, "Nibbler (Raylib)");
	return nullptr;
}

void    Raylib::centerWindow(void* r) {
	int monitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(monitor);
	int monitorHeight = GetMonitorHeight(monitor);
	SetWindowPosition((int)(monitorWidth / 2) - (int)(_windowWidth / 2), (int)(monitorHeight / 2) - (int)(_windowHeight / 2));
}

extern "C" {
	ILibraries*	createLibraryInstance() {
		return new Raylib();
	}
}
