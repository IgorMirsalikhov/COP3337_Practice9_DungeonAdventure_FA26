#ifndef DUNGEON_EVENT_HPP
#define DUNGEON_EVENT_HPP

#include "Player.hpp"

class DungeonEvent {
public:
    virtual void interact(Player& player) = 0;
    virtual void printInfo() const = 0;
private:
};

#endif