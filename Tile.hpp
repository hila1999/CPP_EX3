#pragma once
#include <string>
#include <vector>
#include "Board.hpp"
using namespace std;
namespace ariel {
    // Forward declaration of classes from other headers
    class Vertex; // Add this line

    class Structure;

    enum class Resource {
        Wood,
        Brick,
        Wheat,
        Ore,
        Sheep,
        Sea,
        Desert,
        None
    };

    class Tile {
    public:
        int number;
        Resource resource;
        std::vector<Tile> neighbors;
        std::vector<int> vertices;

Tile(Resource res, int num, std::vector<Tile> neighbors = {}, std::vector<int> vertices = {});
   
       ~Tile()=default;
        Resource getResource() const;
        int getNumber() const;
        std::string getResourceName() const;
        const std::vector<int>& getVertices() const;
        void setVertices(const std::vector<int>& vertexIndices);

        void addStructure(Structure* structure);
    };
}
