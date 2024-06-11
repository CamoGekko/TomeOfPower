#include "struct.hpp"

vector<int> getItemIds(const std::vector<Item>& vec) {
    std::vector<int> existingIds;
    for (const auto& item : vec) {
        if (item.id != 0) { // Assuming 0 means the element doesn't exist
            existingIds.push_back(item.id);
        }
    }
    return existingIds;
}

bool contains(const string& str, string term) {
    return str.find(term) != string::npos;
}

std::vector<Item> initializeItems(Player& player) {
    std::vector<Item> itemsVector;

    // Tier One Sword and Shields (25 items)
    itemsVector.push_back({0, "Wood Sword", 0.09, 3, 0});
    itemsVector.push_back({1, "Wood Shield", 0.13, 0, 2});
    itemsVector.push_back({2, "Stone Sword", 0.12, 4, 0});
    itemsVector.push_back({3, "Stone Shield", 0.20, 0, 3});
    itemsVector.push_back({4, "Iron Sword", 0.18, 6, 0});
    itemsVector.push_back({5, "Iron Shield", 0.25, 0, 5});
    itemsVector.push_back({6, "Tin Sword", 0.10, 4, 0});
    itemsVector.push_back({7, "Tin Shield", 0.14, 0, 3});
    itemsVector.push_back({8, "Tungsten Sword", 0.22, 8, 0});
    itemsVector.push_back({9, "Tungsten Shield", 0.30, 0, 7});
    itemsVector.push_back({10, "Copper Sword", 0.16, 5, 0});
    itemsVector.push_back({11, "Copper Shield", 0.22, 0, 4});
    itemsVector.push_back({12, "Bronze Sword", 0.15, 5, 0});
    itemsVector.push_back({13, "Bronze Shield", 0.20, 0, 4});
    itemsVector.push_back({14, "Silver Sword", 0.17, 6, 0});
    itemsVector.push_back({15, "Silver Shield", 0.25, 0, 5});
    itemsVector.push_back({16, "Gold Sword", 0.18, 7, 0});
    itemsVector.push_back({17, "Gold Shield", 0.27, 0, 6});
    itemsVector.push_back({18, "Platinum Sword", 0.20, 8, 0});
    itemsVector.push_back({19, "Platinum Shield", 0.30, 0, 7});
    itemsVector.push_back({20, "Diamond Sword", 0.25, 10, 0});
    itemsVector.push_back({21, "Diamond Shield", 0.35, 0, 9});
    itemsVector.push_back({22, "Emerald Sword", 0.23, 9, 0});
    itemsVector.push_back({23, "Emerald Shield", 0.33, 0, 8});
    itemsVector.push_back({24, "Ruby Sword", 0.24, 9, 0});
    itemsVector.push_back({25, "Ruby Shield", 0.34, 0, 9});

    // Tier Two Swords and Shields (25 items)
    itemsVector.push_back({26, "Double Edged Wood Sword", 0.11, 5, 0});
    itemsVector.push_back({27, "Reinforced Wood Shield", 0.15, 0, 4});
    itemsVector.push_back({28, "Double Edged Stone Sword", 0.14, 6, 0});
    itemsVector.push_back({29, "Reinforced Stone Shield", 0.22, 0, 5});
    itemsVector.push_back({30, "Double Edged Iron Sword", 0.20, 8, 0});
    itemsVector.push_back({31, "Reinforced Iron Shield", 0.27, 0, 7});
    itemsVector.push_back({32, "Double Edged Tin Sword", 0.12, 5, 0});
    itemsVector.push_back({33, "Reinforced Tin Shield", 0.16, 0, 4});
    itemsVector.push_back({34, "Double Edged Tungsten Sword", 0.26, 10, 0});
    itemsVector.push_back({35, "Reinforced Tungsten Shield", 0.34, 0, 9});
    itemsVector.push_back({36, "Double Edged Copper Sword", 0.19, 7, 0});
    itemsVector.push_back({37, "Reinforced Copper Shield", 0.26, 0, 6});
    itemsVector.push_back({38, "Double Edged Bronze Sword", 0.17, 6, 0});
    itemsVector.push_back({39, "Reinforced Bronze Shield", 0.23, 0, 5});
    itemsVector.push_back({40, "Double Edged Silver Sword", 0.21, 8, 0});
    itemsVector.push_back({41, "Reinforced Silver Shield", 0.28, 0, 7});
    itemsVector.push_back({42, "Double Edged Gold Sword", 0.22, 9, 0});
    itemsVector.push_back({43, "Reinforced Gold Shield", 0.30, 0, 8});
    itemsVector.push_back({44, "Double Edged Platinum Sword", 0.24, 10, 0});
    itemsVector.push_back({45, "Reinforced Platinum Shield", 0.32, 0, 9});
    itemsVector.push_back({46, "Double Edged Diamond Sword", 0.28, 12, 0});
    itemsVector.push_back({47, "Reinforced Diamond Shield", 0.36, 0, 11});
    itemsVector.push_back({48, "Double Edged Emerald Sword", 0.26, 11, 0});
    itemsVector.push_back({49, "Reinforced Emerald Shield", 0.34, 0, 10});
    itemsVector.push_back({50, "Double Edged Ruby Sword", 0.27, 11, 0});
    itemsVector.push_back({51, "Reinforced Ruby Shield", 0.35, 0, 11});

    // Armor (25 items)
    itemsVector.push_back({52, "Wooden Greaves", 0.14, 0, 3});
    itemsVector.push_back({53, "Wooden Chestplate", 0.20, 0, 4});
    itemsVector.push_back({54, "Stone Greaves", 0.18, 0, 4});
    itemsVector.push_back({55, "Stone Chestplate", 0.26, 0, 5});
    itemsVector.push_back({56, "Iron Greaves", 0.21, 0, 6});
    itemsVector.push_back({57, "Iron Chestplate", 0.27, 0, 7});
    itemsVector.push_back({58, "Tin Greaves", 0.16, 0, 4});
    itemsVector.push_back({59, "Tin Chestplate", 0.21, 0, 5});
    itemsVector.push_back({60, "Tungsten Greaves", 0.46, 0, 14});
    itemsVector.push_back({61, "Tungsten Chestplate", 0.58, 0, 20});
    itemsVector.push_back({62, "Copper Greaves", 0.22, 0, 7});
    itemsVector.push_back({63, "Copper Chestplate", 0.27, 0, 8});
    itemsVector.push_back({64, "Bronze Greaves", 0.20, 0, 6});
    itemsVector.push_back({65, "Bronze Chestplate", 0.26, 0, 7});
    itemsVector.push_back({66, "Silver Greaves", 0.23, 0, 7});
    itemsVector.push_back({67, "Silver Chestplate", 0.29, 0, 8});
    itemsVector.push_back({68, "Gold Greaves", 0.24, 0, 8});
    itemsVector.push_back({69, "Gold Chestplate", 0.31, 0, 9});
    itemsVector.push_back({70, "Platinum Greaves", 0.27, 0, 10});
    itemsVector.push_back({71, "Platinum Chestplate", 0.34, 0, 11});
    itemsVector.push_back({72, "Diamond Greaves", 0.30, 0, 12});
    itemsVector.push_back({73, "Diamond Chestplate", 0.38, 0, 14});
    itemsVector.push_back({74, "Emerald Greaves", 0.28, 0, 11});
    itemsVector.push_back({75, "Emerald Chestplate", 0.36, 0, 13});
    itemsVector.push_back({76, "Ruby Greaves", 0.29, 0, 12});
    itemsVector.push_back({77, "Ruby Chestplate", 0.37, 0, 13});

    // Food (25 items)
    itemsVector.push_back({78, "Apple", 0.0, 0, 0, true, 2});
    itemsVector.push_back({79, "Rotten Apple", 0.0, 0, 0, true, -3});
    itemsVector.push_back({80, "Infused Apple", 0.0, 0, 0, true, 10});
    itemsVector.push_back({81, "Sandwich", 0.0, 0, 0, true, 5});
    itemsVector.push_back({82, "Rotten Sandwich", 0.0, 0, 0, true, -6});
    itemsVector.push_back({83, "Infused Sandwich", 0.0, 0, 0, true, 25});
    itemsVector.push_back({84, "Smore", 0.0, 0, 0, true, 4});
    itemsVector.push_back({85, "Rotten Smore", 0.0, 0, 0, true, -5});
    itemsVector.push_back({86, "Infused Smore", 0.0, 0, 0, true, 20});
    itemsVector.push_back({87, "Cheese", 0.0, 0, 0, true, 3});
    itemsVector.push_back({88, "Rotten Cheese", 0.0, 0, 0, true, -4});
    itemsVector.push_back({89, "Infused Cheese", 0.0, 0, 0, true, 12});
    itemsVector.push_back({90, "Bread", 0.0, 0, 0, true, 5});
    itemsVector.push_back({91, "Rotten Bread", 0.0, 0, 0, true, -6});
    itemsVector.push_back({92, "Infused Bread", 0.0, 0, 0, true, 15});
    itemsVector.push_back({93, "Steak", 0.0, 0, 0, true, 8});
    itemsVector.push_back({94, "Rotten Steak", 0.0, 0, 0, true, -9});
    itemsVector.push_back({95, "Infused Steak", 0.0, 0, 0, true, 20});
    itemsVector.push_back({96, "Fish", 0.0, 0, 0, true, 6});
    itemsVector.push_back({97, "Rotten Fish", 0.0, 0, 0, true, -7});
    itemsVector.push_back({98, "Infused Fish", 0.0, 0, 0, true, 18});
    itemsVector.push_back({99, "Mushroom", 0.0, 0, 0, true, 4});
    itemsVector.push_back({100, "Rotten Mushroom", 0.0, 0, 0, true, -5});
    itemsVector.push_back({101, "Infused Mushroom", 0.0, 0, 0, true, 16});
    itemsVector.push_back({102, "Berry", 0.0, 0, 0, true, 2});
    itemsVector.push_back({103, "Rotten Berry", 0.0, 0, 0, true, -3});
    
    itemsVector.push_back({104, "Healing Tome", 0.0, 0, 0, true, player.healthMax});
    itemsVector.push_back({104, "Healing Tome", 0.0, 0, 0, true, player.healthMax});

    itemsVector.push_back({105, "Cursed Tome", 0.2, 35, 0});

    return itemsVector;
}

