//hila.shamir99@gmail.com
//314906983
#pragma once
#include <string>
namespace ariel {
class Player;  // Forward declaration to avoid circular dependency

class Structure {
protected:
    Player* owner;
    

public:
    Structure(Player* owner);
    virtual ~Structure() = default;

    Player* getOwner() const;
    
};
}
// #pragma once
// #include "player.hpp" // Include the Player class definition

// namespace ariel {
//     class Player;
//     class Structure {
//     private:
//         Player* owner;
//     public:
//         Structure(Player* owner);
//         virtual ~Structure() = default;
//         Player* getOwner() const;
//     };
// }

