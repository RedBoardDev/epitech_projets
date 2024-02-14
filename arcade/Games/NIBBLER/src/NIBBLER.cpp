#include "../includes/IGameModule.hpp"
#include "../includes/NIBBLER.hpp"
#include <ctime>
#include<unistd.h>

static unsigned int rgba_from_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
    return r << 24 | g << 16 | b << 8 | a;
}

std::vector<std::pair<int, int>> genAllApple()
{
    std::vector<std::pair<int, int>> appleList = {
        {80, 20}, {200, 20}, {320, 20}, {440, 20},
        {20, 80}, {140, 80}, {380, 80}, {500, 80},
        {200, 140}, {320, 140},
        {20, 200}, {140, 200}, {380, 200}, {500, 200},
        {140, 260}, {260, 260}, {380, 260},
        {80, 320}, {440, 320},
        {260, 380},
        {20, 440}, {140, 440}, {200, 440}, {320, 440}, {380, 440},
        {500, 440},
        {20, 500}, {480, 500}
    };
    return (appleList);
}

std::vector<std::pair<int, int>> genAllPath()
{
    std::vector<std::pair<int, int>> pathList = {
        {20, 20}, {40, 20}, {60, 20}, {80, 20}, {100, 20}, {120, 20}, {140, 20}, {160, 20}, {180, 20}, {200, 20}, {220, 20}, {240, 20}, {260, 20}, {280, 20}, {300, 20}, {320, 20}, {340, 20}, {360, 20}, {380, 20}, {400, 20},  {420, 20}, {440, 20}, {460, 20}, {480, 20}, {500, 20},
        {20, 40}, {140, 40}, {200, 40}, {320, 40}, {380, 40}, {500, 40},
        {20, 60}, {140, 60}, {200, 60}, {320, 60}, {380, 60}, {500, 60},
        {20, 80}, {140, 80}, {200, 80}, {220, 80}, {240, 80}, {260, 80}, {280, 80}, {300, 80}, {320, 80}, {380, 80}, {500, 80},
        {20, 100}, {140,100}, {200, 100}, {260, 100}, {320, 100}, {380, 100}, {500, 100},
        {20, 120}, {140,120}, {200, 120}, {260, 120}, {320, 120}, {380, 120}, {500, 120},
        {20, 140}, {40, 140}, {60, 140}, {80, 140}, {100, 140}, {120, 140}, {140, 140}, {200, 140}, {260, 140}, {320, 140}, {380, 140}, {400, 140}, {420, 140}, {440, 140}, {460, 140}, {480, 140}, {500, 140},
        {20, 160}, {200,160}, {260, 160}, {320, 160}, {500, 160},
        {20, 180}, {200,180}, {260, 180}, {320, 180}, {500, 180},
        {20, 200}, {80, 200}, {100, 200}, {120, 200}, {140, 200}, {160, 200}, {180, 200}, {200, 200}, {220, 200}, {240, 200}, {260, 200}, {280, 200}, {300, 200}, {320, 200}, {340, 200}, {360, 200}, {380, 200}, {400, 200}, {420, 200}, {440, 200}, {500, 200},
        {20, 220}, {80, 220}, {260, 220}, {440, 220}, {500, 220},
        {20, 240}, {80, 240}, {260, 240}, {440, 240}, {500, 240},
        {20, 260}, {40, 260}, {60, 260}, {80, 260}, {100, 260}, {120, 260}, {140, 260}, {160, 260}, {180, 260}, {200, 260}, {220, 260}, {240, 260}, {260, 260}, {280, 260}, {300, 260}, {320, 260}, {340, 260}, {360, 260}, {380, 260}, {400, 260}, {420, 260}, {440, 260}, {460, 260}, {480, 260}, {500, 260},
        {20, 280}, {200, 280}, {320, 280}, {500, 280},
        {20, 300}, {200, 300}, {320, 300}, {500, 300},
        {20, 320}, {40, 320}, {60, 320}, {80, 320}, {100, 320}, {120, 320}, {140, 320}, {160, 320}, {180, 320}, {200, 320}, {320, 320}, {340, 320}, {360, 320}, {380, 320}, {400, 320}, {420, 320}, {440, 320}, {460, 320}, {480, 320}, {500, 320},
        {20, 340}, {140, 340}, {200, 340}, {320, 340}, {380, 340}, {500, 340},
        {20, 360}, {140, 360}, {200, 360}, {320, 360}, {380, 360}, {500, 360},
        {20, 380}, {140, 380}, {200, 380}, {220, 380}, {240, 380}, {260, 380}, {280, 380}, {300, 380}, {320, 380}, {380, 380}, {500, 380},
        {20, 400}, {140, 400}, {200, 400}, {320, 400}, {380, 400}, {500, 400},
        {20, 420}, {140, 420}, {200, 420}, {320, 420}, {380, 420}, {500, 420},
        {20, 440}, {40, 440}, {60, 440}, {80, 440}, {100, 440}, {120, 440}, {140, 440}, {200, 440}, {220, 440}, {240, 440}, {260, 440}, {280, 440}, {300, 440}, {320, 440}, {380, 440}, {400, 440}, {420, 440}, {440, 440}, {460, 440}, {480, 440}, {500, 440},
        {20, 460}, {200, 460}, {320, 460}, {500, 460},
        {20, 480}, {200, 480}, {320, 480}, {500, 480},
        {20, 500}, {40, 500}, {60, 500}, {80, 500}, {100, 500}, {120, 500}, {140, 500}, {160, 500}, {180, 500}, {200, 500}, {220, 500}, {240, 500}, {260, 500}, {280, 500}, {300, 500}, {320, 500}, {340, 500}, {360, 500}, {380, 500}, {400, 500}, {420, 500}, {440, 500}, {460, 500}, {480, 500}, {500, 500}
    };
    return (pathList);
}

