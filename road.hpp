#pragma once
#include "structure.hpp"

class Road : public Structure {
public:
    Road(Player* owner, const std::string& location);
};
