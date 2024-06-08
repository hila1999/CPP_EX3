#pragma once
#include "settlement.hpp"
namespace ariel {
class City : public Settlement {
public:
    City(Player* owner);
};
}