std::vector<std::pair<int, int>> genAllAppleOne()
{
    std::vector<std::pair<int, int>> appleList = {
        {80, 140}, {440, 140},
        {40, 200}, {60, 200}, {80, 200}, {100, 200}, {120, 200}, {140, 200}, {160, 200}, {180, 200}, {200, 200}, {220, 200}, {320, 200}, {340, 200}, {360, 200}, {380, 200}, {400, 200}, {420, 200}, {440, 200}, {460, 200}, {480, 200},
        {100, 220}, {160, 220}, {220, 220}, {320, 220}, {380, 220}, {440, 220},
        {100, 240}, {160, 240}, {220, 240}, {320, 240}, {380, 240}, {440, 240},
        {100, 260}, {160, 260}, {220, 260}, {320, 260}, {380, 260}, {440, 260},
        {100, 280}, {160, 280}, {220, 280}, {320, 280}, {380, 280}, {440, 280},
        {100, 300}, {160, 300}, {220, 300}, {320, 300}, {380, 300}, {440, 300},
        {40, 320}, {60, 320}, {80, 320}, {100, 320}, {120, 320}, {140, 320}, {160, 320}, {180, 320}, {200, 320}, {220, 320}, {320, 320}, {340, 320}, {360, 320}, {380, 320}, {400, 320}, {420, 320}, {440, 320}, {460, 320}, {480, 320},
        {80, 380}, {440, 380},
    };
    return (appleList);
}

std::vector<std::pair<int, int>> genAllPathOne()
{
    std::vector<std::pair<int, int>> pathList = {
        {20, 20}, {40, 20}, {60, 20}, {80, 20}, {100, 20}, {120, 20}, {140, 20}, {160, 20}, {180, 20}, {200, 20}, {220, 20}, {240, 20}, {260, 20}, {280, 20}, {300, 20}, {320, 20}, {340, 20}, {360, 20}, {380, 20}, {400, 20},  {420, 20}, {440, 20}, {460, 20}, {480, 20}, {500, 20},
        {20, 40}, {140, 40}, {380, 40}, {500, 40},
        {20, 60}, {140, 60}, {380, 60}, {500, 60},
        {20, 80}, {80, 80}, {100, 80}, {120, 80}, {140, 80}, {380, 80}, {400, 80}, {420, 80}, {440, 80}, {500, 80},
        {20, 100}, {80, 100}, {440, 100}, {500, 100},
        {20, 120}, {80, 120}, {440, 120}, {500, 120},
        {20, 140}, {40, 140}, {60, 140}, {80, 140}, {100, 140}, {120, 140}, {140, 140}, {160, 140}, {180, 140}, {200, 140}, {220, 140}, {240, 140}, {260, 140}, {280, 140}, {300, 140}, {320, 140}, {340, 140}, {360, 140}, {380, 140}, {400, 140},  {420, 140}, {440, 140}, {460, 140}, {480, 140}, {500, 140},
        {20, 160}, {500, 160},
        {20, 180}, {500, 180},
        {20, 200}, {40, 200}, {60, 200}, {80, 200}, {100, 200}, {120, 200}, {140, 200}, {160, 200}, {180, 200}, {200, 200}, {220, 200}, {320, 200}, {340, 200}, {360, 200}, {380, 200}, {400, 200}, {420, 200}, {440, 200}, {460, 200}, {480, 200}, {500, 200},
        {20, 220}, {100, 220}, {160, 220}, {220, 220}, {320, 220}, {380, 220}, {440, 220}, {500, 220},
        {20, 240}, {100, 240}, {160, 240}, {220, 240}, {320, 240}, {380, 240}, {440, 240}, {500, 240},
        {20, 260}, {100, 260}, {160, 260}, {220, 260}, {320, 260}, {380, 260}, {440, 260}, {500, 260},
        {20, 240}, {100, 240}, {160, 240}, {220, 240}, {320, 240}, {380, 240}, {440, 240}, {500, 240},
        {20, 280}, {100, 280}, {160, 280}, {220, 280}, {320, 280}, {380, 280}, {440, 280}, {500, 280},
        {20, 300}, {100, 300}, {160, 300}, {220, 300}, {320, 300}, {380, 300}, {440, 300}, {500, 300},
        {20, 320}, {40, 320}, {60, 320}, {80, 320}, {100, 320}, {120, 320}, {140, 320}, {160, 320}, {180, 320}, {200, 320}, {220, 320}, {320, 320}, {340, 320}, {360, 320}, {380, 320}, {400, 320},  {420, 320}, {440, 320}, {460, 320}, {480, 320}, {500, 320},
        {20, 340}, {500, 340},
        {20, 360}, {500, 360},
        {20, 380}, {40, 380}, {60, 380}, {80, 380}, {100, 380}, {120, 380}, {140, 380}, {160, 380}, {180, 380}, {200, 380}, {220, 380}, {240, 380}, {260, 380}, {280, 380}, {300, 380}, {320, 380}, {340, 380}, {360, 380}, {380, 380}, {400, 380},  {420, 380}, {440, 380}, {460, 380}, {480, 380}, {500, 380},
        {20, 400}, {80, 400}, {440, 400}, {500, 400},
        {20, 420}, {80, 420}, {440, 420}, {500, 420},
        {20, 440}, {80, 440}, {100, 440}, {120, 440}, {140, 440},{380, 440}, {400, 440}, {420, 440}, {440, 440}, {500, 440},
        {20, 460}, {140, 460}, {380, 460}, {500, 460},
        {20, 480}, {140, 480}, {380, 480}, {500, 480},
        {20, 500}, {40, 500}, {60, 500}, {80, 500}, {100, 500}, {120, 500}, {140, 500}, {160, 500}, {180, 500}, {200, 500}, {220, 500}, {240, 500}, {260, 500}, {280, 500}, {300, 500}, {320, 500}, {340, 500}, {360, 500}, {380, 500}, {400, 500}, {420, 500}, {440, 500}, {460, 500}, {480, 500}, {500, 500}
    };
    return (pathList);
}

