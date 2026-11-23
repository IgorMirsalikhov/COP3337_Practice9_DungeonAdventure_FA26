#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    Player(int health = 0, int attack = 0, int max_health = 100, int gold = 0); 

    bool takeDamage(int damage); 	// Reduces health, minimum 0.
    bool heal(int amount);          // Restores health, maximum maxHealth.
    void addGold(int amount);	    // Increases gold.
    int getHealth() const;	        // Returns current health.
    int getAttackPower() const;	    // Returns attack power.
    int getGold() const;	        // Returns player's gold amount.
    void printStatus() const;       // Prints player's status

private:
    int health, max_health;
    int attack_power;
    int gold;
};

#endif