Game newGame(string name) {
    Game game;
    game.player.health = 10;
    game.player.healthMax = 10;
    game.player.damage = 3;
    game.player.level = 1;
    game.player.name = name;
    game.player.exp = 0.0;

    return game;
}

void saveGame(Game game) {
    FileManager fileManager;
    std::string filename = "savegame.dat";
    fileManager.saveGameData(game, filename);
}

Game loadGame() {
    Game game;
    FileManager fileManager;
    std::string filename = "savegame.dat";
    fileManager.loadGameData(game, filename);
    return game;
}


char** readFile(const std::string& fileName, int& lineCount);

Entity genEnemy(int lvl) {
    string enemyName;
    unsigned int enemyLvl = rand() % lvl + (lvl * 1.2); 
    int health = pow(1.4, enemyLvl);
    int damage = pow(1.3, enemyLvl);
    double multi;

    int name = rand() % 4;
    switch (name) {
        case 0:
            enemyName = "Goblin";
            multi = 0.5;
            break;
        case 1:
            enemyName = "Orc";
            multi = 1.5;
            break;
        case 2:
            enemyName = "Troll";
            multi = 1.25;
            break;
        case 3:
            enemyName = "Dragon";
            multi = 2.0;
            break;
        default:
            enemyName = "Unknown";
            multi = 1.0;
            break;
    }

    health = (health + 1) * multi;
    damage = damage * multi;
    
    Entity entity = {enemyName, health, damage, enemyLvl};
    return entity;
}