std::vector<std::pair<int, int>> genAllAppleTwo()
{
    std::vector<std::pair<int, int>> appleList = {
        {20, 60}, {60, 60}, {100, 60}, {140, 60}, {180, 60}, {220, 60}, {260, 60}, {300, 60}, {340, 60}, {380, 60}, {420, 60}, {460, 60}, {500, 60},
        {20, 100}, {60, 100}, {100, 100}, {140, 100}, {180, 100}, {220, 100}, {260, 100}, {300, 100}, {340, 100}, {380, 100}, {420, 100}, {460, 100}, {500, 100},
        {20, 140}, {60, 140}, {100, 140}, {140, 140}, {180, 140}, {220, 140}, {260, 140}, {300, 140}, {340, 140}, {380, 140}, {420, 140}, {460, 140}, {500, 140},
        {20, 180}, {60, 180}, {100, 180}, {140, 180}, {180, 180}, {220, 180}, {260, 180}, {300, 180}, {340, 180}, {380, 180}, {420, 180}, {460, 180}, {500, 180},
        {20, 220}, {60, 220}, {100, 220}, {140, 220}, {180, 220}, {220, 220}, {260, 220}, {300, 220}, {340, 220}, {380, 220}, {420, 220}, {460, 220}, {500, 220},
        {20, 260}, {60, 260}, {100, 260}, {140, 260}, {180, 260}, {220, 260}, {260, 260}, {300, 260}, {340, 260}, {380, 260}, {420, 260}, {460, 260}, {500, 260},
        {20, 300}, {60, 300}, {100, 300}, {140, 300}, {180, 300}, {220, 300}, {260, 300}, {300, 300}, {340, 300}, {380, 300}, {420, 300}, {460, 300}, {500, 300},
        {20, 340}, {60, 340}, {100, 340}, {140, 340}, {180, 340}, {220, 340}, {260, 340}, {300, 340}, {340, 340}, {380, 340}, {420, 340}, {460, 340}, {500, 340},
        {20, 380}, {60, 380}, {100, 380}, {140, 380}, {180, 380}, {220, 380}, {260, 380}, {300, 380}, {340, 380}, {380, 380}, {420, 380}, {460, 380}, {500, 380},
        {20, 420}, {60, 420}, {100, 420}, {140, 420}, {180, 420}, {220, 420}, {260, 420}, {300, 420}, {340, 420}, {380, 420}, {420, 420}, {460, 420}, {500, 420},
        {20, 460}, {60, 460}, {100, 460}, {140, 460}, {180, 460}, {220, 460}, {260, 460}, {300, 460}, {340, 460}, {380, 460}, {420, 460}, {460, 460}, {500, 460},
    };
    return (appleList);
}

