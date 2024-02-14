#include "../includes/IGameModule.hpp"
#include "../includes/NIBBLER.hpp"
#include <iostream>
#include <memory>

extern "C"
{
    std::unique_ptr<Arcade::Game::IGameModule> entryPoint()
    {
        return std::make_unique<Arcade::Game::NIBBLER>();
    }
    bool isGraphic()
    {
        return false;
    }
}