void initializeItem(Player& player, Item& item){
    item.level = (rand() % (player.level / 4));
    item.damage = item.level * (((rand() % 2) * 1.25) + ((rand() % 2) * -0.25));
}


Item generateItem(Player& player) {
    std::vector<Item> vecI = initializeItems(player);
    int size = vecI.size(); // Get the size of the item vector
    Item index = vecI[rand() % size]; // Generate a random index
    initializeItem(player, index);

    return index;
}


void outputStats(Player& player) {
    cout << player.name << "'s stats:\n" << "\nLevel: " << YELLOW << to_string(player.level) << RESET << "\nExperience: " << CYAN << to_string(player.exp) << RESET << "\nHealth: " << RED << to_string(player.health) << " / " << to_string(player.healthMax) << RESET << "\nDamage: " << MAGENTA << to_string(player.damage) << RESET << "\nDefense: " << BLUE << to_string(player.defense) << RESET << "\nWeight: " << BRIGHT_YELLOW << player.weight << RESET << "\nSword: " << GREEN << player.sword.name << RESET << "\nShield: " << GREEN << player.shield.name << RESET << "\nChestplate: " << GREEN << player.chestplate.name << RESET << "\nGreaves: " << GREEN << player.greaves.name << RESET << endl;
}

double updateStats(Game& game, Player& player) {
    player.weight = player.sword.weight + player.greaves.weight + player.shield.weight + player.chestplate.weight;

    // Calculate damage reduction per weight unit
    double damageReductionPerUnit = 0.25;
    double totalDamageReduction = damageReductionPerUnit * player.weight;

    // Calculate the reduction factor based on weight
    double reductionFactor = 1.0 - totalDamageReduction;

    // Apply damage reduction to player's damage
    player.damage = static_cast<int>((player.sword.damage + STAT_BASE_DAMAGE) * reductionFactor);

    // Update player's defense
    player.defense = player.greaves.block + player.chestplate.block + player.shield.block;

    // Ensure player's health does not exceed maximum health
    if (player.health > player.healthMax) {
        player.health = player.healthMax;
    }

    // Update game's player stats
    game.player.health = player.health;
    game.player.healthMax = player.healthMax;
    game.player.damage = player.damage;
    game.player.inventory = player.inventory;
    game.player.sword = player.sword;
    game.player.shield = player.shield;
    game.player.greaves = player.greaves;
    game.player.chestplate = player.chestplate;
    game.player.exp = player.exp;
    game.player.level = player.level;

    return totalDamageReduction; // Return the total damage reduction applied
}