std::vector<std::pair<int, int>> genAllPathTwo()
{
    std::vector<std::pair<int, int>> pathList = {
        {20, 20}, {40, 20}, {60, 20}, {80, 20}, {100, 20}, {120, 20}, {140, 20}, {160, 20}, {180, 20}, {200, 20}, {220, 20}, {240, 20}, {260, 20}, {280, 20}, {300, 20}, {320, 20}, {340, 20}, {360, 20}, {380, 20}, {400, 20},  {420, 20}, {440, 20}, {460, 20}, {480, 20}, {500, 20},
        {20, 40}, {60, 40}, {100, 40}, {140, 40}, {180, 40}, {220, 40}, {260, 40}, {300, 40},  {340, 40}, {380, 40}, {420, 40}, {460, 40}, {500, 40},
        {20, 60}, {40, 60}, {60, 60}, {80, 60}, {100, 60}, {120, 60}, {140, 60}, {160, 60}, {180, 60}, {200, 60}, {220, 60}, {240, 60}, {260, 60}, {280, 60}, {300, 60}, {320, 60}, {340, 60}, {360, 60}, {380, 60}, {400, 60},  {420, 60}, {440, 60}, {460, 60}, {480, 60}, {500, 60},
        {20, 80}, {60, 80}, {100, 80}, {140, 80}, {180, 80}, {220, 80}, {260, 80}, {300, 80},  {340, 80}, {380, 80}, {420, 80}, {460, 80}, {500, 80},
        {20, 100}, {40, 100}, {60, 100}, {80, 100}, {100, 100}, {120, 100}, {140, 100}, {160, 100}, {180, 100}, {200, 100}, {220, 100}, {240, 100}, {260, 100}, {280, 100}, {300, 100}, {320, 100}, {340, 100}, {360, 100}, {380, 100}, {400, 100},  {420, 100}, {440, 100}, {460, 100}, {480, 100}, {500, 100},
        {20, 120}, {60, 120}, {100, 120}, {140, 120}, {180, 120}, {220, 120}, {260, 120}, {300, 120},  {340, 120}, {380, 120}, {420, 120}, {460, 120}, {500, 120},
        {20, 140}, {40, 140}, {60, 140}, {80, 140}, {100, 140}, {120, 140}, {140, 140}, {160, 140}, {180, 140}, {200, 140}, {220, 140}, {240, 140}, {260, 140}, {280, 140}, {300, 140}, {320, 140}, {340, 140}, {360, 140}, {380, 140}, {400, 140},  {420, 140}, {440, 140}, {460, 140}, {480, 140}, {500, 140},
        {20, 160}, {60, 160}, {100, 160}, {140, 160}, {180, 160}, {220, 160}, {260, 160}, {300, 160},  {340, 160}, {380, 160}, {420, 160}, {460, 160}, {500, 160},
        {20, 180}, {40, 180}, {60, 180}, {80, 180}, {100, 180}, {120, 180}, {140, 180}, {160, 180}, {180, 180}, {200, 180}, {220, 180}, {240, 180}, {260, 180}, {280, 180}, {300, 180}, {320, 180}, {340, 180}, {360, 180}, {380, 180}, {400, 180},  {420, 180}, {440, 180}, {460, 180}, {480, 180}, {500, 180},
        {20, 200}, {60, 200}, {100, 200}, {140, 200}, {180, 200}, {220, 200}, {260, 200}, {300, 200},  {340, 200}, {380, 200}, {420, 200}, {460, 200}, {500, 200},
        {20, 220}, {40, 220}, {60, 220}, {80, 220}, {100, 220}, {120, 220}, {140, 220}, {160, 220}, {180, 220}, {200, 220}, {220, 220}, {240, 220}, {260, 220}, {280, 220}, {300, 220}, {320, 220}, {340, 220}, {360, 220}, {380, 220}, {400, 220},  {420, 220}, {440, 220}, {460, 220}, {480, 220}, {500, 220},
        {20, 240}, {60, 240}, {100, 240}, {140, 240}, {180, 240}, {220, 240}, {260, 240}, {300, 240},  {340, 240}, {380, 240}, {420, 240}, {460, 240}, {500, 240},
        {20, 260}, {40, 260}, {60, 260}, {80, 260}, {100, 260}, {120, 260}, {140, 260}, {160, 260}, {180, 260}, {200, 260}, {220, 260}, {240, 260}, {260, 260}, {280, 260}, {300, 260}, {320, 260}, {340, 260}, {360, 260}, {380, 260}, {400, 260},  {420, 260}, {440, 260}, {460, 260}, {480, 260}, {500, 260},
        {20, 280}, {60, 280}, {100, 280}, {140, 280}, {180, 280}, {220, 280}, {260, 280}, {300, 280},  {340, 280}, {380, 280}, {420, 280}, {460, 280}, {500, 280},
        {20, 300}, {40, 300}, {60, 300}, {80, 300}, {100, 300}, {120, 300}, {140, 300}, {160, 300}, {180, 300}, {200, 300}, {220, 300}, {240, 300}, {260, 300}, {280, 300}, {300, 300}, {320, 300}, {340, 300}, {360, 300}, {380, 300}, {400, 300},  {420, 300}, {440, 300}, {460, 300}, {480, 300}, {500, 300},
        {20, 320}, {60, 320}, {100, 320}, {140, 320}, {180, 320}, {220, 320}, {260, 320}, {300, 320},  {340, 320}, {380, 320}, {420, 320}, {460, 320}, {500, 320},
        {20, 340}, {40, 340}, {60, 340}, {80, 340}, {100, 340}, {120, 340}, {140, 340}, {160, 340}, {180, 340}, {200, 340}, {220, 340}, {240, 340}, {260, 340}, {280, 340}, {300, 340}, {320, 340}, {340, 340}, {360, 340}, {380, 340}, {400, 340},  {420, 340}, {440, 340}, {460, 340}, {480, 340}, {500, 340},
        {20, 360}, {60, 360}, {100, 360}, {140, 360}, {180, 360}, {220, 360}, {260, 360}, {300, 360},  {340, 360}, {380, 360}, {420, 360}, {460, 360}, {500, 360},
        {20, 380}, {40, 380}, {60, 380}, {80, 380}, {100, 380}, {120, 380}, {140, 380}, {160, 380}, {180, 380}, {200, 380}, {220, 380}, {240, 380}, {260, 380}, {280, 380}, {300, 380}, {320, 380}, {340, 380}, {360, 380}, {380, 380}, {400, 380},  {420, 380}, {440, 380}, {460, 380}, {480, 380}, {500, 380},
        {20, 400}, {60, 400}, {100, 400}, {140, 400}, {180, 400}, {220, 400}, {260, 400}, {300, 400},  {340, 400}, {380, 400}, {420, 400}, {460, 400}, {500, 400},
        {20, 420}, {40, 420}, {60, 420}, {80, 420}, {100, 420}, {120, 420}, {140, 420}, {160, 420}, {180, 420}, {200, 420}, {220, 420}, {240, 420}, {260, 420}, {280, 420}, {300, 420}, {320, 420}, {340, 420}, {360, 420}, {380, 420}, {400, 420},  {420, 420}, {440, 420}, {460, 420}, {480, 420}, {500, 420},
        {20, 440}, {60, 440}, {100, 440}, {140, 440}, {180, 440}, {220, 440}, {260, 440}, {300, 440},  {340, 440}, {380, 440}, {420, 440}, {460, 440}, {500, 440},
        {20, 460}, {40, 460}, {60, 460}, {80, 460}, {100, 460}, {120, 460}, {140, 460}, {160, 460}, {180, 460}, {200, 460}, {220, 460}, {240, 460}, {260, 460}, {280, 460}, {300, 460}, {320, 460}, {340, 460}, {360, 460}, {380, 460}, {400, 460},  {420, 460}, {440, 460}, {460, 460}, {480, 460}, {500, 460},
        {20, 480}, {60, 480}, {100, 480}, {140, 480}, {180, 480}, {220, 480}, {260, 480}, {300, 480},  {340, 480}, {380, 480}, {420, 480}, {460, 480}, {500, 480},
        {20, 500}, {40, 500}, {60, 500}, {80, 500}, {100, 500}, {120, 500}, {140, 500}, {160, 500}, {180, 500}, {200, 500}, {220, 500}, {240, 500}, {260, 500}, {280, 500}, {300, 500}, {320, 500}, {340, 500}, {360, 500}, {380, 500}, {400, 500}, {420, 500}, {440, 500}, {460, 500}, {480, 500}, {500, 500}
    };
    return (pathList);
}


