#include "Monster.hpp"
#include <iostream>

void Monster::printInfo() const {
    std::cout << "=============================\n";
    std::cout << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "=============================\n";
}
