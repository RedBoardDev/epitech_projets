#include <string>
#include <iostream>
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include <memory>
#include "library.hpp"
#include "menu.hpp"
#include "DlLoad.hpp"

#pragma once

namespace Arcade
{
    class Core: public Menu
    {
        private:
            enum Action {
                A_ERROR = -84,
                A_LEAVE,
                A_RESET,
                A_CLOSE,
                A_NOTHING,
            };
            DLLoader _gameLoader;
            DLLoader _graphicLoader;
            std::unique_ptr<Arcade::Game::IGameModule> _gameLib;
            std::unique_ptr<Arcade::Graphics::IDisplayModule> _graphicLib;
        public:
            Core();
            ~Core() {};
            int loopMenu(Arcade::Library &cLibrary);
            int gameLoop(Arcade::Library &cLibrary);
            int mainLoop(Arcade::Library &cLibrary);
            int keyEventForGameLoop(Arcade::Library &cLibrary, std::vector<Arcade::Graphics::IDisplayModule::Events> events);
            std::pair<int, int> long_to_coords(long nbr);
            void display_putPixel();
            int loadNewGraphicalLib(Arcade::Library &cLibrary);
            int loadNewGameLib(Arcade::Library &cLibrary);
    };
    bool checkEventKey(std::vector<Arcade::Graphics::IDisplayModule::Events> events, Arcade::Graphics::IDisplayModule::Events key);
}
