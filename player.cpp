#include "player.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include "developmentCard.hpp"
#include "Board.hpp"
namespace ariel {
Player::Player()
{}
Player::Player(const std::string &name) : name(name), victoryPoints(2), isTurn(false), numOfKnights(0)
{
    // Initialize resources with zero
    resources["wood"] = 0; 
    resources["brick"] = 0;
    resources["wool"] = 0;
    resources["wheat"] = 0;
    resources["ore"] = 0;
}
Player::~Player() {
    for (DevelopmentCard* card : developmentCards) {
        delete card;
    }
}

void Player::setTurn(bool isTurn) {
    this->isTurn = isTurn;
}

bool Player::isTurnPlayer() const {
    return isTurn;
}

void Player::addKnight()
{
    numOfKnights++;
}

int Player::getNumOfKnights() const
{
    return numOfKnights;
}

std::string Player::getName() const {
    return name;
}

void Player::rollDice(Board& board)
{
    if(isTurn)
{   std::random_device rd; // Random number generator
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(1, 6); // Uniform distribution in range [1, 6]

    int dice1 = dis(gen);
    int dice2 = dis(gen);
    int lastRoll = dice1 + dice2;

    std::cout << name << " rolled " << dice1 << " and " << dice2 << " for a total of " << lastRoll << std::endl;
        board.distributeResources(lastRoll); // Call distributeResources with the roll outcome
        }
        else
        {
            throw std::runtime_error("Not your turn");
        }

}

void Player::buyDevelopmentCard(Board& board) {
    if (resources["ore"] >= 1 && resources["wool"] >= 1 && resources["wheat"] >= 1) {
        DevelopmentCard* card = nullptr;

        while (true) {
            int randNum = std::rand() % 5; // Assuming 5 types of cards

            switch (randNum) {
                case 0:
                    if (board.knightCount < board.MAX_KNIGHT_CARDS) {
                        card = new Knight(this);
                        board.knightCount++;
                    }
                    break;
                case 1:
                    card = new Monopoly();
                    break;
                case 2:
                    card = new RoadBuilding();
                    break;
                case 3:
                    card = new YearOfPlenty();
                    break;
                case 4:
                    if (board.victoryPointCount < board.MAX_VICTORY_POINT_CARDS) {
                        card = new VictoryPoint();
                        board.victoryPointCount++;
                    }
                    break;
            }

            if (card != nullptr) {
                break;
            }
        }
        
        developmentCards.push_back(card);
        // developmentCards.push_back(<DevelopmentCard>(card));
        removeResources("ore", 1);
        removeResources("wool", 1);
        removeResources("wheat", 1);
        std::cout << name << " bought a development card." << card ->getType() << std::endl;
    } else {
        throw std::runtime_error("Not enough resources to buy a development card.");
    }
}

void Player::useDevelopmentCard(Board& board) {
    if (!developmentCards.empty()) {
        DevelopmentCard* card = std::move(developmentCards.back());
        card->use(*this, board);
        std::cout << name << " used a development card." << card->getType() << std::endl;
           if(card->getType() != "Victory Point" && card->getType() != "Knight"){
        developmentCards.pop_back();
        delete card;
        std::cout << name << " the card delet" << std::endl;}
    } else {
        throw std::runtime_error("No development cards to use.");
    }
}

void Player::placeRoad(int placesNum, Board& board) { //add check if the player have settelmet near i need to update the board
    if (resources["wood"] >= 1 && resources["brick"] >= 1) {
        Road road(this);
        roads.push_back(road);
        board.placeStructure(road, placesNum);
        removeResources("wood", 1);
        removeResources("brick", 1);
        std::cout << name << " placed a road." << std::endl;
    } else {
        throw std::runtime_error("Not enough resources to place a road.");
    }
}

Settlement* Player::placeSettlement(int vertexIndex, Board& board) {
    if (resources["wood"] >= 1 && resources["brick"] >= 1 && resources["wool"] >= 1 && resources["wheat"] >= 1) {
        Settlement* settlement = new Settlement(this);
        try {
            board.placeStructure(*settlement, vertexIndex);
            settlements.push_back(*settlement);
            removeResources("wood", 1);
            removeResources("brick", 1);
            removeResources("wool", 1);
            removeResources("wheat", 1);
            std::cout << name << " placed a settlement." << std::endl;
            return settlement;
        } catch (const std::invalid_argument& e) {
            delete settlement; // Clean up to avoid memory leak
            throw; // Re-throw the caught exception
        }
    } else {
        throw std::runtime_error("Not enough resources to place a settlement.");
    }
}
void Player::trade(Player& otherPlayer, const std::string& resourceOffered, const std::string& resourceRequested, int offeredAmount, int requestedAmount) {
    // Check if the player has the offered resource
    if (resources.find(resourceOffered) == resources.end() || resources[resourceOffered] < offeredAmount) {
        throw std::runtime_error("Not enough offered resources for the trade.");
    }
    
    // Check if the other player has the requested resource
    if (otherPlayer.resources.find(resourceRequested) == otherPlayer.resources.end() || otherPlayer.resources[resourceRequested] < requestedAmount) {
        throw std::runtime_error("The other player doesn't have enough requested resources for the trade.");
    }
    
    // Exchange resources between players
    resources[resourceOffered] -= offeredAmount;
    otherPlayer.resources[resourceOffered] += offeredAmount;
    resources[resourceRequested] += requestedAmount;
    otherPlayer.resources[resourceRequested] -= requestedAmount;
    
    std::cout << name << " traded " << offeredAmount << " " << resourceOffered << " for " << requestedAmount << " " << resourceRequested << " with " << otherPlayer.getName() << "." << std::endl;
}

int Player::removeAllResources(const std::string& resourceType) {
    int resourcesRemoved = resources[resourceType]; // Assuming resourceMap holds the resource count for each type
    resources[resourceType] = 0;
    return resourcesRemoved;
}

int Board::getVerticesCount() const {
    return vertices.size();
}

bool Board::hasSettlement(int vertexIndex) const {
    // Check if the vertex index is valid
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::out_of_range("Invalid vertex index.");
    }
    
