#include "Trap.hpp"
#include <iostream>

Trap::Trap(int damage) : damage(damage) {

}

void Trap::interact(Player& player) {
    if (!activated) {
        player.takeDamage(damage);
        activated = true;
    }
}

void Trap::printInfo() const {
    std::cout << "=============================\n";
    std::cout << "Trap" << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Activated: " << ((!activated) ? "no" : "yes") << std::endl;
    std::cout << "=============================\n";
}