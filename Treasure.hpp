#ifndef TREASURE_HPP
#define TREASURE_HPP

#include <string>
#include "DungeonEvent.hpp"

class Treasure : public DungeonEvent {
public:
    Treasure(int gold);
    void interact(Player& player) override;
    void printInfo() const override;
private:
    int gold_amount;
    bool collected = false;
};

#endif