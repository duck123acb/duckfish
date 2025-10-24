#include "render.h"
#include "piece_type.h"

Image atlas;
float pieceScaleFactor;
Texture pieceTextures[12];

void Setup() {
    atlas = LoadImage("assets/Chess_Pieces_Sprite.svg.png");
    float frameSideLength = atlas.height / 6;
    pieceScaleFactor = SQUARE_SIZE / frameSideLength; 

    for (int
         i = 0; i != Final; i++) {
        PieceType type = static_cast<PieceType>(i);
        Rectangle frame = {
            frameSideLength * (type % 6),
            (type >= BlackKing) ? frameSideLength : 0,
            frameSideLength,
            frameSideLength
        };
        Image img = ImageFromImage(atlas, frame);
        pieceTextures[type] = LoadTextureFromImage(img);

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

void DrawPieces(Bitboard bitboards[]) {
    for (int i = 0; i != Final; i++) {
        PieceType type = static_cast<PieceType>(i);
        Bitboard bitboard = bitboards[type];

        while (bitboard) { // bitboard != 0
            int sq = __builtin_ctzll(bitboard); // counts trailing zeros to get the next sig dig
            bitboard &= bitboard - 1; // remove that sig dig to for next iteration

            float row = sq / 8;
            float col = sq % 8;
            Vector2 pos = { col * SQUARE_SIZE, row * SQUARE_SIZE };

            DrawTextureEx(pieceTextures[type], pos, 0, pieceScaleFactor, WHITE);
        }
    }
}