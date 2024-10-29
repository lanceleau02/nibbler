#include "../libs/Raylib/include/raylib.h"

extern "C" void createCircle() {
	DrawCircle(100, 100, 100, GREEN);
}

extern "C" void createWindow() {
	InitWindow(800, 600, "Raylib - Circle Example");

	while (!WindowShouldClose()) {
		BeginDrawing();
		createCircle();
		EndDrawing();
	}
	CloseWindow();
}
