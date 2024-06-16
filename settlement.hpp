//hila.shamir99@gmail.com
//314906983
#pragma once
#include "structure.hpp" // Include the base class definition

namespace ariel {
    class Settlement : public Structure {
    public:
        Settlement(Player* owner); // Define the constructor
        ~Settlement() override=default; // Define the destructor
    };
}