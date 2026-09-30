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
    // char delimiter = '/';
    // std::stringstream ss(fen);
    // std::string row;
    // std::vector<std::string> rows;

    // while(std::getline(ss, row, delimiter)){
    //     rows.push_back(row);
    // }

    // // for(const auto& row : rows){
    // //     std::cout << row << '\n';
    // // }

    const size_t size = fen.size();
    size_t iter = 0;
    int index = 0;

    // parse string
    for(; (iter < size) && fen[iter] != ' '; iter++){

        if(fen[iter] != '/') continue;

        if(std::isdigit(fen[iter])){
            index += (fen[iter] - '0'); // convert char to int eg: '5' to 5
        }
        else{
            //TODO
        }
    }


}