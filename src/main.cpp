#include "../inc/board.h"

int main(){
    Board* test = new Board;
    // test->print();

    test->parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    return 0;
}