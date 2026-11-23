#include "Treasure.hpp"
#include <iostream>

Treasure::Treasure(int amount) : gold_amount(amount) {

}

void Treasure::interact(Player& player) {
    if (!collected) {
        player.addGold(gold_amount);
        collected = true;
    }
}

void Treasure::printInfo() const {
    std::cout << "=============================\n";
    std::cout << "Treasure" << std::endl;
    std::cout << "Amount: " << gold_amount << std::endl;
    std::cout << "Collected: " << ((!collected) ? "no" : "yes") << std::endl;
    std::cout << "=============================\n";
}