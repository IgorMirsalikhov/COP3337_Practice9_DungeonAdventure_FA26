#include "Player.hpp"
#include <iostream>

Player::Player(int health, int attack, int max_health, int gold)
    : health(health), max_health(max_health), attack_power(attack), gold(gold) {

}



bool Player::takeDamage(int damage) {
    health = (damage >= health) ? 0 : health - damage;

    return (health == 0) ? true : false;
}

bool Player::heal(int amount) {
    health = ((health + amount) >= max_health) ? max_health : health + amount;

    return (health == max_health) ? true : false;
}   

void Player::addGold(int amount) {
    gold += amount;
}

int Player::getHealth() const {
    return health;
}	

int Player::getAttackPower() const {
    return attack_power;
}

int Player::getGold() const {
    return gold;
}
 
void Player::printStatus() const {
    std::cout << "=============================\n";
    std::cout << "Player" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Gold: " << gold << std::endl;
    std::cout << "=============================\n";

}