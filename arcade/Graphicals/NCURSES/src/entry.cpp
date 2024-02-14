#include "../includes/IDisplayModule.hpp"
#include "../includes/NCURSES.hpp"
#include <iostream>
#include <memory>

extern "C"
{
    std::unique_ptr<Arcade::Graphics::IDisplayModule> entryPoint(int winX, int winY)
    {
        return std::make_unique<Arcade::Graphics::NCURSES>(winX, winY);
    }
    bool isGraphic()
    {
        return true;
    }
}
