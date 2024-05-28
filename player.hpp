#pragma once
#include <string>
#include <map>
#include <vector>
#include "Board.hpp"
#include "developmentCard.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"
namespace ariel {
class Player {
private:
    

    std::string name;
    std::map<std::string, int> resources;
    std::vector<Settlement> settlements;
    std::vector<City> cities;
    std::vector<Road> roads;
    std::vector<DevelopmentCard*> developmentCards;
    int victoryPoints;
    bool isTurn;

    public:
    Player();// Constructor to initialize resources and victory points
    Player(const std::string& name);
    ~Player();  // Destructor to delete dynamically allocated development cards


    std::string getName() const;

    void rollDice();
    void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void upgradeToCity(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);
    void buyDevelopmentCard();
    void useDevelopmentCard();
    void endTurn();

    void printPoints() const;

    int getVictoryPoints() const;

    void addResources(const std::string& resource, int amount);
    void removeResources(const std::string& resource, int amount);
};
}