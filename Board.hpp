#pragma once
#include "Tile.hpp"
#include "city.hpp"
#include "player.hpp"
#include "structure.hpp"
#include <vector>
using namespace std;
namespace ariel {
    class Tile;
     class Player;
     
    class Vertex {
public:
    Player* owner;
    std::vector<Structure*> structures;
    std::vector<Tile> adjacentTiles;

    Vertex();

    // Constructor
    Vertex(Player* owner , std::vector<Tile> adjacentTiles);
    ~Vertex() ;

    // Member functions
    void addAdjacentTile(const std::vector<Tile>& tiles);
    Player* getOwner() const;
    void addStructure(Structure* structure);
    bool hasSettlement() const;
    City* upgradeToCity();
    void setOwner(Player *owner);
    
};


    class Edge {
    private:
        int id;
        Player* owner;
    public:
        std::vector<int> neighbors_vertice;
        std::vector<Structure*> structures;
        Edge();
        Edge(int id, Player* owner, vector<int> neighbors_vertice);
        Player* getOwner() const;
        void setOwner(Player *owner);
        void addStructure(Structure *structure);
        ~Edge() = default;
    };

    class Board {
    private:
        std::vector<Tile> tiles;
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Player*> players; // Container to hold all players

    public:
        
        Board();
        void make();
        Tile& getTile(int number);
        const std::vector<Tile>& getTiles() const;
        std::vector<Vertex>& getVertices() ;
        void distributeResources(int diceRoll);
        void placeStructure(Structure &structure, int vertexIndex);
        void placeRoad(Structure &structure, int edgeIndex);
        int getVerticesCount() const;
        bool hasSettlement(int vertexIndex) const;
        Vertex &getVertex(int vertexIndex);
        void addPlayer(Player& player); // Method to add a player to the game
        std::vector<Player*>& getPlayers(); // Method to get all players by reference

    static int knightCount;
    static int victoryPointCount;
    static const int MAX_KNIGHT_CARDS = 3;
    static const int MAX_VICTORY_POINT_CARDS = 4;
    };
}
