#ifndef TRAP_HPP
#define TRAP_HPP

#include <string>
#include "DungeonEvent.hpp"

class Trap : public DungeonEvent {
public:
    Trap(int damage);
    void interact(Player& player) override;
    void printInfo() const override;
private:
    int damage; 
    bool activated = false;
};

#endif