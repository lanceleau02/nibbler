#include "../Raylib/include/raylib.h"

extern "C" void createCircle() {
	DrawCircle(0, 0, 100, GREEN);
}

extern "C" void createWindow() {
	InitWindow(800, 600, "Raylib - Circle Example");

	while (!WindowShouldClose()) {
		BeginDrawing();
		createCircle();
		EndDrawing();
	}
}
