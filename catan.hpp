#pragma once
#include "player.hpp"  // Include the full definition of Player class
#include <string> // Include the <string> header file
//hila.shamir99@gmail.com
//314906983
namespace ariel {
class Player;  // Forward declaration to avoid circular dependency

class Catan{
    Player& p1;
    Player& p2;
    Player& p3;
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