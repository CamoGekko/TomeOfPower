#include "def.hpp"

using namespace std;

struct Entity {
    string name;
    int health;
    int damage;
    unsigned int level;
    unsigned int defense;
    bool blocked;

    template <class Archive>
    void serialize(Archive& ar) {
        ar(name, health, damage, level, defense, blocked);
    }
};

// ID, Name, Weight, Damage, Defense, Effect immunity, Dealt effect, bool isFood, healAmount
class Item {
public:
    string name;
    int id;
    int damage;
    int block;
    int level;
    double weight;
    bool food;
    int healAmount;

    // default constructor
    Item() : id(-1), name(""), weight(0.0), damage(0), block(0), food(false), healAmount(0), level(0) {}

    // Constructor
    Item(int i, const string& n, double w, int d = 0, int b = 0, bool f = false, int heal = 0, int l = 0)
        : id(i), name(n), weight(w), damage(d), block(b), food(f), healAmount(heal), level(l) {}

    // operator for comparing Item ids quickly
    bool operator==(const Item& other) const {
        return id == other.id;
    }

    template <class Archive>
    void serialize(Archive& ar) {
        ar(name, id, damage, block, weight, food, healAmount);
    }
};

class Player : public Entity {
public:
    unsigned int healthMax;
    double weight;
    vector<Item> inventory;
    Item sword;
    Item shield;
    Item greaves;
    Item chestplate;
    double exp;

    void levelUp(Player& player) {
        const double threshold = pow(1.3, player.level);
        if (player.exp <= threshold) {
            return;
        }

        player.level += 1;

        if (level > 0) {
            player.damage = (rand() % 5) * (player.health / player.level);
        }

        int prevHp = player.healthMax;
        player.healthMax = prevHp + player.level * (rand() % 10 + 1);
        if ((player.health * 2) < player.healthMax){
            player.health = player.healthMax / 2;
        }
    }


    template <class Archive>
    void serialize(Archive& ar) {
        ar(cereal::base_class<Entity>(this), healthMax, weight, inventory, sword, shield, greaves, chestplate, exp);
    }
};

struct Game {
    Player player;

    template <class Archive>
    void serialize(Archive& ar) {
        ar(player);
    }
};

// FileManager class with save and load functions using Cereal
class FileManager {
public:
    void saveGameData(const Game& game, const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            cerr << "Error opening file for writing: " << filename << endl;
            return;
        }

        cereal::BinaryOutputArchive archive(file);
        archive(game);

        // Debug output
        const Player& player = game.player;
        cout << "Saved game data:\n";
        cout << "Name: " << player.name << "\nHealth: " << player.health << "\nMax Health: " << player.healthMax << "\nWeight: " << player.weight << "\n";
    }

    void loadGameData(Game& game, string filename) {

        ifstream file;
        file.open(filename, std::ios::binary);
        if (!file) {
            cerr << "Error opening file for reading: " << filename << endl;
            return;
        }
        cereal::BinaryInputArchive archive(file);
        archive(game);

        // Debug output
        const Player& player = game.player; 
    }
};
