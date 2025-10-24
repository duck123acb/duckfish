#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include "piece_type.h"
#include "bitboard.h"

struct Move {
    int from;
    int to;
    PieceType piece;
    PieceType capturedPiece;   // e.g. WhitePawn captures BlackKnight
    PieceType promotionPiece;  // for pawn promotions
    bool isCastle;
    bool isEnPassant;
};

struct Board {
    Bitboard bitboards[12];
    
    Board();

    void PrintBitboard(Bitboard);
    void MovePiece(Move);
};

#endif