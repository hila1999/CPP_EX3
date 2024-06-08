//    #ifndef VERTEX_HPP
//    #define VERTEX_HPP
//     #include "Tile.hpp"
//     #include "player.hpp"
//     #include <vector>

//     namespace ariel {
//        class Structure;
//             class Vertex {
//         public:
//             Player* owner;
//             std::vector<Structure*> structures;
//             std::vector<Tile> adjacentTiles;

//             Vertex();

//             // Constructor
//             Vertex(Player* owner , std::vector<Tile> adjacentTiles);

//             // Member functions
//             void addAdjacentTile(const std::vector<Tile>& tiles);
//             Player* getOwner() const;
//             void addStructure(Structure* structure);
//             void setOwner(Player* owner);
// };
//     }

// #endif // VERTEX_HPP