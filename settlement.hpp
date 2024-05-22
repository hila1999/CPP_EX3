#pragma once
#include "structure.hpp"

class Settlement : public Structure {
public:
    Settlement(Player* owner, const std::string& location);
};
