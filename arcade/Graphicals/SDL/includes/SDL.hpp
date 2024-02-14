#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "IDisplayModule.hpp"
#include "../includes/SDLEncaps.hpp"


#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()


namespace Arcade {
    namespace Graphics {
        class SDL : public Arcade::Graphics::IDisplayModule {
            private:
                

                
                std::vector<Events> eventList;
                std::pair<int, int> mousePos;

                std::pair<int, int>winSize;
                
                std::unique_ptr<SDLEncaps> sdl;

                

            public:
                SDL(size_t winX, size_t winY);
                virtual ~SDL();
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