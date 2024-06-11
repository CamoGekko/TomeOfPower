#include <vector>

// Function pointer for getItemIds
vector<int> (*getItemIds)(const std::vector<Item>&) = getItemIds;

// Function pointer for contains
bool (*containsPtr)(const string&, string) = contains;

// Function pointer for initializeItems
std::vector<Item> (*initializeItemsPtr)(Player&) = initializeItems;

// Function pointer for newGame
Game (*newGamePtr)(string) = newGame;

// Function pointer for saveGame
void (*saveGamePtr)(Game) = saveGame;

// Function pointer for loadGame
Game (*loadGamePtr)() = loadGame;

// Function pointer for readFile
char** (*readFilePtr)(const std::string&, int&) = readFile;

// Function pointer for genEnemy
Entity (*genEnemyPtr)(int) = genEnemy;

// Function pointer for initializeItem
void (*initializeItemPtr)(Player&, Item&) = initializeItem;

// Function pointer for generateItem
Item (*generateItemPtr)(Player&) = generateItem;

// Function pointer for outputStats
void (*outputStatsPtr)(Player&) = outputStats;

// Function pointer for updateStats
double (*updateStatsPtr)(Game&, Player&) = updateStats;

// Function pointer for outputInv
void (*outputInvPtr)(const vector<Item>&, const vector<Item>&) = outputInv;

// Function pointer for isValidChoice
bool (*isValidChoicePtr)(int, size_t) = isValidChoice;

// Function pointer for useFood
bool (*useFoodPtr)(Item&, Player&) = useFood;

// Function pointer for useEquipment
bool (*useEquipmentPtr)(Item&, Player&) = useEquipment;

// Function pointer for useSelectedItem
void (*useSelectedItemPtr)(int, Player&, std::vector<Item>&) = useSelectedItem;

// Function pointer for fight
int (*fightPtr)(Game&, Player&, vector<Item>&) = fight;

// Function pointer for explore
string (*explorePtr)() = explore;

// Function pointer for inventoryB
vector<int> (*inventoryBPtr)(vector<int>) = inventoryB;
