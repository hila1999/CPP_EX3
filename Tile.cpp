#include "Tile.hpp"

namespace ariel {
    Tile::Tile(int num, Resource res) : number(num), resource(res) {}

    Resource Tile::getResource() const {
        return resource;
    }

    int Tile::getNumber() const {
        return number;
    }

    std::string Tile::getResourceName() const {
        switch (resource) {
            case Resource::Wood: return "Wood";
            case Resource::Brick: return "Brick";
            case Resource::Wool: return "Wool";
            case Resource::Grain: return "Grain";
            case Resource::Ore: return "Ore";
            case Resource::None: return "None";
        }
        return "Unknown";
    }
}