void outputInv(const vector<Item>& inventory, const vector<Item>& items) {
    for (size_t counter = 0; counter < inventory.size(); ++counter) {
        Item index = inventory[counter];
        if (index.id >= 0 && index.id < items.size()) {
            cout << counter + 1 << ": " << GREEN << index.name  << RESET << " | " << YELLOW << index.level << "LVL" << endl;
        } else {
            cout << "Invalid item index: " << index.id << endl;
        }
    }
}

// Function to check if the choice is valid (within the inventory range)
bool isValidChoice(int choice, size_t inventorySize) {
    return choice >= 0 && choice < inventorySize;
}

// Function to use food items
bool useFood(Item& item, Player& player) {
    int in;
    if (item.food == true) {
        player.health = player.health + item.healAmount;
        return true; // Food item used
    }
    return false; // Not a food item
}

// Function to use equipment items (sword, shield, armor)
bool useEquipment(Item& item, Player& player) {
    if ( contains(item.name, "Sword")) {
        player.sword = item;
        return true; // Sword equipped
    } else if ( contains(item.name, "Greaves")) {
        player.greaves = item;
        return true; // Greaves equipped
    } else if ( contains(item.name, "Chestplate") ){
        player.chestplate = item;
        return true; // Chestplate equipped
    } else if ( contains(item.name, "Shield")){
        player.shield = item;
        return true; // Shield equipped       
    } else {
        cout << "Cannot equip unknown item: " << item.name << endl;
        return false; // Not an equipment item
    }
}


// Function to handle selecting and using items from the inventory
void useSelectedItem(int choice, Player& player, std::vector<Item>& items) {
    if (isValidChoice(choice, player.inventory.size())) {
        Item& selectedItem = items[player.inventory[choice].id];
        cout << "Using item: " << selectedItem.name << endl;

        if (useFood(selectedItem, player)) {
            // Food item used
            player.inventory.erase(player.inventory.begin() + choice);
        } else if (useEquipment(selectedItem, player)) {
            // Equipment item used (sword, shield, armor)
            player.inventory.erase(player.inventory.begin() + choice);
        } else {
            std::cout << "\nInvalid Item" << std::endl;
        }
    } else {
        std::cout << "Invalid choice" << std::endl;
    }
}