Arcade::Game::NIBBLER::NIBBLER()
{
    this->Score = 0;
    this->timer_tot = 0;
    this->timer = NOW;
    this->timerPause = 0;
    this->timerStart = 1;
    this->time = 0;
    this->apple = genAllApple();
    this->path = genAllPath();
    this->level = 0;
    this->GameState = State::on;
    std::srand(std::time(nullptr));

    this->Nibbler.push_back(std::make_unique<NibblerPart>(std::pair<int, int>(300, 500), true));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
}

Arcade::Game::NIBBLER::~NIBBLER() {}

std::pair<int, int> Arcade::Game::NIBBLER::getResolution() const
{
    return this->WinSize;
}

void Arcade::Game::NIBBLER::start()
{
    this->GameState = State::on;
}

void Arcade::Game::NIBBLER::end()
{
    this->GameState = State::off;
}

const size_t &Arcade::Game::NIBBLER::getScore() const
{
    return this->Score;
}

void Arcade::Game::NIBBLER::setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> ev)
{
    Events = ev;
}

const std::unordered_map<long, unsigned int> &Arcade::Game::NIBBLER::getPixels() const
{
    return fbr;
}

void Arcade::Game::NIBBLER::drawRect(std::pair<int, int> pos, std::pair<int, int> size, unsigned int color)
{
    if (pos.first < 0 || pos.second < 0 || pos.first + size.first > this->WinSize.first || pos.second + size.second > this->WinSize . second)
        return;
    for (int i = pos.first; i < pos.first + size.first; ++i) {
        for (int j = pos.second; j < pos.second + size.second; ++j) {
            fbr.insert({(static_cast<long>(i) << 32 | static_cast<long>(j)), color});
        }
    }
}

