#include "../inc/move.h"
#include <optional>
#include <string>

inline std::optional<square> stringToSquare(const std::string &moveStr){
    
    if(moveStr.size() != 2){
        return std::nullopt;
    }
    
    char fileChar = moveStr[0];
    char rankChar = moveStr[1];

    if(fileChar < 'a' || fileChar > 'h' || rankChar < '1' || rankChar > '8'){
        return std::nullopt;
    }

    int rankIdx = rankChar - '1';
    int fileIdx = fileChar - 'a';

    int squareIdx = rankIdx*8 + fileIdx;

    return static_cast<square>(squareIdx);
}