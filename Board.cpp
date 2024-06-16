#include "Board.hpp"
#include "Tile.hpp"
#include "player.hpp"
#include "structure.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <string>
#include <map>
//hila.shamir99@gmail.com
//314906983

namespace ariel {
    Vertex::Vertex() : owner(nullptr) {}
    Vertex::Vertex(Player *owner, std::vector<Tile> adjacentTiles) : owner(owner), adjacentTiles(adjacentTiles) {}
    Vertex::~Vertex()
    {
        
    }
    
    void Vertex::addAdjacentTile(const std::vector<Tile>& tiles) {
        adjacentTiles.insert(adjacentTiles.end(), tiles.begin(), tiles.end());
    }
    
    Player* Vertex::getOwner() const {
        return owner;
    }
    
    void Vertex::addStructure(Structure* structure) {
        structures.push_back(structure);
    }
     // Function to check if the vertex has a settlement
     bool Vertex::hasSettlement() const {
    // Check if the structures vector contains a settlement
        for (const auto& structure : structures) {
            if (dynamic_cast<Settlement*>(structure) != nullptr) {
             return true;
            }
     }
     return false;
    }

    City* Vertex::upgradeToCity() {
        // Find the settlement in the structures vector
        for (auto it = structures.begin(); it != structures.end(); ++it) {
            Settlement* settlement = dynamic_cast<Settlement*>(*it);
            if (settlement != nullptr) {
                // Replace the settlement with a city
                City* city = new City(settlement->getOwner()); // Assuming City constructor takes a Player* parameter
                delete *it; // Delete the settlement
                *it = city;
                return city; 
            }
        }
    }
    
    Edge::Edge() : owner(nullptr)
    {
    }

    Edge::Edge(int id, Player *owner, std::vector<int> neighbors_vertice) : id(id), owner(nullptr), neighbors_vertice(neighbors_vertice) {}

    Player* Edge::getOwner() const {
        return owner;
    }
    
    void Edge::setOwner(Player* owner){
        this->owner = owner;
    }
   
    void Edge::addStructure(Structure* structure) {
        structures.push_back(structure);
    }
    

    int Board::knightCount = 0;
    int Board::victoryPointCount = 0;
    // const int Board::MAX_KNIGHT_CARDS = 3;
    // const int Board::MAX_VICTORY_POINT_CARDS = 4;
    
