#include "../inc/board.h"
#include <cctype>
#include <cstddef>
#include <algorithm>
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

    std::reverse(rows.begin(), rows.begin()+8);

    // print rows
    // for(const auto& row : rows){
    //     std::cout << row << '\n';
    // }

    // modify board state according to fen
    for(int i = 0; i < 8; i++){ // iterate through rows vector
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
    // update turn, castling rights, en passant
}