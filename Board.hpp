#pragma once
#include <vector>
#include "Tile.hpp"
namespace ariel {
// class Board{

// public:
// Board();


// };
class Board {
private:
    std::vector<Tile> tiles;

public:
    Board();
    void generateBoard();
    Tile& getTile(int number);
    bool isValidSettlementLocation(int location);
    bool isValidRoadLocation(int location);
    const std::vector<Tile>& getTiles() const {
        return tiles;
    }
    void printBoard(const Board& board);
};
}