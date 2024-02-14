#include "../includes/IDisplayModule.hpp"
#include "../includes/SFML.hpp"
#include <iostream>
#include <memory>

extern "C"
{
    std::unique_ptr<Arcade::Graphics::IDisplayModule> entryPoint(int winX, int winY)
    {
        return std::make_unique<Arcade::Graphics::SFML>(winX, winY);
    }
    bool isGraphic()
    {
        return true;
    }
}