void Arcade::Game::NIBBLER::drawAllApple(std::vector<std::pair<int, int>> apple)
{
    std::pair<int, int> tmp;

    for (size_t i = 0; i < (this->apple.size()); i++) {
        tmp.first = (apple[i].first);
        tmp.second = (apple[i].second);
        this->drawRect(tmp, std::pair<int, int>(20,20), rgba_from_rgba(194, 46, 46));
    }
}

void Arcade::Game::NIBBLER::drawAllPath(std::vector<std::pair<int, int>> path)
{
    std::pair<int, int> tmp;

    for (size_t i = 0; i < (this->path.size()); i++) {
        tmp.first = (path[i].first);
        tmp.second = (path[i].second);
        this->drawRect(tmp, std::pair<int, int>(20,20), rgba_from_rgba(200, 200, 200));
    }
}

void Arcade::Game::NIBBLER::drawWall(void)
{
    for (size_t y = 0; y <= 520; y += 20) {
        for (size_t x = 0; x <= 520; x += 20) {
            if ((x < 20) || (x == 520) || (y < 20) || (y == 520)) {
                this->drawRect(std::pair<int, int>(x, y), std::pair<int, int>(20,20), rgba_from_rgba(96, 96, 96));
            } else {
                continue;
            }
        }
    }
}

void Arcade::Game::NIBBLER::checkIfAppleIsEat(std::vector<std::pair<int, int>> apple)
{
    for (size_t i = 0; i < (this->apple.size()); i++) {
        if (this->Nibbler.front()->getPos().first + 20 > this->apple[i].first && this->Nibbler.front()->getPos().first < this->apple[i].first + 20) {
            if (this->Nibbler.front()->getPos().second + 20 > this->apple[i].second && this->Nibbler.front()->getPos().second < this->apple[i].second + 20) {
                this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
                this->Score += 1;
                this->apple.erase(this->apple.begin() + i);
            }
        }
    }
}

