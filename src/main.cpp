#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Duckfish");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

        while (!WindowShouldClose())
        {
		// LOGIC

		// DRAWING

		BeginDrawing();

        ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}