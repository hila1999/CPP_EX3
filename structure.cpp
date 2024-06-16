//hila.shamir99@gmail.com
//314906983
#include "structure.hpp"

using namespace ariel;

Structure::Structure(Player* owner) : owner(owner) {}

Player* Structure::getOwner() const {
    return owner;
}
