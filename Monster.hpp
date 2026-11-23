#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>
#include "DungeonEvent.hpp"

class Monster : public DungeonEvent {
public:
    Monster(const std::string& name = "Goblin", int health = 30, int attack = 5);
    void interact(Player& player) override;
    void printInfo() const override;
private:
    std::string name;
    int health, attack;
};

#endif