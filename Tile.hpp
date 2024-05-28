#pragma once
#include <string>
namespace ariel {
enum class Resource {
    Wood,
    Brick,
    Wool,
    Grain,
    Ore,
    None
};

class Tile {
private:
    int number;
    Resource resource;

public:
    Tile(int num, Resource res);

    Resource getResource() const;

    int getNumber() const;

    std::string getResourceName() const;
};
}