void Arcade::Game::NIBBLER::refresh()
{
    if (this->GameState == off) {
        fbr.clear();
    }

    if (this->GameState == paused) {
        for (auto i = this->Events.begin(); i != this->Events.end(); ++i) {
            if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyEscape && NOW - this->timerUnPause > 500) {
                this->GameState = on;
                this->timerPause = NOW;
                this->timer = NOW;
            }
        }
        for (auto i = this->Nibbler.begin(); i != this->Nibbler.end(); ++i)
            this->drawRect((*i)->getPos(), std::pair<int, int>(20,20), rgba_from_rgba(43, 153, 14));
        this->drawAllApple(apple);
        this->drawAllPath(path);
        this->drawWall();
    }

    if (this->GameState == on) {
        fbr.clear();
        if (this->timerStart == 0) {
            for (auto i = this->Events.begin(); i != this->Events.end(); ++i) {
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyLeft ) {
                    this->nxtDir = LEFT;
                }
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyRight) {
                    this->nxtDir = RIGHT;
                }
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyUp ) {
                    this->nxtDir = TOP;
                }
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyDown ) {
                    this->nxtDir = BOTTOM;
                }


                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyEscape && NOW - this->timerPause > 500) {
                    this->GameState = paused;
                    this->timerUnPause = NOW;
                    return;
                }
            }
            Direction curDir = this->Nibbler.front()->getDir();
            if ((this->nxtDir == LEFT) && (this->Nibbler.front()->getDir() != Arcade::Game::NIBBLER::Direction::RIGHT))
                if (0 == (this->checkIfPath(this->path, Arcade::Game::NIBBLER::Direction::LEFT, this->Nibbler.front()->getPos()))) {
                    this->Nibbler.front()->setDir(Arcade::Game::NIBBLER::Direction::LEFT);
                }
            if ((this->nxtDir == RIGHT) && (this->Nibbler.front()->getDir() != Arcade::Game::NIBBLER::Direction::LEFT))
                if (0 == (this->checkIfPath(this->path, Arcade::Game::NIBBLER::Direction::RIGHT, this->Nibbler.front()->getPos()))) {
                        this->Nibbler.front()->setDir(Arcade::Game::NIBBLER::Direction::RIGHT);
                }
            if ((this->nxtDir == BOTTOM) && (this->Nibbler.front()->getDir() != Arcade::Game::NIBBLER::Direction::TOP))
                if (0 == (this->checkIfPath(this->path, Arcade::Game::NIBBLER::Direction::BOTTOM, this->Nibbler.front()->getPos()))) {
                        this->Nibbler.front()->setDir(Arcade::Game::NIBBLER::Direction::BOTTOM);
                }
            if ((this->nxtDir == TOP) && (this->Nibbler.front()->getDir() != Arcade::Game::NIBBLER::Direction::BOTTOM))
                if (0 == (this->checkIfPath(this->path, Arcade::Game::NIBBLER::Direction::TOP, this->Nibbler.front()->getPos()))) {
                        this->Nibbler.front()->setDir(Arcade::Game::NIBBLER::Direction::TOP);
                }
        }

        for (auto i = this->Nibbler.begin(); i != this->Nibbler.end(); ++i)
            this->drawRect((*i)->getPos(), std::pair<int, int>(20,20), rgba_from_rgba(43, 153, 14));
        this->drawAllApple(apple);
        this->drawAllPath(path);
        this->drawWall();
        this->timer_tot += NOW - this->timer;

        while (this->timer_tot >= this->refreshTime) {
            if (this->Nibbler.front()->getDir() == LEFT) {
                if (1 == this->checkIfPath(this->path, LEFT, this->Nibbler.front()->getPos()))
                    if (0 == this->checkIfPath(this->path, BOTTOM, this->Nibbler.front()->getPos())) {
                        this->Nibbler.front()->setDir(BOTTOM);
                        this->nxtDir = BOTTOM;
                    } else {
                        this->Nibbler.front()->setDir(TOP);
                        this->nxtDir = TOP;
                    }
            }
            if (this->Nibbler.front()->getDir() == RIGHT) {
                if (1 == this->checkIfPath(this->path, RIGHT, this->Nibbler.front()->getPos()))
                    if (0 == this->checkIfPath(this->path, TOP, this->Nibbler.front()->getPos())) {
                        this->Nibbler.front()->setDir(TOP);
                        this->nxtDir = TOP;
                    } else {
                        this->Nibbler.front()->setDir(BOTTOM);
                        this->nxtDir = BOTTOM;
                    }
            }
            if (this->Nibbler.front()->getDir() == TOP) {
                if (1 == this->checkIfPath(this->path, TOP, this->Nibbler.front()->getPos()))
                    if (0 == this->checkIfPath(this->path, LEFT, this->Nibbler.front()->getPos())) {
                        this->Nibbler.front()->setDir(LEFT);
                        this->nxtDir = LEFT;
                    } else {
                        this->Nibbler.front()->setDir(RIGHT);
                        this->nxtDir = RIGHT;
                    }
            }
            if (this->Nibbler.front()->getDir() == BOTTOM) {
                if (1 == this->checkIfPath(this->path, BOTTOM, this->Nibbler.front()->getPos()))
                    if (0 == this->checkIfPath(this->path, RIGHT, this->Nibbler.front()->getPos())) {
                        this->Nibbler.front()->setDir(RIGHT);
                        this->nxtDir = RIGHT;
                    } else {
                        this->Nibbler.front()->setDir(LEFT);
                        this->nxtDir = LEFT;
                    }
            }

            if (this->timerStart > 0)
                this->timerStart -= 1;
            for (int i = 0; i != this->Nibbler.size(); ++i) {
                if (i != 0)
                    this->Nibbler[i]->setNextDir(this->Nibbler[i -1]->getDir());
            }
            for (int i = 0; i != this->Nibbler.size(); ++i) {
                this->Nibbler[i]->refresh(this->path);
            }

            this->checkIfAppleIsEat(apple);

            if (60 <= (this->time / 1000)) {
                this->level = 0;
                this->reset();
                return;
            }

            if (this->Nibbler.front()->getPos().first < 0 || this->Nibbler.front()->getPos().first > 1000 || this->Nibbler.front()->getPos().second < 0 || this->Nibbler.front()->getPos().second > 1000) {
                this->level = 0;
                this->reset();
                return;
            }

            for (int i = 1; i < this->Nibbler.size(); ++i) {
                if (this->Nibbler[i]->getPos().first == this->Nibbler[0]->getPos().first && this->Nibbler[i]->getPos().second == this->Nibbler[0]->getPos().second) {
                    this->level = 0;
                    this->reset();
                    return;
                }
            }
            this->timer_tot -= this->refreshTime;
            this->time += this->refreshTime;

            if (1 == this->checkIfCurPosIsPath(this->Nibbler.front()->getPos(), this->path)) {
                this->level = 0;
                this->reset();
                return;
            }
            this->nextLevel(apple);
        }
        this->timer = NOW;
    }
}

