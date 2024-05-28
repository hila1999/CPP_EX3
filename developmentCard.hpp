#pragma once
#include <string>
namespace ariel {
class Player;  // Forward declaration

class DevelopmentCard {
public:
    virtual ~DevelopmentCard() = default;
    virtual void use(Player& player) = 0;  // Pure virtual function for using the card
    virtual std::string getType() const = 0;  // Pure virtual function to get the card type
};

class Monopoly : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};

class RoadBuilding : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};

class YearOfPlenty : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};

class Knight : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};

class VictoryPoint : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};
}