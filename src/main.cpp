#include "raylib.h"
#include <iostream>

int main()
{
    const Color CHECKERBOARD_LIGHT = (Color){240, 216, 181, 255};
    const Color CHECKERBOARD_DARK = (Color){180, 136, 98, 255};

    const int SQUARE_SIZE = 80;

    InitWindow(SQUARE_SIZE * 8, SQUARE_SIZE * 8, "Duckfish");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

        while (!WindowShouldClose())
        {
    		BeginDrawing();

            ClearBackground(BLACK);

            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    Color c = ((row + col) % 2 == 0) ? CHECKERBOARD_LIGHT : CHECKERBOARD_DARK;
                    DrawRectangle(col * SQUARE_SIZE, (7 - row) * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, c);
                }
            }

    		EndDrawing();
    	}

	CloseWindow();
	return 0;
}