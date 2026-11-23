
#include <iostream>
#include <vector>
#include <string>

#include "Player.hpp"
#include "DungeonEvent.hpp"
#include "Monster.hpp"
#include "Treasure.hpp"
#include "Trap.hpp"

using namespace std;

int passed = 0;
int failed = 0;

void check(const string& test, int actual, int expected) {
    if (actual == expected) {
        cout << "[PASS] " << test << endl;
        passed++;
    } else {
        cout << "[FAIL] " << test
             << " | Expected: " << expected
             << " | Actual: " << actual << endl;
        failed++;
    }
}

int main() {
    // =========================================
    // TEST 1: COMPLETE DUNGEON
    // =========================================
    cout << "\n===== TEST 1: COMPLETE DUNGEON =====\n";

    Player player(100, 15);

    Monster goblin("Goblin", 30, 5);
    Monster orc("Orc", 50, 10);
    Treasure treasure1(25);
    Treasure treasure2(50);
    Trap trap(20);

    vector<DungeonEvent*> dungeon = {
        &treasure1, &goblin, &trap, &orc, &treasure2
    };

    vector<int> expectedHealth = {100, 95, 75, 45, 45};
    vector<int> expectedGold = {25, 25, 25, 25, 75};

    bool completed = true;

    for (int i = 0; i < dungeon.size(); i++) {
        cout << "\n--- Room " << i + 1 << " ---\n";

        dungeon[i]->printInfo();
        dungeon[i]->interact(player);
        player.printStatus();

        check("Health after room " + to_string(i + 1),
              player.getHealth(), expectedHealth[i]);

        check("Gold after room " + to_string(i + 1),
              player.getGold(), expectedGold[i]);

        if (player.getHealth() <= 0) {
            completed = false;
            break;
        }
    }

    check("Dungeon completed", completed, true);

    // =========================================
    // TEST 2: REPEATED INTERACTIONS
    // =========================================
    cout << "\n===== TEST 2: REPEATED INTERACTIONS =====\n";

    treasure1.interact(player);
    treasure2.interact(player);
    trap.interact(player);

    check("Treasure cannot be collected twice",
          player.getGold(), 75);

    check("Trap cannot activate twice",
          player.getHealth(), 45);

    cout << "\nObject states after interaction:\n";
    treasure1.printInfo();
    trap.printInfo();

    // =========================================
    // TEST 3: ONE-HIT KILL
    // =========================================
    cout << "\n===== TEST 3: ONE-HIT KILL =====\n";

    Player strongPlayer(100, 50);
    Monster weakMonster("Rat", 20, 99);

    weakMonster.interact(strongPlayer);

    check("Monster cannot attack after dying",
          strongPlayer.getHealth(), 100);

    // =========================================
    // TEST 4: PLAYER DEATH
    // =========================================
    cout << "\n===== TEST 4: PLAYER DEATH =====\n";

    Player weakPlayer(20, 5);
    Monster boss("Dragon", 100, 30);

    boss.interact(weakPlayer);

    check("Player dies during combat",
          weakPlayer.getHealth(), 0);

    // =========================================
    // TEST 5: LETHAL TRAP
    // =========================================
    cout << "\n===== TEST 5: LETHAL TRAP =====\n";

    Player trappedPlayer(10, 10);
    Trap deadlyTrap(50);

    deadlyTrap.interact(trappedPlayer);

    check("Health cannot become negative",
          trappedPlayer.getHealth(), 0);

    deadlyTrap.interact(trappedPlayer);

    check("Deadly trap activates only once",
          trappedPlayer.getHealth(), 0);

    // =========================================
    // TEST 6: DUNGEON GAME OVER
    // =========================================
    cout << "\n===== TEST 6: DUNGEON GAME OVER =====\n";

    Player player2(20, 10);
    Treasure firstTreasure(10);
    Trap fatalTrap(30);
    Treasure lastTreasure(100);

    vector<DungeonEvent*> dangerousDungeon = {
        &firstTreasure, &fatalTrap, &lastTreasure
    };

    bool survived = true;

    for (DungeonEvent* event : dangerousDungeon) {
        event->interact(player2);

        if (player2.getHealth() <= 0) {
            survived = false;
            cout << "GAME OVER!\n";
            break;
        }
    }

    check("Player dies in dungeon",
          survived, false);

    check("Rooms after death are not processed",
          player2.getGold(), 10);

    // =========================================
    // TEST 7: REPEATED MONSTER INTERACTION
    // =========================================
    cout << "\n===== TEST 7: DEFEATED MONSTER =====\n";

    Player player3(50, 20);
    Monster skeleton("Skeleton", 15, 10);

    skeleton.interact(player3);
    check("First fight", player3.getHealth(), 50);

    skeleton.interact(player3);
    check("Defeated monster cannot attack again",
          player3.getHealth(), 50);

    // =========================================
    // FINAL RESULTS
    // =========================================
    cout << "\n=============================\n";
    cout << "TEST RESULTS\n";
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;
    cout << "=============================\n";

    return failed == 0 ? 0 : 1;
}
