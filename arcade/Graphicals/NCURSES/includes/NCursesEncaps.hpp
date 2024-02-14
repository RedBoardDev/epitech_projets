#pragma once

#include "IDisplayModule.hpp"
#include <curses.h>
#include <chrono>

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

class NCursesEncaps {
    public:
        NCursesEncaps();
        ~NCursesEncaps();
        std::pair<int, int>getMaxSize();
        std::pair<char, unsigned int> getColor(unsigned int color);
        void putPixel(int x, int y, unsigned int color);
        void display();
        void clearWin();
        void setFramerateLimit(int limit);
        std::vector<Arcade::Graphics::IDisplayModule::Events> getEvents();
        void putText(int x, int y, unsigned int color, const std::string &str);

    private:
        WINDOW *win;
        std::vector<std::pair<char, unsigned int>> colors;
        uint64_t lastFrame;
        size_t timeBetweenFrames;
        std::vector<Arcade::Graphics::IDisplayModule::Events>events;

};