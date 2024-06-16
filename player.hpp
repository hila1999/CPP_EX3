//hila.shamir99@gmail.com
//314906983
#pragma once
#include "structure.hpp"
#include <string>
#include <map>
#include <vector>
#include "Board.hpp"
#include "developmentCard.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"
namespace ariel {
    class Board;
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
    int numOfKnights;

    public:
    Player();// Constructor to initialize resources and victory points
    Player(const std::string& name);
    ~Player();  // Destructor to delete dynamically allocated development cards
    
    bool isTurnPlayer() const;
    void setTurn(bool turn);
    void addKnight();
    int getNumOfKnights() const;
    std::string getName() const;
    void buyDevelopmentCard(Board& board);
    void useDevelopmentCard(Board& board);
    void endTurn();
    void printPoints() const;
    void rollDice(Board &board);
    void placeRoad(int placesNum, Board &board);
    Settlement* placeSettlement(int vertexIndex, Board &board);
    
    void trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);
    int removeAllResources(const std::string &resourceType);
    City* upgradeToCity(Board &board, int vertexIndex);
    int getResources(const std::string& resource) const;
    int getVictoryPoints() const;
    void addVictoryPoints(int points);
    void addResources(const std::string& resource, int amount);
    void removeResources(const std::string& resource, int amount);
    const std::vector<Settlement>& getSettlements() ;
    const std::vector<City>& getCities()  ;
    const std::vector<Road>& getRoads()  ;


};
}