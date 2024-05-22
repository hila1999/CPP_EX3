#include "player.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

Player::Player(const std::string& name) : name(name), victoryPoints(2), isTurn(false) {
    // Initialize resources with zero
    resources["wood"] = 0;
    resources["brick"] = 0;
    resources["wool"] = 0;
    resources["grain"] = 0;
    resources["ore"] = 0;
}
Player::~Player() {
    for (DevelopmentCard* card : developmentCards) {
        delete card;
    }
}

std::string Player::getName() const {
    return name;
}

void Player::rollDice() {
    if (!isTurn) {
        throw std::runtime_error("It's not your turn!");
    }
    int diceRoll = rand() % 6 + 1 + rand() % 6 + 1; // Sum of two dice (2-12)
    std::cout << name << " rolled a " << diceRoll << std::endl;
    // Logic to distribute resources based on dice roll
    // This part should be handled by the Board class
}

// void Player::placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
//     if (resources["wood"] >= 1 && resources["brick"] >= 1 && resources["wool"] >= 1 && resources["grain"] >= 1) {
//         Settlement settlement(this);
//         settlements.push_back(settlement);
//         board.placeStructure(settlement, places, placesNum);
//         removeResources("wood", 1);
//         removeResources("brick", 1);
//         removeResources("wool", 1);
//         removeResources("grain", 1);
//         victoryPoints += 1;
//         std::cout << name << " placed a settlement." << std::endl;
//     } else {
//         throw std::runtime_error("Not enough resources to place a settlement.");
//     }
// }

// void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
//     if (resources["wood"] >= 1 && resources["brick"] >= 1) {
//         Road road(this);
//         roads.push_back(road);
//         board.placeStructure(road, places, placesNum);
//         removeResources("wood", 1);
//         removeResources("brick", 1);
//         std::cout << name << " placed a road." << std::endl;
//     } else {
//         throw std::runtime_error("Not enough resources to place a road.");
//     }
// }

// void Player::upgradeToCity(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
//     if (resources["ore"] >= 3 && resources["grain"] >= 2) {
//         City city(this);
//         cities.push_back(city);
//         board.upgradeStructure(city, places, placesNum);
//         removeResources("ore", 3);
//         removeResources("grain", 2);
//         victoryPoints += 1; // Net gain of 1 point, 2 for city - 1 for settlement
//         std::cout << name << " upgraded a settlement to a city." << std::endl;
//     } else {
//         throw std::runtime_error("Not enough resources to upgrade to a city.");
//     }
// }

// void Player::trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount) {
//     if (resources[giveResource] >= giveAmount && other.resources[getResource] >= getAmount) {
//         removeResources(giveResource, giveAmount);
//         other.removeResources(getResource, getAmount);
//         addResources(getResource, getAmount);
//         other.addResources(giveResource, giveAmount);
//         std::cout << name << " traded " << giveAmount << " " << giveResource << " for " << getAmount << " " << getResource << " with " << other.getName() << "." << std::endl;
//     } else {
//         throw std::runtime_error("Trade cannot be completed due to insufficient resources.");
//     }
// }

// void Player::buyDevelopmentCard() {
//     if (resources["ore"] >= 1 && resources["wool"] >= 1 && resources["grain"] >= 1) {
//         // For simplicity, assuming a new generic development card is created
//         DevelopmentCard* card = new DevelopmentCard(); // This should be a specific card like KnightCard
//         developmentCards.push_back(card);
//         removeResources("ore", 1);
//         removeResources("wool", 1);
//         removeResources("grain", 1);
//         std::cout << name << " bought a development card." << std::endl;
//     } else {
//         throw std::runtime_error("Not enough resources to buy a development card.");
//     }
// }

// void Player::useDevelopmentCard() {
//     if (!developmentCards.empty()) {
//         DevelopmentCard* card = developmentCards.back();
//         card->use();
//         developmentCards.pop_back();
//         delete card;
//         std::cout << name << " used a development card." << std::endl;
//     } else {
//         throw std::runtime_error("No development cards to use.");
//     }
// }

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

void Player::addResources(const std::string& resource, int amount) {
    resources[resource] += amount;
}

void Player::removeResources(const std::string& resource, int amount) {
    if (resources[resource] < amount) {
        throw std::runtime_error("Not enough resources.");
    }
    resources[resource] -= amount;
}
