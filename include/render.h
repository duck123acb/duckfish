#ifndef RENDER_H
#define RENDER_H

#include "raylib.h"

const Color CHECKERBOARD_LIGHT = {240, 216, 181, 255};
const Color CHECKERBOARD_DARK  = {180, 136, 98, 255};

const int SQUARE_SIZE = 80;

void DrawBoard(); // eventually drawBoard(board);

#endif