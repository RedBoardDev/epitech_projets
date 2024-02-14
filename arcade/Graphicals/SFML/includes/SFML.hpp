#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "IDisplayModule.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


namespace Arcade {
    namespace Graphics {
        class SFML : public Arcade::Graphics::IDisplayModule {
            private:
                std::vector<Events> eventList;
                std::pair<int, int> winSize;
                std::unique_ptr<sf::RenderWindow> win;
                std::unique_ptr<sf::Texture>texture;
                std::unique_ptr<sf::Sprite>sprite;
                sf::Uint8 *fbr;
                std::pair<int, int> mousePos;
                sf::Font font;
                sf::Text text;

            public:
                SFML(size_t winX, size_t winY);
                virtual ~SFML();
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