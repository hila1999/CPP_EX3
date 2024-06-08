#pragma once
#include "player.hpp"  // Include the full definition of Player class
#include <string> // Include the <string> header file
namespace ariel {
class Player;  // Forward declaration to avoid circular dependency

class Catan{
    Player p1;
    Player p2;
    Player p3;
    Player* currentPlayer;
    Board board;
    public:
    Catan(Player& p1, Player& p2, Player& p3);
    ~Catan();
    void ChooseStartingPlayer(); // Return the name of the starting player
    Player &getCurrentPlayer();
    Board &getBoard();
};
}