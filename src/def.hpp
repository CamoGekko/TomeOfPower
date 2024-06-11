#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <algorithm>
#include <iterator>
#include <limits> // For std::numeric_limits
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <variant>

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/variant.hpp>


#define INTRO_1 "\
  _    _               _                        \n\
 | |  | |             | |                       \n\
 | |__| |   __ _    __| |   ___    __ _   _ __  \n\
 |  __  |  / _` |  / _` |  / _ \\  / _` | | '_ \\ \n\
 | |  | | | (_| | | (_| | |  __/ | (_| | | | | |\n\
 |_|  |_|  \\__,_|  \\__,_|  \\___|  \\__,_| |_| |_|\n\
                                                \n\
                                                \n"

#define INTRO_2 "\
  _______                           _                     _ \n\
 |__   __|                         (_)                   | |\n\
    | |      ___   _ __   _ __ ___  _   _ __    __ _  ___| |\n\
    | |     / _ \\ | '__| | '_ ` _ \\| | | '_ \\  / _` |/ __| |\n\
    | |    |  __/ | |    | | | | | | | | | | || (_| | (__| |\n\
    |_|     \\___| |_|    |_| |_| |_|_| |_| |_| \\__,_|\\___|_|\n\
                                                            \n\
                                                            \n"

#define GAME_OVER "\
   _____                         ____                 \n\
  / ____|                       / __ \\                \n\
 | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n\
 | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n\
 | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n\
  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n\
                                                      \n"


#define MENU_MAIN "\
1. Continue Saved Game\n\
2. New Game\n\
3. Quit\n"

#define MENU_ACTION "\
1. Explore\n\
2. View Inventory\n\
3. Use Item\n\
9. Save Game\n"

#define RESET   "\033[0m"   // Resets color to default
#define RED     "\033[31m"  // Red text
#define GREEN   "\033[32m"  // Green text
#define YELLOW  "\033[33m"  // Yellow text
#define BLUE    "\033[34m"  // Blue text
#define MAGENTA "\033[35m"  // Magenta text
#define CYAN    "\033[36m"  // Cyan text
#define WHITE   "\033[37m"  // White text (default)
#define BOLONG  "\033[1m"   // Bolong double text
#define BRIGHT_BLACK    "\x1b[30;1m"
#define BRIGHT_RED      "\x1b[31;1m"
#define BRIGHT_GREEN    "\x1b[32;1m"
#define BRIGHT_YELLOW   "\x1b[33;1m"
#define BRIGHT_BLUE     "\x1b[34;1m"
#define BRIGHT_MAGENTA  "\x1b[35;1m"
#define BRIGHT_CYAN     "\x1b[36;1m"
#define BRIGHT_WHITE    "\x1b[37;1m"

#define ENDL std::cout << std::endl;

#define STAT_BASE_DAMAGE 3
#define STAT_BASE_HEALTH 10