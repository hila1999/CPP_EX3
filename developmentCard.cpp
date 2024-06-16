#include "developmentCard.hpp"
#include "player.hpp"
#include "catan.hpp"
#include <iostream>
using namespace ariel;
// Monopoly card
// void Monopoly::use(int a) {
//     std::cout << "Monopoly card used by " << player.getName() << ". All players must give " << player.getName() << " their resources of a chosen type." << std::endl;
//     // Implement the logic to collect resources from all other players
// }

void ariel::Monopoly::use(Player &player,Board& board)
{
    use(player,"ore",board);
}

void ariel::Monopoly::use(Player &player, ::string resourceType, Board &board)
{
std::cout << "Monopoly card used by " << player.getName() << ". All players must give " << player.getName() << " their resources of " << resourceType << "." << std::endl;
// Inside any function or scope outside of the Catan class
    std::vector<Player*> players = board.getPlayers();

     cout << players.size() << endl;
    for (Player* p : players) {
        cout<<"p" << p->getName() << endl;
        if (p != &player) {
            int resources = p->removeAllResources(resourceType);
            player.addResources(resourceType, resources);
            std::cout << p->getName() << " gives " << resources << " " << resourceType << " to " << player.getName() << "." << std::endl;
        }
    }}

std::string Monopoly::getType() const
{
    return "Monopoly";
}

void ariel::RoadBuilding::use(Player &player,Board& board)
{
    use(player,1,2 ,board);
    
}

// Road Building card
void RoadBuilding::use(Player& player,int road1, int road2 ,Board& board) {
    std::cout << "Road Building card used by " << player.getName() << ". Player can build two roads for free." << std::endl;
    std::cout << "Road 1: " << road1 << std::endl;
    player.addResources("wood",2);
    player.addResources("brick",2);
    player.placeRoad(road1,board);
    player.placeRoad(road2, board);
    // Implement the logic to allow the player to build two roads for free
}

std::string RoadBuilding::getType() const {
    return "Road Building";
}

// Year of Plenty card
void YearOfPlenty::use(Player& player,Board& board) {
    std::cout << "Year of Plenty card used by " << player.getName() << ". Player can take any two resource cards from the bank." << std::endl;
    use(player,"wood","brick");
    // Implement the logic to allow the player to take any two resources from the bank
}

void ariel::YearOfPlenty::use(Player &player, std::string resource1, std::string resource2)
{
    player.addResources(resource1,1);
    player.addResources(resource2,1);
}

std::string YearOfPlenty::getType() const {
    return "Year of Plenty";
}

// Knight card
Knight::Knight(Player* owner) : owner(owner) {
}
void Knight::use(Player& player,Board& board) {
    owner->addKnight();
    if(owner->getNumOfKnights() >= 3){
        owner->addVictoryPoints(2);
    }
    std::cout << "Knight card used by " << player.getName() << ". Player can move the robber and steal a resource card from one player." << std::endl;
    // Implement the logic to move the robber and steal a resource from one player
}

std::string Knight::getType() const {
    return "Knight";
}

// Victory Point card
void VictoryPoint::use(Player& player,Board& board) {
    std::cout << "Victory Point card used by " << player.getName() << ". Player gets one additional victory point." << std::endl;
    // Implement the logic to give the player an additional victory point
    player.addVictoryPoints(1);
}

std::string VictoryPoint::getType() const {
    return "Victory Point";
}
