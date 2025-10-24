#include "render.h"
#include "piece_type.h"
#include "bitboard.h"

Image atlas;
int pieceScaleFactor;
Texture pieceTextures[];

void Setup() {
    atlas = LoadImage("assets/Chess_Pieces_Sprite.svg.png");
    int frameSideLength = atlas.height / 6;
    pieceScaleFactor = SQUARE_SIZE / frameSideLength; 

    for (int i = 0; i != Final; i++)
    {
        PieceType type = static_cast<PieceType>(i);
        Rectangle frame = {
            frameSideLength * (type % 6),
            (type >= BlackKing) ? frameSideLength : 0,
            frameSideLength,
            frameSideLength
        };
        Image img = ImageFromImage(atlas, frame);
        Texture2D txt = LoadTextureFromImage(img);

        UnloadImage(img);
    }

    UnloadImage(atlas);
}
void DrawCheckerboard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Color c = ((row + col) % 2 == 0) ? CHECKERBOARD_LIGHT : CHECKERBOARD_DARK;
            DrawRectangle(col * SQUARE_SIZE, (7 - row) * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, c);
        }
    }
}

void RenderPieces(Bitboard bitboards[]) {
    
    

    // DrawTextureEx(txt, {0, 0}, 0, scaleFactor, WHITE);
    
}