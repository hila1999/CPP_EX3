#pragma once
#include "structure.hpp"
namespace ariel {
class Road : public Structure {
public:
    Road(Player* owner, const std::string& location);
};
}