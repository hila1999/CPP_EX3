#include "Tile.hpp"

namespace ariel {
    // Tile::Tile(Resource res, int num, std::vector<Tile> neighbors, std::vector<int> vertices)
    //     : resource(res), number(num), neighbors(std::move(neighbors)), vertices(std::move(vertices)) {}
   Tile::Tile(Resource res, int num, std::vector<Tile> neighbors, std::vector<int> vertices)
    : resource(res), number(num), neighbors(neighbors), vertices(vertices) {}
   
   Resource Tile::getResource() const
   {
       return resource;
   }

    int Tile::getNumber() const {
        return number;
    }
    
    #include <vector>

    const std::vector<int>& Tile::getVertices() const {
        return vertices;
    }
      void Tile::setVertices(const std::vector<int>& vertexIndices) {
     vertices = vertexIndices;
    }   
    std::string Tile::getResourceName() const {
        switch (resource) {
            case Resource::Wood: return "Wood";
            case Resource::Brick: return "Brick";
            case Resource::Sheep: return "Sheep";
            case Resource::Wheat: return "Wheat";
            case Resource::Ore: return "Ore";
            case Resource::Sea: return "Sea";
            case Resource::None: return "None";
            case Resource::Desert: return "Desert";
            default: return "Unknown";
        }
    }
}
