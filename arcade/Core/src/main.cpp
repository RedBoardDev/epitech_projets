#include "../includes/IDisplayModule.hpp"
#include "../includes/IGameModule.hpp"
#include "../includes/core.hpp"
#include "../includes/library.hpp"
#include "../includes/DlLoad.hpp"
#include <memory>
#include <unordered_map>

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 2) return (84);
    Arcade::Library cLibrary(av[1]);
    Arcade::initLibrary(cLibrary, av[1]);
    Arcade::Core core;
    return core.mainLoop(cLibrary);
    return 0;
}
