#include "../includes/NCursesEncaps.hpp"

static unsigned int rgba_from_rgba(int r, int g, int b, int a)
{
    return r << 24 | g << 16 | b << 8 | a;
}

NCursesEncaps::NCursesEncaps()
{
    initscr();
    start_color();
    timeout(0);
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    this->lastFrame = NOW;
    this->timeBetweenFrames = 20;
    mousemask(BUTTON1_CLICKED , NULL);
}

NCursesEncaps::~NCursesEncaps()
{
    this->colors.clear();
    endwin();
}

std::pair<int, int>NCursesEncaps::getMaxSize()
{
    int a, b;
    getmaxyx(stdscr, a, b);

    return std::pair<int, int>(b, a);
}

std::pair<char, unsigned int> NCursesEncaps::getColor(unsigned int color)
{
    for (auto i = this->colors.begin(); i != this->colors.end(); ++i) {
        if (i->second == color) {
            return (*i);
        }
    }

    if (this->colors.size() == 0) {
        std::pair<char, unsigned int>tmp(1, color);
        this->colors.push_back(tmp);
        return tmp;
    }

    if (this->colors.back().first < 256) {
        std::pair<char, unsigned int>tmp(this->colors.size() + 1, color);
        this->colors.push_back(tmp);
        return tmp;
    }
    return this->colors.back();
}

static int getColorValue(unsigned int color, int shift)
{
    return (color >> shift) % 256;
}


void NCursesEncaps::putPixel(int x, int y, unsigned int color)
{
    std::pair<char, unsigned int> tmp = this->getColor(color);
    init_color(tmp.first, getColorValue(tmp.second, 24) * 3.9, getColorValue(tmp.second, 16) * 3.9, getColorValue(tmp.second, 8) * 3.9);
    init_pair(tmp.first, tmp.first, tmp.first);
    attron(COLOR_PAIR(tmp.first));
    mvprintw(x , y, " ");
    attroff(COLOR_PAIR(tmp.first));
}

void NCursesEncaps::display()
{
    refresh();
    if (this->timeBetweenFrames != 0) {
        while (NOW - this->lastFrame < this->timeBetweenFrames);
    }
    this->lastFrame = NOW;
    this->colors.clear();
}

void NCursesEncaps::setFramerateLimit(int limit)
{
    if (limit <= 0)
        return;
    int tmp = 1000 / limit;

    (tmp <= 0) ? (tmp = 1) : (0);
    this->timeBetweenFrames = tmp;
}


std::vector<Arcade::Graphics::IDisplayModule::Events> NCursesEncaps::getEvents()
{
    this->events.clear();
    int event;

    MEVENT Mevent;

    for (int i = 0; i < 10; ++i) {
        event = getch();

        if (event != -1) {
            if (event >= 48 && event <= 57)
                this->events.push_back((Arcade::Graphics::IDisplayModule::Events)(event - 18));
            else if (event >= 97 && event <= 122)
                this->events.push_back((Arcade::Graphics::IDisplayModule::Events)(event - 97));
            else if (event == 10)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEnter);
            else if (event == 27)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEscape);
            else if (event == 32)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keySpace);
            else if (event == KEY_UP)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyUp);
            else if (event == KEY_DOWN)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyDown);
            else if (event == KEY_LEFT)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyLeft);
            else if (event == KEY_RIGHT)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::keyRight);
            else if (event == KEY_BACKSPACE)
                this->events.push_back(Arcade::Graphics::IDisplayModule::Events::backSpace);
        }
    }
    return this->events;
}

void NCursesEncaps::clearWin()
{
    clear();
}

void NCursesEncaps::putText(int x, int y, unsigned int color, const std::string &str)
{
    // std::pair<char, unsigned int> tmp = this->getColor(color);
    // std::pair<char, unsigned int> black = this->getColor(rgba_from_rgba(0,0,0,255));
    // mvprintw(0,0, "%d", black.first);

    // init_color(black.first, getColorValue(black.second, 24) * 3.9, getColorValue(black.second, 16) * 3.9, getColorValue(black.second, 8) * 3.9);


    // init_color(tmp.first, getColorValue(tmp.second, 24) * 3.9, getColorValue(tmp.second, 16) * 3.9, getColorValue(tmp.second, 8) * 3.9);
    // init_pair(tmp.first, tmp.first, black.first);
    // attron(COLOR_PAIR(tmp.first));
    mvprintw(y, x, str.c_str());
    // attroff(COLOR_PAIR(tmp.first));
}