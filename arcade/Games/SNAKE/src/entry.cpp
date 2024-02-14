#include "../includes/IGameModule.hpp"
#include "../includes/SNAKE.hpp"
#include <iostream>
#include <memory>

extern "C"
{
    std::unique_ptr<Arcade::Game::IGameModule> entryPoint()
    {
        return std::make_unique<Arcade::Game::SNAKE>();
    }
    bool isGraphic()
    {
        return false;
    }
}
