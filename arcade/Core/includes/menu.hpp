#include <string>
#include <iostream>
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include <memory>
#include "library.hpp"
#include <chrono>
#include "scoreboard.hpp"

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

#pragma once

namespace Arcade
{
    class Menu: public Scoreboard
    {
        private:
        public:
            enum MENU {
                M_GAME,
                M_MENU,
                M_MENU_USERNAME,
                M_DELAY_KEYBOARD = 50,
            };
            int _cursorLibrary;
            int _statusSelectGraphicalLibrary;
            int _menu;
            size_t timerKey = 0;
            void configUsername(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical);
            void handlingLibrary(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical);
            void putGameScoreBoard(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical, const std::string &library);
    };
}
