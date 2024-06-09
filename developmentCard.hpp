#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>
namespace ariel {
class Player;  // Forward declaration

class DevelopmentCard {
public:
    DevelopmentCard() = default; // Default constructor
    virtual ~DevelopmentCard() = default;
    virtual void use(Player& player) = 0;  // Pure virtual function for using the card
    virtual std::string getType() const = 0;  // Pure virtual function to get the card type
};

class Monopoly : public DevelopmentCard {
public:
    void use(Player& player) override;
    void use(Player& player, std::string resourceType);
    std::string getType() const override;
};

class RoadBuilding : public DevelopmentCard {
public:
    void use(Player& player) override;
    void use(Player& player, int road1, int road2);
    std::string getType() const override;
};

class YearOfPlenty : public DevelopmentCard {
public:
    void use(Player& player) override;
    void use(Player& player, std::string resource1, std::string resource2);
    std::string getType() const override;
};

class Knight : public DevelopmentCard {
private:
    Player* owner;
public:
    Knight(Player *owner);
    void use(Player &player) override;
    std::string getType() const override;
};

class VictoryPoint : public DevelopmentCard {
public:
    void use(Player& player) override;
    std::string getType() const override;
};
}
#endif