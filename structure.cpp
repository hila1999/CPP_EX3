#include "structure.hpp"
#include "player.hpp"

Structure::Structure(Player* owner, const std::string& location) : owner(owner), location(location) {}

Player* Structure::getOwner() const {
    return owner;
}

std::string Structure::getLocation() const {
    return location;
}
