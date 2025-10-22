#include "render.h"

void drawBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Color c = ((row + col) % 2 == 0) ? CHECKERBOARD_LIGHT : CHECKERBOARD_DARK;
            DrawRectangle(col * SQUARE_SIZE, (7 - row) * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, c);
        }
    }
}