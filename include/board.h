#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include "piece_type.h"

using Bitboard = __UINT64_TYPE__;

class Board {
    Bitboard bitboards[12];
    
    
public: 
    Board();

    void PrintBitboard(Bitboard);
    void MovePiece(Move);
};

struct Move {
    int from;
    int to;
    PieceType piece;
    PieceType capturedPiece;   // e.g. WhitePawn captures BlackKnight
    PieceType promotionPiece;  // for pawn promotions
    bool isCastle;
    bool isEnPassant;
};

#endif