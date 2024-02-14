#include "../includes/NCURSES.hpp"
#include <chrono>
#include <memory>

static std::pair<int, int> pixelsToChars(std::pair<int, int> winSize, std::pair<int, int> NwinSize, int x, int y)
{
    int posx = x / (winSize.first / NwinSize.first);
    int posy = y / (winSize.second / NwinSize.second);

    if (posx >= NwinSize.first)
        posx = NwinSize.first - 1;
    if (posy >= NwinSize.second)
        posy = NwinSize.second - 1;
    return std::pair<int, int>(posx, posy);
}

Arcade::Graphics::NCURSES::NCURSES(size_t winX, size_t winY)
{
    curses = std::make_unique<NCursesEncaps>();
    this->NwinSize = curses->getMaxSize();
    this->winSize.first = winX;
    this->winSize.second = winY;
    this->fbr.reserve(this->NwinSize.first * this->NwinSize.second);
    for (int i = 0; i < this->NwinSize.first * this->NwinSize.second; ++i)
        this->fbr.push_back(0);
}

Arcade::Graphics::NCURSES::~NCURSES()
{
    
}

void Arcade::Graphics::NCURSES::setFrameRateLimit(int limit)
{
    this->curses->setFramerateLimit(limit);
}

void Arcade::Graphics::NCURSES::putpixel(int x, int y, unsigned int color)
{
    std::pair<int, int> coords = pixelsToChars(this->winSize, this->NwinSize, x, y);
    this->fbr[coords.second * this->NwinSize.first + coords.first] = color;
}

bool Arcade::Graphics::NCURSES::isOpen()
{
    return true;
}

void Arcade::Graphics::NCURSES::clearWin()
{
    for (int i = 0; i < this->NwinSize.first * this->NwinSize.second; ++i)
        this->fbr[i] = 0;
    this->curses->clearWin();
}

void Arcade::Graphics::NCURSES::refreshWin()
{
    for (int i = 0; i < this->fbr.size(); ++i) {
        if (this->fbr[i] > 255) {
            this->curses->putPixel(i / this->NwinSize.first, i % this->NwinSize.first, this->fbr[i]);
        }
    }
    this->events = this->curses->getEvents();
    this->curses->display();
}

void Arcade::Graphics::NCURSES::puttext(int x, int y, unsigned int color, const std::string &str)
{
    std::pair<int, int> coords = pixelsToChars(this->winSize, this->NwinSize, x, y);

    this->curses->putText(coords.first, coords.second, color, str);
}

std::vector<Arcade::Graphics::NCURSES::Events> Arcade::Graphics::NCURSES::getEvents()
{
    return this->events;
}

std::pair<int, int> Arcade::Graphics::NCURSES::getMousePos()
{
    return this->mousePos;
}
