#include "../inc/board.h"
#include <cctype>
#include <cstddef>
#include <algorithm>
#include <cstdint>
#include <sstream>
#include <string>
#include <sys/types.h>

void Board::print(){
    for(int i = 0; i < 64; i++){
        std::cout << pieceSymbols[board[i]] << ' ';
        if((i + 1) % 8 == 0){
            std::cout << '\n';
        }
    }

    !turn ? std::cout << "white turn" << '\n' : std::cout << "black turn" << '\n';

    whiteKingCastle ? std::cout << "white king castle true" << '\n' : std::cout << "false" << '\n';
    whiteQueenCastle ? std::cout << "white queen castle true" << '\n' : std::cout << "false" << '\n';
    blackKingCastle ? std::cout << "black king castle true" << '\n' : std::cout << "false" << '\n';
    blackQueenCastle ? std::cout << "black queen castle true" << '\n' : std::cout << "false" << '\n';

    std::cout << static_cast<int>(enPassant_target) << '\n';

}

void Board::parseFEN(const std::string& fen){

    std::cout << fen << '\n';

    char delimiter = '/';
    std::stringstream ss(fen);
    std::string row;
    std::vector<std::string> rows;

    while(std::getline(ss, row, delimiter)){
        rows.push_back(row);
    }

    int lastRowIdx = rows.size()-1;

    std::stringstream ss2(rows[lastRowIdx]);
    std::string lastRow;
    while(std::getline(ss2, lastRow, ' ')){
        rows.push_back(lastRow);
    }

    rows.erase(rows.begin() + lastRowIdx);

    std::reverse(rows.begin(), rows.begin()+8);

    // print rows
    // for(const auto& row : rows){
    //     std::cout << row << '\n';
    // }

    // modify board state according to fen
    for(int i = 0; i < 8; i++){ // iterate through rows vector, rows 0 - 7 are piece positions on the board
        int counter = 0;
        for(int j = 0; j < rows[i].size(); j++){
            if(std::isdigit(static_cast<unsigned char>(rows[i][j]))){
                // 
                counter += rows[i][j] - '0';
                continue;
            }
            else{
                int index;
                auto ptr = std::find(std::begin(pieceSymbols), std::end(pieceSymbols), rows[i][j]);
                if(ptr != std::end(pieceSymbols)){
                    index = ptr - pieceSymbols;
                }
                board[i*8 + counter] = index;
                counter++;
            }
        }
    }

    // TODO:
    // update turn, castling rights, en 
    // rows 8-12 are:

    // 8 - turn (b/w)
    if(rows[8] == "w"){
        turn = WHITE;    // white turn
    }
    else{
        turn = BLACK;   // black turn
    }

    // 9 - castling rights (KQ - white, kq - black)
    if(std::count(rows[9].begin(), rows[9].end(), 'K')){
        whiteKingCastle = true;
    }
    if(std::count(rows[9].begin(), rows[9].end(), 'Q')){
        whiteQueenCastle = true;
    }
    if(std::count(rows[9].begin(), rows[9].end(), 'k')){
        blackKingCastle = true;
    }
    if(std::count(rows[9].begin(), rows[9].end(), 'q')){
        blackQueenCastle = true;
    }

    // 10 - en passant target
    enPassant_target = setEnPassTarget(rows[10]);

    // 11 - half move clock - used to track 50 move draw rule
    
    // 12 - full move number - tracks number of moves in game. updated after black's turn
    for(const auto& row : rows){
        std::cout << row << '\n';
    }
}

uint8_t Board::setEnPassTarget(const std::string& square){
    // TODO
    if(square[0] == '-'){
        return -1;
    }

    char fileChar = square[0];
    char rankChar = square[1];

    uint8_t fileIdx = fileChar - 'a';
    uint8_t rankIdx = rankChar - '1';

    uint8_t boardSquare = rankIdx * 8 + fileIdx;

    return boardSquare;
}