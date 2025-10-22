#include "raylib.h"
#include "render.h"
// #include <iostream>

int main()
{
    InitWindow(SQUARE_SIZE * 8, SQUARE_SIZE * 8, "Duckfish");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

    while (!WindowShouldClose()) {
		BeginDrawing();

        ClearBackground(BLACK);

        drawBoard();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}