#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "IDisplayModule.hpp"
#include <chrono>

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

class SDLEncaps {
    public:
        SDLEncaps(int winX, int winY);
        ~SDLEncaps();
        void putPixel(int x, int y, unsigned int color);
        std::vector<Arcade::Graphics::IDisplayModule::Events> getEvents();
        std::pair<int, int>getMousePos();
        void setFrameRateLimit(int limit);
        void putText(int x, int y, unsigned int color, const std::string &str);
        void display();


    private:
        std::vector<Arcade::Graphics::IDisplayModule::Events> eventList;
        SDL_Window *win;
        SDL_Renderer *renderer;

        SDL_Surface* screen = NULL;
        Uint32 *fbr;
        std::pair<int, int> mousePos;

        long lastFrame;
        long timeBetweenFrames;

        TTF_Font * font;
};