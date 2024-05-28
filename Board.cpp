#include "Board.hpp"
#include "Tile.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace ariel {
// Board::Board() {
//     // constructor implementation
// }
        Board::Board() {
         
    tiles.emplace_back(1, Resource::None);
    tiles.emplace_back(2, Resource::Wool);
    tiles.emplace_back(3, Resource::Wood);
    tiles.emplace_back(4, Resource::Grain);
    tiles.emplace_back(5, Resource::Wool);
    tiles.emplace_back(6, Resource::Brick);
    tiles.emplace_back(7, Resource::Wood);
    tiles.emplace_back(8, Resource::Wood);
    tiles.emplace_back(9, Resource::Grain);
    tiles.emplace_back(10, Resource::Ore);
    tiles.emplace_back(11, Resource::Wool);
    tiles.emplace_back(12, Resource::Grain);
    tiles.emplace_back(3, Resource::Ore);
    tiles.emplace_back(4, Resource::Grain);
    tiles.emplace_back(5, Resource::Brick);
    tiles.emplace_back(6, Resource::Grain);
    tiles.emplace_back(9, Resource::Wood);
    tiles.emplace_back(10, Resource::Brick);
    tiles.emplace_back(8, Resource::Ore);
        }
// void Board::generateBoard() {
//     tiles.emplace_back(1, Resource::None);
//     tiles.emplace_back(2, Resource::Wool);
//     tiles.emplace_back(3, Resource::Wood);
//     tiles.emplace_back(4, Resource::Grain);
//     tiles.emplace_back(5, Resource::Wool);
//     tiles.emplace_back(6, Resource::Brick);
//     tiles.emplace_back(7, Resource::Wood);
//     tiles.emplace_back(8, Resource::Wood);
//     tiles.emplace_back(9, Resource::Grain);
//     tiles.emplace_back(10, Resource::Ore);
//     tiles.emplace_back(11, Resource::Wool);
//     tiles.emplace_back(12, Resource::Grain);
//     tiles.emplace_back(3, Resource::Ore);
//     tiles.emplace_back(4, Resource::Grain);
//     tiles.emplace_back(5, Resource::Brick);
//     tiles.emplace_back(6, Resource::Grain);
//     tiles.emplace_back(9, Resource::Wood);
//     tiles.emplace_back(10, Resource::Brick);
//     tiles.emplace_back(8, Resource::Ore);
// }

Tile& Board::getTile(int number) {
    for (auto& tile : tiles) {
        if (tile.getNumber() == number) {
            return tile;
        }
    }
    throw std::out_of_range("Tile not found");
}

// bool Board::isValidSettlementLocation(int location) {
//     // Logic to check if the location is valid for settlement
//     return true;
// }

// bool Board::isValidRoadLocation(int location) {
//     // Logic to check if the location is valid for road
//     return true;
// }

// void Game::start() {
//     board.generateBoard();
// }

std::string drawTile(const Tile& tile) {
    std::ostringstream tileStream;
    tileStream << std::setw(10) << std::left << tile.getResourceName().substr(0, 3)
               << std::setw(3) << tile.getNumber();

    return tileStream.str();
}

void Board::printBoard( const Board& board) {
    const auto& tiles = board.getTiles();

    int layout[5][5] = {
        { -1,  0,  1, -1, -1},
        {  2,  3,  4,  5, -1},
        {  6,  7,  8,  9, 10},
        { -1, 11, 12, 13, 14},
        { -1, -1, 15, 16, 17}
    };

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (layout[i][j] == -1) {
                std::cout << std::setw(13) << " "; // רווח ריק ליישור
            } else {
                std::cout << drawTile(tiles[layout[i][j]]) << " ";
            }
        }
        std::cout << std::endl;
    }
}



}
