#include "board.h"
#include <iostream>

Board::Board() {
    bitboards[WhitePawns]   = 0x000000000000FF00ULL;
    bitboards[WhiteRooks]   = 0x0000000000000081ULL;
    bitboards[WhiteKnights] = 0x0000000000000042ULL;
    bitboards[WhiteBishops] = 0x0000000000000024ULL;
    bitboards[WhiteQueens]  = 0x0000000000000008ULL;
    bitboards[WhiteKing]    = 0x0000000000000010ULL;

    // Black
    bitboards[BlackPawns]   = 0x00FF000000000000ULL;
    bitboards[BlackRooks]   = 0x8100000000000000ULL;
    bitboards[BlackKnights] = 0x4200000000000000ULL;
    bitboards[BlackBishops] = 0x2400000000000000ULL;
    bitboards[BlackQueens]  = 0x0800000000000000ULL;
    bitboards[BlackKing]    = 0x1000000000000000ULL;
}

void Board::PrintBitboard(Bitboard bitboard) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            if ((bitboard >> square) & 1)
                std::cout << "1 ";
            else
                std::cout << ". ";
        }
        std::cout << '\n';
    }
}

void Board::MovePiece(Move move) {
    Bitboard from = 1ULL << move.from;
    Bitboard to = 1ULL << move.to;

    bitboards[move.piece] &= ~from;
    bitboards[move.piece] |= to;

}