#include "func.hpp"

using namespace std;

int main() {
    // Define essential variables here
    Game game;
    Player player;
    vector<Item> items = initializeItems(player);
    bool gameOver = false;

    system("clear"); // Clear screen for better looks
    int option;
    cout << INTRO_1 << INTRO_2 << "\n" << MENU_MAIN; // Display main menu from def.hpp
    cin >> option; // Take input
    switch (option) {
        case 1: // Loads save data from savegame.dat
            system("clear");
            FileManager fm;
            fm.loadGameData(game, "savegame.dat");
            break;
        case 2: { // Creates a new game
            string name;
            cout << endl << "Player Name: ";
            cin >> name;
            system("clear");
            game = newGame(name);
            break;
        }
        case 3: // Quits the program
            return 0;
        default: // If none of those then quit
            cout << "Invalid option.\n";
            return 1;
    }

    // Set the random seed with the current time
    time_t randomSeed = time(0); 
    srand(randomSeed); 

    // Initialize player stats
    player.health = game.player.health;
    player.healthMax = game.player.healthMax;
    player.damage = game.player.damage;
    player.defense = 0;
    player.level = game.player.level;
    player.name = game.player.name;
    player.exp = game.player.exp;
    player.weight = 0;
    player.inventory = game.player.inventory;
    player.sword = game.player.sword;
    player.shield = game.player.shield;
    player.chestplate = game.player.chestplate;
    player.greaves = game.player.greaves;

    while (true) {
        string explorationResult;

        // Check for game over scenario
        if (player.health <= 0) {
            system("clear");
            gameOver = true;
            cout << GAME_OVER << "You lost all your health and were sent back to Tartarus" << endl;
            return 0;
        }

        // Update the players state
        updateStats(game, player);
        player.levelUp(player);

        // Output the players stats and show the input menu
        outputStats(player);
        cout << "\n\n" << MENU_ACTION;

        // Take input from the menu
        string input;
        cin >> input;

        // No idea why i have this but the program doesnt like it when its not there
        try {
            option = stoi(input);
        } catch (invalid_argument&) {
            cout << "Invalid option. Please enter a number.\n";
            continue;
        } catch (out_of_range&) {
            cout << "Invalid option. Please enter a valid number.\n";
            continue;
        }

        system("clear");

        // Take the previously entered input and put it through a switch
        switch (option) {
            case 1: { // Adds the value of the explore function to a previously init variable and breaks
                explorationResult = explore();
                break;
            }
            case 2: // Show the players inventory
                outputInv(player.inventory, items);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                break;
            case 3: { // Use an item from the inventory
                outputInv(player.inventory, items);
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

                useSelectedItem(choice, player, items);
                system("clear");
                break;
            }
            case 9: { // Save the games data
                FileManager fm;
                fm.saveGameData(game, "savegame.dat");
            }
            default:
                cout << "Invalid option.\n";
                break;
        }

        // Takes exploration result and does some stuff based on that
        if (explorationResult == "chest") { 
            Item gendItem = generateItem(player);
            player.inventory.push_back(gendItem);
            cout << "You found a chest! It contains a " << GREEN << gendItem.name << RESET << endl;
            cin.ignore();
        } else if (explorationResult == "enemy") {
            fight(game, player, items);
        } else if (explorationResult == "trap") {
            system("clear");
            int damage = (rand() % 10) * (player.health / 10);
            cout << "Oh no there was a trap!\nYou took " << RED << damage << RESET << " damage\n";
            player.health -= damage;
            cin.ignore();
        } else if (explorationResult == "nothing") {
            cout << "Nothing happened and you continue on your journey.\n";
            cin.ignore();
        }
    }

    return 0;
}
