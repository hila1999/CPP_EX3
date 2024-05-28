#pragma once
#include <string>
namespace ariel {
class Player;  // Forward declaration to avoid circular dependency

class Structure {
protected:
    Player* owner;
    std::string location;

public:
    Structure(Player* owner, const std::string& location);
    virtual ~Structure() = default;

    Player* getOwner() const;
    std::string getLocation() const;
};
}