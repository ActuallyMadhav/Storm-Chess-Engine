#include "../inc/board.h"
#include <cctype>
#include <cstddef>
#include <sstream>
#include <string>

void Board::print(){
    for(int i = 0; i < 64; i++){
        std::cout << pieceSymbols[board[i]] << ' ';
        if((i + 1) % 8 == 0){
            std::cout << '\n';
        }
    }
}

void Board::parseFEN(const std::string& fen){
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

    // print rows
    for(const auto& row : rows){
        std::cout << row << '\n';
    }

}