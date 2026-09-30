#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

// macros
#define u64 unsigned long long

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
    int board[64] = {
        wrook, wknight, wbishop, wqueen, wking, wbishop, wknight, wrook,
        wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn,
        empty, empty,empty,empty,empty,empty,empty,empty,
        empty, empty,empty,empty,empty,empty,empty,empty,
        empty, empty,empty,empty,empty,empty,empty,empty,
        empty, empty,empty,empty,empty,empty,empty,empty,
        bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn,
        brook, bknight, bbishop, bqueen, bking, bbishop, bknight, brook
    };  // starting board as single array
    // 0: a1, 1: b1, ..., 7: h1
    // 56: a8, 57: b8, ..., 63: h8

    // pieces are arranged according to enum pieces
    char pieceSymbols[13] = {
        '_',    // empty square
        'P', 'N', 'B', 'R', 'Q', 'K',  // white pieces
        'p', 'n', 'b', 'r', 'q', 'k'    // black pieces
        };

public:
    void print();   // print board state    
};