    // Get the vertex at the specified index
    const Vertex& vertex = vertices[vertexIndex];
    
    // Check if the vertex has a settlement
    return vertex.hasSettlement();
}

Vertex& Board::getVertex(int vertexIndex) {
    // Check if the vertex index is valid
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::out_of_range("Invalid vertex index.");
    }
    
    // Return a reference to the vertex at the specified index
    return vertices[vertexIndex];
}

City* Player::upgradeToCity(Board &board, int vertexIndex) {
    // Check if the player has enough resources
    if (resources["ore"] < 3 || resources["wheat"] < 2) {
        throw std::runtime_error("Not enough resources to upgrade to a city.");
    }
    
    // Check if the specified vertex index is valid
    if (vertexIndex < 0 || vertexIndex >= board.getVerticesCount()) {
        throw std::out_of_range("Invalid vertex index.");
    }
    
    // Get the vertex at the specified index
    Vertex& vertex = board.getVertex(vertexIndex);
    
    // Check if there's a settlement owned by the player at the specified vertex
    if (vertex.getOwner() != this || !vertex.hasSettlement()) {
        throw std::runtime_error("No settlement owned by the player at the specified vertex.");
    }
    
    // Replace the settlement with a city
    City* city =vertex.upgradeToCity();
    addVictoryPoints(1);
    cities.push_back(*city);
    // Deduct resources from the player
    resources["ore"] -= 3;
    resources["wheat"] -= 2;
    
    std::cout << name << " upgraded a settlement to a city." << std::endl;
    return city;
}

int Player::getResources(const std::string &resource) const
{
    return resources.at(resource);
}




void Player::endTurn() {
    isTurn = false;
    std::cout << name << " ended their turn." << std::endl;
}

void Player::printPoints() const {
    std::cout << name << " has " << victoryPoints << " victory points." << std::endl;
}

int Player::getVictoryPoints() const {
    return victoryPoints;
}

void Player::addVictoryPoints(int points)
{
    this->victoryPoints += points;
}

void Player::addResources(const std::string& resource, int amount) {
    resources[resource] += amount;
}

void Player::removeResources(const std::string& resource, int amount) {
    if (resources[resource] < amount) {
        throw std::runtime_error("Not enough resources.");
    }
    resources[resource] -= amount;
}

const std::vector<Settlement> &Player::getSettlements() 
{
    return settlements;}

const std::vector<City> &Player::getCities() 
{
    return cities;}

const std::vector<Road> &Player::getRoads()
{
    return roads;}

    

} // namespace ariel