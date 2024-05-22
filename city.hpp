#pragma once
#include "settlement.hpp"

class City : public Settlement {
public:
    City(Player* owner, const std::string& location);
};
