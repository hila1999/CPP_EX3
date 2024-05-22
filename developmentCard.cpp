#include "developmentCard.hpp"
#include "player.hpp"
#include <iostream>

// Monopoly card
void Monopoly::use(Player& player) {
    std::cout << "Monopoly card used by " << player.getName() << ". All players must give " << player.getName() << " their resources of a chosen type." << std::endl;
    // Implement the logic to collect resources from all other players
}

std::string Monopoly::getType() const {
    return "Monopoly";
}

// Road Building card
void RoadBuilding::use(Player& player) {
    std::cout << "Road Building card used by " << player.getName() << ". Player can build two roads for free." << std::endl;
    // Implement the logic to allow the player to build two roads for free
}

std::string RoadBuilding::getType() const {
    return "Road Building";
}

// Year of Plenty card
void YearOfPlenty::use(Player& player) {
    std::cout << "Year of Plenty card used by " << player.getName() << ". Player can take any two resource cards from the bank." << std::endl;
    // Implement the logic to allow the player to take any two resources from the bank
}

std::string YearOfPlenty::getType() const {
    return "Year of Plenty";
}

// Knight card
void Knight::use(Player& player) {
    std::cout << "Knight card used by " << player.getName() << ". Player can move the robber and steal a resource card from one player." << std::endl;
    // Implement the logic to move the robber and steal a resource from one player
}

std::string Knight::getType() const {
    return "Knight";
}

// Victory Point card
// void VictoryPoint::use(Player& player) {
//     std::cout << "Victory Point card used by " << player.getName() << ". Player gets one additional victory point." << std::endl;
//     // Implement the logic to give the player an additional victory point
//     player.addVictoryPoint();
// }

std::string VictoryPoint::getType() const {
    return "Victory Point";
}