    void Board::make(){ 
            Tile tile1 = Tile(Resource::Wood, 11,{Tile(Resource::Brick, 2),Tile(Resource::Wheat, 4),Tile(Resource::Ore, 5),Tile(Resource::Sea,0)});
            Tile tile2 = Tile(Resource::Brick, 2,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Sheep, 3),Tile(Resource::Sea,0)});
            Tile tile3 = Tile(Resource::Sheep, 3,{tile2,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Brick, 11),Tile(Resource::Sea,0)});
            Tile tile4 = Tile(Resource::Wheat, 4,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
            Tile tile5 = Tile(Resource::Ore, 5,{tile1,tile2,tile4,Tile(Resource::Wood, 6),Tile(Resource::Wheat, 9),Tile(Resource::Desert, 7)});
            Tile tile6 = Tile(Resource::Wood, 6,{tile5,tile2,tile3,Tile(Resource::Brick, 11),Tile(Resource::Wood, 10),Tile(Resource::Desert, 7)});
            Tile tile7 = Tile(Resource::Brick, 11,{tile6,tile3,Tile(Resource::Wood, 10),Tile(Resource::Wood, 10),Tile(Resource::Sea, 0)});
            Tile tile8 = Tile(Resource::Sheep, 8,{tile4,Tile(Resource::Wheat, 9),Tile(Resource::Wheat, 3),Tile(Resource::Sea, 0)});
            Tile tile9 = Tile(Resource::Wheat, 9,{tile4,tile5,tile8,Tile(Resource::Wheat, 3),Tile(Resource::Ore, 4),Tile(Resource::Desert, 7)});
            Tile tile10 = Tile(Resource::Desert, 7,{tile9,tile5,tile6,Tile(Resource::Wood, 10),Tile(Resource::Wood, 5),Tile(Resource::Ore, 4)});
            Tile tile11 = Tile(Resource::Wood, 10,{tile6,tile7,tile10,Tile(Resource::Sheep, 12),Tile(Resource::Ore, 6),Tile(Resource::Wood, 5)});
            Tile tile12 = Tile(Resource::Sheep, 12,{tile7,tile11,Tile(Resource::Brick, 6),Tile(Resource::Sea, 0)});
            Tile tile13 = Tile(Resource::Wheat, 3,{tile8,tile9,Tile(Resource::Ore, 4),Tile(Resource::Sheep, 8),Tile(Resource::Sea, 0)});
            Tile tile14 = Tile(Resource::Ore, 4,{tile13,tile9,tile10,Tile(Resource::Wood, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
            Tile tile15 = Tile(Resource::Wood, 5,{tile14,tile10,tile11,Tile(Resource::Brick, 6),Tile(Resource::Brick, 10),Tile(Resource::Wheat, 9)});
            Tile tile16 = Tile(Resource::Brick, 6,{tile15,tile11,tile12,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
            Tile tile17 = Tile(Resource::Sheep, 8,{tile13,tile14,Tile(Resource::Wheat, 9),Tile(Resource::Sea, 0)});
            Tile tile18 = Tile(Resource::Wheat, 9,{tile17,tile14,tile15,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
            Tile tile19 = Tile(Resource::Brick, 10,{tile18,tile15,tile16,Tile(Resource::Sea, 0)});
            tile1.setVertices({4, 5, 6, 11, 12, 13});
            tile2.setVertices({2, 3, 4, 9, 10, 11});
            tile3.setVertices({0, 1, 2, 7, 8, 9});
            tile4.setVertices({13, 14, 12, 25, 24, 23});
            tile5.setVertices({11, 12, 10, 22, 21, 23});
            tile6.setVertices({9, 10, 8, 20, 19, 21});
            tile7.setVertices({7, 8, 15, 18, 17, 19});
            tile8.setVertices({26, 24, 25, 27, 28, 29});
            tile9.setVertices({23, 24, 22, 30, 31, 29});
            tile10.setVertices({21, 22, 20, 33, 32, 31});
            tile11.setVertices({19, 20, 18, 35, 34, 33});
            tile12.setVertices({17, 18, 16, 37, 36, 35});
            tile13.setVertices({29, 30, 28, 46, 45, 44});
            tile14.setVertices({30, 31, 32, 44, 43, 42});
            tile15.setVertices({34, 32, 33, 42, 41, 40});
            tile16.setVertices({36, 34, 35, 40, 39, 38});
            tile17.setVertices({44, 45, 43, 47, 48, 49});
            tile18.setVertices({42, 43, 41, 51, 50, 49});
            tile19.setVertices({40, 41, 39, 53, 52, 51});

            // Simplified board with fixed resources and numbers
                    
            tiles = {tile1,tile2,tile3,tile4,tile5,tile6,tile7,
                tile8,tile9,tile10,tile11,tile12,tile13,
                tile14,tile15,tile16,tile17,tile18,tile19
            };

            // Create vertices
            vertices.resize(54);
            vertices[0].addAdjacentTile({tile3});
            vertices[1].addAdjacentTile({tile3});
            vertices[2].addAdjacentTile({tile3,tile2});
            vertices[3].addAdjacentTile({tile2});
            vertices[4].addAdjacentTile({tile2,tile1});
            vertices[5].addAdjacentTile({tile1});
            vertices[6].addAdjacentTile({tile1});
            vertices[7].addAdjacentTile({tile3,tile7});
            vertices[8].addAdjacentTile({tile3,tile6,tile7});;
            vertices[9].addAdjacentTile({tile2,tile3,tile6});
            vertices[10].addAdjacentTile({tile2,tile5,tile6});
            vertices[11].addAdjacentTile({tile2,tile1,tile5});
            vertices[12].addAdjacentTile({tile1,tile4,tile5});
            vertices[13].addAdjacentTile({tile1,tile4});
            vertices[14].addAdjacentTile({tile4});
            vertices[15].addAdjacentTile({tile7});
            vertices[16].addAdjacentTile({tile12});
            vertices[17].addAdjacentTile({tile7,tile12});
            vertices[18].addAdjacentTile({tile7,tile11,tile12});
            vertices[19].addAdjacentTile({tile6,tile7,tile11});
            vertices[20].addAdjacentTile({tile6,tile10,tile11});
            vertices[21].addAdjacentTile({tile5,tile6,tile10});
            vertices[22].addAdjacentTile({tile5,tile9,tile10});
            vertices[23].addAdjacentTile({tile4,tile5,tile9});
            vertices[24].addAdjacentTile({tile4,tile8,tile9});
            vertices[25].addAdjacentTile({tile4,tile8});
            vertices[26].addAdjacentTile({tile8});
            vertices[27].addAdjacentTile({tile8});
            vertices[28].addAdjacentTile({tile8,tile13});
            vertices[29].addAdjacentTile({tile8,tile9,tile13});
            vertices[30].addAdjacentTile({tile9,tile13,tile14});
            vertices[31].addAdjacentTile({tile9,tile10,tile14});
            vertices[32].addAdjacentTile({tile10,tile14,tile15});
            vertices[33].addAdjacentTile({tile10,tile11,tile15});
            vertices[34].addAdjacentTile({tile11,tile15,tile16});
            vertices[35].addAdjacentTile({tile11,tile12,tile16});
            vertices[36].addAdjacentTile({tile12,tile16});
            vertices[37].addAdjacentTile({tile12});
            vertices[38].addAdjacentTile({tile16});
            vertices[39].addAdjacentTile({tile16,tile19});
            vertices[40].addAdjacentTile({tile15,tile16,tile19});
            vertices[41].addAdjacentTile({tile15,tile18,tile19});
            vertices[42].addAdjacentTile({tile14,tile15,tile18});
            vertices[43].addAdjacentTile({tile14,tile18,tile17});
            vertices[44].addAdjacentTile({tile13,tile14,tile17});
            vertices[45].addAdjacentTile({tile13,tile17});
            vertices[46].addAdjacentTile({tile13});
            vertices[47].addAdjacentTile({tile17});
            vertices[48].addAdjacentTile({tile17});
            vertices[49].addAdjacentTile({tile17,tile18});
            vertices[50].addAdjacentTile({tile18});
            vertices[51].addAdjacentTile({tile18,tile19});
            vertices[52].addAdjacentTile({tile19});
            vertices[53].addAdjacentTile({tile19});
            

            edges.resize(70);
              // Manually setting neighbors based on a Catan-like hexagonal layout
            edges[0].neighbors_vertice = {0, 1};
            edges[1].neighbors_vertice = {1, 2};
            edges[2].neighbors_vertice = {2, 3};
            edges[3].neighbors_vertice = {3, 4};
            edges[4].neighbors_vertice = {4, 5};
            edges[5].neighbors_vertice = {5, 6};
            edges[6].neighbors_vertice = {0, 7};
            edges[7].neighbors_vertice = {2, 9};
            edges[8].neighbors_vertice = {4, 11};// i changed 2 to 23
            edges[9].neighbors_vertice = {6, 13};
            edges[10].neighbors_vertice = {7, 8};
            edges[11].neighbors_vertice = {8, 9};
            edges[12].neighbors_vertice = {9, 10};
            edges[13].neighbors_vertice = {10, 11};
            edges[14].neighbors_vertice = {11, 12};
            edges[15].neighbors_vertice = {12, 13};
            edges[16].neighbors_vertice = {13, 14};
            edges[17].neighbors_vertice = {15, 17};
            edges[18].neighbors_vertice = {8, 19};
            edges[19].neighbors_vertice = {10, 21};
            edges[20].neighbors_vertice = {12, 23};
            edges[21].neighbors_vertice = {14, 25};
            edges[22].neighbors_vertice = {17, 18};
            edges[23].neighbors_vertice = {18, 19};
            edges[24].neighbors_vertice = {19, 20};
            edges[25].neighbors_vertice = {20, 21};
            edges[26].neighbors_vertice = {21, 22};
            edges[27].neighbors_vertice = {22, 23};
            edges[28].neighbors_vertice = {23, 24};
            edges[29].neighbors_vertice = {24, 25};
            edges[30].neighbors_vertice = {25, 26};
            edges[31].neighbors_vertice = {16, 37};
            edges[32].neighbors_vertice = {18, 35};
            edges[33].neighbors_vertice = {20, 33};
            edges[34].neighbors_vertice = {22, 31};
            edges[35].neighbors_vertice = {24, 29};
            edges[36].neighbors_vertice = {26, 27};
            edges[37].neighbors_vertice = {36, 37};
            edges[38].neighbors_vertice = {35, 36};
            edges[39].neighbors_vertice = {34, 35};
            edges[40].neighbors_vertice = {34, 33};
            edges[41].neighbors_vertice = {32, 33};
            edges[42].neighbors_vertice = {32, 31};
            edges[43].neighbors_vertice = {31, 30};
            edges[44].neighbors_vertice = {30, 29};
            edges[45].neighbors_vertice = {29, 28};
            edges[46].neighbors_vertice = {28, 27};
            edges[47].neighbors_vertice = {36, 38};
            edges[48].neighbors_vertice = {34, 40};
            edges[49].neighbors_vertice = {32, 42};
            edges[50].neighbors_vertice = {30, 44};
            edges[51].neighbors_vertice = {46, 28};
            edges[52].neighbors_vertice = {38, 39};
            edges[53].neighbors_vertice = {39, 40};
            edges[54].neighbors_vertice = {40, 41};
            edges[55].neighbors_vertice = {41, 42};
            edges[56].neighbors_vertice = {42, 43};
            edges[57].neighbors_vertice = {43, 44};
            edges[58].neighbors_vertice = {44, 45};
            edges[59].neighbors_vertice = {45, 46};
            edges[60].neighbors_vertice = {39, 53};
            edges[61].neighbors_vertice = {41, 51};
            edges[62].neighbors_vertice = {43, 49};
            edges[63].neighbors_vertice = {45, 47};
            edges[64].neighbors_vertice = {52, 53};
            edges[65].neighbors_vertice = {51, 52};
            edges[66].neighbors_vertice = {50, 51};
            edges[67].neighbors_vertice = {49, 50};
            edges[68].neighbors_vertice = {48, 49};
            edges[69].neighbors_vertice = {48, 47};
            
            }
    
    Board::Board() {
        make();
    }

    Tile& Board::getTile(int number) {
        for (auto& tile : tiles) {
            if (tile.getNumber() == number) {
                return tile;
            }
        }
        throw std::out_of_range("Tile not found");
    }

    const std::vector<Tile>& Board::getTiles() const {
        return tiles;
    }
    std::vector<Vertex> &Board::getVertices()
    {
          return vertices;    }

    
    void Board::distributeResources(int diceRoll) {
        cout << "Distributing resources for dice roll " << diceRoll << endl;
    for (const auto& tile : tiles) {
        if (tile.getNumber() == diceRoll) {
            const std::vector<int>& verticesIndices = tile.getVertices();
            for (const auto& vertexIndex : verticesIndices) {
                if (vertexIndex >= 0 && vertexIndex < vertices.size()) {
                    Player* owner = vertices[vertexIndex].getOwner();
                    if (owner != nullptr) {
                        owner->addResources(tile.getResourceName(), 1);
                        std::cout << owner->getName() << " receives " << tile.getResourceName() << " from tile " << tile.getNumber() << std::endl;
                        
                    }
                }
            }
        }
    }
}

    
    void Vertex::setOwner(Player* owner) {
        this->owner = owner;
        
    }
   
    void Board::placeStructure(Structure& structure, int vertexIndex) {
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::out_of_range("Invalid vertex index");
    }
    
    if (vertices[vertexIndex].getOwner() != nullptr) {
        throw std::invalid_argument("Vertex already has an owner");
    }
    Vertex& vertex = vertices[vertexIndex];
    vertex.setOwner(structure.getOwner());
    // Assuming each vertex has a method to add a structure
    vertices[vertexIndex].addStructure(&structure);
    // structure.getOwner()->addVictoryPoints(1);
    
    std::cout << "Placed " << typeid(structure).name() << " at vertex " << vertexIndex << std::endl;
}
    void Board::placeRoad(Structure& structure, int edgeIndex) {
    if (edgeIndex < 0 || edgeIndex >= edges.size()) {
        throw std::out_of_range("Invalid edge index");
    }
     Edge& edge = edges[edgeIndex];
    if (edge.getOwner() != nullptr) {
        throw std::invalid_argument("Edge already has an owner");
    }
    for (int neighborId : edges[edgeIndex].neighbors_vertice){
        Vertex& vertex = vertices[neighborId];
        if(vertex.owner==structure.getOwner()){
        edges[edgeIndex].setOwner(structure.getOwner());
    // Assuming each edge has a method to add a structure
        edges[edgeIndex].addStructure(&structure);
        std::cout << "Placed " << typeid(structure).name() << " at edge " << edgeIndex << std::endl;
         break;
        }
    }
    
}
 
    void Board::addPlayer(Player &player)
{
    players.push_back(&player);
}


std::vector<Player *> &Board::getPlayers()
{
    return players;}
}
