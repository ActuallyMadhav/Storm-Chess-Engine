#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <cstddef>
#include <algorithm>
#include <sstream>
#include <string>
#include <sys/types.h>

// macros
using u64 = std::uint64_t;

enum color{
    WHITE = 0,
    BLACK = 1
};

// check piece color: black > 6; white <= 6
// (piece <= 6) && piece ? white : black;
enum pieces {
    empty = 0,  // empty square

    // white pieces
    wpawn = 1, wknight = 2, wbishop = 3, wrook = 4, wqueen = 5, wking = 6,
    
    // black pieces
    bpawn = 7, bknight = 8, bbishop = 9, brook = 10, bqueen = 11, bking = 12
};

class Board{
private:
    int board[64];
    // starting position
    // int board[64] = {
    //     wrook, wknight, wbishop, wqueen, wking, wbishop, wknight, wrook,
    //     wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn,
    //     empty, empty,empty,empty,empty,empty,empty,empty,
    //     empty, empty,empty,empty,empty,empty,empty,empty,
    //     empty, empty,empty,empty,empty,empty,empty,empty,
    //     empty, empty,empty,empty,empty,empty,empty,empty,
    //     bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn,
    //     brook, bknight, bbishop, bqueen, bking, bbishop, bknight, brook
    // };  // starting board as single array
    // 0: a1, 1: b1, ..., 7: h1
    // 56: a8, 57: b8, ..., 63: h8

    // pieces are arranged according to enum pieces
    static constexpr char pieceSymbols[13] = {
        '_',    // empty square
        'P', 'N', 'B', 'R', 'Q', 'K',  // white pieces
        'p', 'n', 'b', 'r', 'q', 'k'    // black pieces
        };
    
    // castling rights
    bool whiteKingCastle;
    bool whiteQueenCastle;
    bool blackKingCastle;
    bool blackQueenCastle;
    
    // en passant legal?
    int enPassant_target;

    // turn - white or black
    bool turn;  // true = white turn
    

public:
    void parseFEN(const std::string& fen);  // parse fen and set up board according to fen
    int setEnPassTarget(const std::string& square);    // update en passant target
    void print();   // print board state    
};

#endif