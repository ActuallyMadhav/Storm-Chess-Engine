#include <iostream>
#include <algorithm>
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
    int board[64];  // starting board as single array
    // 0: a1, 1: a2, ..., 7: a8
    // 56: h1, 57: h2, ..., 63: h8

public:
    
};