int fight(Game& game, Player& player, vector<Item>& itemVector) {
    int hp = player.health;
    int baseDamage = player.damage; // Include sword damage in base damage
    vector<Item> inv = player.inventory;
    int input;
    vector<Entity> enemies;
    bool expCalc = false;
    bool blocking = false;
    double exp;

    int numEnemies = rand() % 1 + 1; // Ensure at least one enemy
    for (int i = 0; i < numEnemies; ++i) {
        Entity enemy = genEnemy(player.level);
        enemies.push_back(enemy);
    }

    system("clear");

    while (!enemies.empty()) {
        updateStats(game, player);
        if (!expCalc) {
            for (int i = 0; i < enemies.size(); ++i) {
                exp = (enemies[i].level / ((rand() % 8) + 1.0));
            }
            expCalc = true;
        }

        for (int i = 0; i < enemies.size(); ++i) {
            cout << "A " << enemies[i].name << " has appeared!\n" << RED << enemies[i].health << "HP" << RESET << " | " << MAGENTA << enemies[i].damage << "DMG" << RESET << " | " << YELLOW << enemies[i].level << "LVL\n" << RESET << "1. Block\n2. Attack\n";

            if (enemies[i].health > 0) {
                int enemyDamage = enemies[i].damage;
                signed int zero = 0;

                enemyDamage = max(zero, (enemyDamage - static_cast<int>(player.defense)));
                if (enemies[i].blocked == true){
                    enemyDamage -= player.defense;
                }
                if (!((enemyDamage - player.shield.block) < 0)) {
                    player.health -= (enemyDamage - static_cast<int>(player.defense));
                }
                cout << "The " << enemies[i].name << " attacks you for " << RED << max(zero, (enemyDamage - static_cast<int>(player.defense))) << RESET << " damage!\n\n\n";

                outputStats(player);
                ENDL

            }
            cin >> input;

            switch (input) {
                case 1: {
                    enemies[i].blocked = true;
                    break;
                }
                case 2: {
                    // Calculate player's total damage
                    if ((rand() % 9) - player.weight > 0) {
                        enemies[i].health -= player.damage;
                        cout << "You attacked the " << enemies[i].name << " for " << baseDamage << " damage!\n";
                    } else {
                        cout << "\nYou missed!\n";
                    }
                    break;
                }
                case 3: {
                    outputInv(player.inventory, itemVector);
                    cout << "Choose an item: ";
                    int choice;
                    cin >> choice;

                    if (cin.fail()) {
                        cout << "Invalid choice. Please enter a number.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    choice--;

                    useSelectedItem(choice, player, itemVector);
                    system("clear");
                    break;
                }
                default: {
                    cout << "Invalid choice" << endl;
                    break;
                }
            }

            if (enemies[i].health < 1) {
                enemies.erase(enemies.begin() + i);
            }
        }

        if (player.health <= 0) {
            system("clear");
            cout << GAME_OVER << "You lost all your health and were sent back to Tartarus" << endl;
            return 0;
        }

        system("clear");
    }

    Item gendItemIndex = generateItem(player); // Generate the item index
    if (gendItemIndex.id != -1) {
        player.inventory.push_back(gendItemIndex); // Push back the index to the inventory
    }

    cout << "\nYou recieved a " << BLUE << gendItemIndex.name << RESET << " | " YELLOW << gendItemIndex.level << "LVL\n1. Done\n";
    int hg;
    cin >> hg;

    player.exp += exp;

    system("clear");
    return 0;
}


string explore() {
    int r = rand() % 5;

    switch (r) {
        case 0:
            return "chest";
        case 1:
            return "enemy";
        case 2:
            return "chest";
        case 3:
            return "trap";
        case 4:
            return "enemy";
        default:
            return "err";
    }
}

vector<int> inventoryB(vector<int> inv) {
    vector<int> list;
    for (size_t i = 0; i < inv.size(); ++i) {
        list.push_back(inv[i]);
    }
    return list;
}