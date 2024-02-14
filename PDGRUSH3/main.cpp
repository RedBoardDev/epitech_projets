#include "IMonitorDisplay.hpp"

static int launch_base(int argc, char **argv)
{
    std::string to_compare;
    if (argc < 2)
        return 1;
    to_compare = argv[1];
    if (to_compare == "-t") {
        main_ncurses();
        return 0;
    }
    if (to_compare == "-S") {
        main_SFML();
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    return launch_base(argc, argv);
}