void Arcade::Game::NIBBLER::reset()
{
    fbr.clear();

    this->Score = 0;
    this->timer_tot = 0;
    this->timer = NOW;
    this->timerPause = 0;
    this->timerStart = 1;
    this->time = 0;
    this->nxtDir = RIGHT;

    this->Nibbler.clear();
    this->Nibbler.push_back(std::make_unique<NibblerPart>(std::pair<int, int>(300, 500), true));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));
    this->Nibbler.push_back((std::make_unique<NibblerPart>(this->Nibbler.back())));

    if (1 == this->level) {
        this->apple = genAllAppleOne();
        this->path = genAllPathOne();
        this->level = 0;
        return;
    }
    if (2 == this->level) {
        this->apple = genAllAppleTwo();
        this->path = genAllPathTwo();
        this->level = 0;
        return;
    }
    this->apple = genAllApple();
    this->path = genAllPath();
    this->level = 0;
}

Arcade::Game::NIBBLER::NibblerPart::NibblerPart(std::pair<int, int> pos, bool head)
{
    this->head = head;
    this->pos = pos;
    this->dir = RIGHT;
    this->wait = false;
    this->next = RIGHT;
}

Arcade::Game::NIBBLER::NibblerPart::NibblerPart(const std::unique_ptr<NibblerPart> &obj)
{
    this->pos = obj->getPos();
    this->dir = obj->getDir();
    this->next = obj->getNextDir();
    this->head = false;
    this->wait = obj->getWait() + 1;
}

int Arcade::Game::NIBBLER::NibblerPart::getWait() const
{
    return this->wait;
}

Arcade::Game::NIBBLER::NibblerPart::~NibblerPart()
{

}

void Arcade::Game::NIBBLER::NibblerPart::refresh(std::vector<std::pair<int, int>> path)
{
    std::pair<int, int> posTmp;

    if (wait > 0) {
        --wait;
        return;
    }
    if (this->dir == LEFT) {
        this->pos.first -= 20;
    }
    if (this->dir == RIGHT) {
        this->pos.first += 20;
    }
    if (this->dir == TOP) {
        this->pos.second -= 20;
    }
    if (this->dir == BOTTOM) {
        this->pos.second += 20;
    }
    if (!head)
        this->dir = this->next;
}

int Arcade::Game::NIBBLER::checkIfPath(std::vector<std::pair<int, int>> path, Arcade::Game::NIBBLER::Direction dir, std::pair<int, int> curPos)
{
    if (dir == LEFT) {
        curPos.first -= 20;
    }
    if (dir == RIGHT) {
        curPos.first += 20;
    }
    if (dir == TOP) {
        curPos.second -= 20;
    }
    if (dir == BOTTOM) {
        curPos.second += 20;
    }
    for (int i = 0; i < path.size(); ++i) {
        if (curPos.first == path[i].first) {
            if (curPos.second == path[i].second)
                return 0;
        } else {
            continue;
        }
    }
    return 1;
}

Arcade::Game::NIBBLER::Direction Arcade::Game::NIBBLER::NibblerPart::getDir() const
{
    return this->dir;
}

Arcade::Game::NIBBLER::Direction Arcade::Game::NIBBLER::NibblerPart::getNextDir() const
{
    return this->next;
}

void Arcade::Game::NIBBLER::NibblerPart::setDir(Arcade::Game::NIBBLER::Direction dir)
{
    this->dir = dir;
}

void Arcade::Game::NIBBLER::NibblerPart::setNextDir(Arcade::Game::NIBBLER::Direction dir)
{
    this->next = dir;
}

std::pair<int, int> Arcade::Game::NIBBLER::NibblerPart::getPos() const
{
    return this->pos;
}

void Arcade::Game::NIBBLER::nextLevel(std::vector<std::pair<int, int>> apple)
{
    size_t scoreTmp = this->Score;
    int levelTmp = this->level;

    if (0 == apple.size()) {
        if (2 == this->level) {
            this->level = 0;
            this->reset();
            this->Score = scoreTmp;
            return;
        }
        this->level = (this->level + 1);
        this->reset();
        this->Score = scoreTmp;
        this->level = (levelTmp + 1);
    }
    return;
}

int Arcade::Game::NIBBLER::checkIfCurPosIsPath(std::pair<int, int> pos, std::vector<std::pair<int, int>> path)
{
    int result = 0;

    for (int i = 0; i < path.size(); ++i) {
        if (pos.first == path[i].first) {
            if (pos.second == path[i].second) {
                ++result;
            }
        } else {
            continue;
        }
    }
    if (result != 0)
        return 0;
    return 1;
}