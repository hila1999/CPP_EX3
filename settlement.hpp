#pragma once
#include "structure.hpp"
namespace ariel {
class Settlement : public Structure {
public:
    Settlement(Player* owner, const std::string& location);
};
}