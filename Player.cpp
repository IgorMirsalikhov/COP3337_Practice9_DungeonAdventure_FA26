#include "Player.hpp"
#include <iostream>

Player::Player(int health, int attack, int max_health, int gold)
    : health(health), max_health(max_health), attack_power(attack), gold(gold) {

}
 
void Player::printStatus() const {
    std::cout << "=============================\n";
    std::cout << "Player" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Gold: " << gold << std::endl;
    std::cout << "=============================\n";

}
