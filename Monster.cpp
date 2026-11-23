#include "Monster.hpp"
#include <iostream>

Monster::Monster(const std::string& name, int health, int attack) 
    : name(name), health(health), attack(attack) {

}

void Monster::interact(Player& player) {
    while (health > 0 && player.getHealth() > 0) {
        health -= player.getAttackPower();
        if (health > 0) {
            player.takeDamage(attack);
        }
    }
}

void Monster::printInfo() const {
    std::cout << "=============================\n";
    std::cout << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "=============================\n";
}