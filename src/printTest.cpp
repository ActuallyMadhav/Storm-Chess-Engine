#include "../inc/board.h"

int main(){
    Board* test = new Board;
    // test->print();

    // std::string fullBoard = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    // test->parseFEN(fullBoard);
    // test->print();

    // std::string emptyBoard = "8/8/8/8/8/8/8/8 w - - 0 1";
    // test->parseFEN(emptyBoard);
    // test->print();

    // std::string mixed = "4k3/8/8/8/8/8/8/4K3 w - - 0 1";
    // test->parseFEN(mixed);
    // test->print();

    // std::string midGame = "r1bqkbnr/pppp1ppp/2n5/1B2p3/4P3/5N2/PPPP1PPP/RNBQK2R b KQkq - 3 3";
    // test->parseFEN(midGame);
    // test->print();

    std::string enPassant = "rnbqkbnr/ppp1pppp/8/3pP3/8/8/PPPP1PPP/RNBQKBNR w KQkq d6 0 3";
    test->parseFEN(enPassant);
    test->print();

    return 0;
}