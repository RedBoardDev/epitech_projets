#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "IDisplayModule.hpp"
#include <curses.h>
#include "NCursesEncaps.hpp"

typedef int cols;
typedef int rows;

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

namespace Arcade {
    namespace Graphics {
        class NCURSES : public Arcade::Graphics::IDisplayModule {
            private:
                std::unique_ptr<NCursesEncaps> curses;
                std::pair<int, int> mousePos;
                std::pair<int, int> winSize;
                std::pair<cols, rows> NwinSize;
                std::vector<unsigned int> fbr;
                std::vector<Arcade::Graphics::IDisplayModule::Events>events;

            public:
                NCURSES(size_t winX, size_t winY);
                virtual ~NCURSES();
                void setFrameRateLimit(int limit);
                void putpixel(int x, int y, unsigned int color);
                std::vector<Events> getEvents();
                bool isOpen();
                void clearWin();
                void refreshWin();
                void puttext(int x, int y, unsigned int color, const std::string &str);
                std::pair<int, int> getMousePos();

        };
    }
}
