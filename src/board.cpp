#include "../inc/board.h"

void Board::print(){
    for(int i = 0; i < 64; i++){
        std::cout << pieceSymbols[board[i]] << ' ';
        if((i + 1) % 8 == 0){
            std::cout << '\n';
        }
    }
}