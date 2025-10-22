#ifndef RENDER_H
#define RENDER_H

#include <cstdint>
#include "piece_type.h"

using Bitboard = __UINT64_TYPE__;

class Board {
    
    Bitboard bitboards[12];


    void PrintBitboard(Bitboard);
    void MovePiece(Bitboard, PieceType);
};

#endif