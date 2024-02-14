#include "../includes/IGameModule.hpp"
#include "../includes/SNAKE.hpp"
#include <ctime>


static unsigned int rgba_from_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
{
    return r << 24 | g << 16 | b << 8 | a;
}

static std::pair<int, int> genApple()
{
    int x = std::rand() % (1900 / 20);
    int y = std::rand() % (1060 / 20);

    return std::pair<int, int>(x * 20, y * 20);
}

Arcade::Game::SNAKE::SNAKE()
{
    this->Score = 0;
    this->timer_tot = 0;
    this->timer = NOW;
    this->timerPause = 0;
    this->timerStart = 1;
    this->GameState = State::on;
    this->apple = this->apple = genApple();
    std::srand(std::time(nullptr));

    this->Snake.push_back(std::make_unique<SnakePart>(std::pair<int, int>(960, 540), true));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
}

Arcade::Game::SNAKE::~SNAKE() {}

std::pair<int, int> Arcade::Game::SNAKE::getResolution() const
{
    return this->WinSize;
}

void Arcade::Game::SNAKE::start()
{
    this->GameState = State::on;
}

void Arcade::Game::SNAKE::end()
{
    this->GameState = State::off;
}

const size_t &Arcade::Game::SNAKE::getScore() const
{
    return this->Score;
}

void Arcade::Game::SNAKE::setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> ev)
{
    Events = ev;
}

const std::unordered_map<long, unsigned int> &Arcade::Game::SNAKE::getPixels() const
{
    return fbr;
}

void Arcade::Game::SNAKE::drawRect(std::pair<int, int> pos, std::pair<int, int> size, unsigned int color)
{
    if (pos.first < 0 || pos.second < 0 || pos.first + size.first > this->WinSize.first || pos.second + size.second > this->WinSize . second)
        return;
    for (int i = pos.first; i < pos.first + size.first; ++i) {
        for (int j = pos.second; j < pos.second + size.second; ++j) {
            fbr.insert({(static_cast<long>(i) << 32 | static_cast<long>(j)), color});
        }
    }
}



void Arcade::Game::SNAKE::refresh()
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
        for (auto i = this->Snake.begin(); i != this->Snake.end(); ++i)
            this->drawRect((*i)->getPos(), std::pair<int, int>(20,20), rgba_from_rgba(43, 153, 14));
        this->drawRect(apple, std::pair<int, int>(20,20), rgba_from_rgba(194, 46, 46));
    }

    if (this->GameState == on) {
        fbr.clear();
        if (this->timerStart == 0) {
            for (auto i = this->Events.begin(); i != this->Events.end(); ++i) {
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyLeft && this->Snake.front()->getDir() != Arcade::Game::SNAKE::Direction::RIGHT)
                    this->Snake.front()->setDir(Arcade::Game::SNAKE::Direction::LEFT);
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyRight && this->Snake.front()->getDir() != Arcade::Game::SNAKE::Direction::LEFT)
                    this->Snake.front()->setDir(Arcade::Game::SNAKE::Direction::RIGHT);
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyUp && this->Snake.front()->getDir() != Arcade::Game::SNAKE::Direction::BOTTOM)
                    this->Snake.front()->setDir(Arcade::Game::SNAKE::Direction::TOP);
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyDown && this->Snake.front()->getDir() != Arcade::Game::SNAKE::Direction::TOP)
                    this->Snake.front()->setDir(Arcade::Game::SNAKE::Direction::BOTTOM);
                if ((*i) == Arcade::Graphics::IDisplayModule::Events::keyEscape && NOW - this->timerPause > 500) {
                    this->GameState = paused;
                    this->timerUnPause = NOW;
                    return;
                }
            }
        }

        for (auto i = this->Snake.begin(); i != this->Snake.end(); ++i)
            this->drawRect((*i)->getPos(), std::pair<int, int>(20,20), rgba_from_rgba(43, 153, 14));

        this->drawRect(apple, std::pair<int, int>(20,20), rgba_from_rgba(194, 46, 46));

        this->timer_tot += NOW - this->timer;

        while (this->timer_tot >= this->refreshTime) {
            if (this->timerStart > 0)
                this->timerStart -= 1;
            for (int i = 0; i != this->Snake.size(); ++i) {
                if (i != 0)
                    this->Snake[i]->setNextDir(this->Snake[i -1]->getDir());
            }
            for (int i = 0; i != this->Snake.size(); ++i) {
                this->Snake[i]->refresh();
            }

            if (this->Snake.front()->getPos().first + 20 > this->apple.first && this->Snake.front()->getPos().first < this->apple.first + 20) {
                if (this->Snake.front()->getPos().second + 20 > this->apple.second && this->Snake.front()->getPos().second < this->apple.second + 20) {
                    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
                    this->Score += 1;
                    this->apple.first = -1;
                }
            }

            if (this->apple.first == -1)
                this->apple = genApple();

            if (this->Snake.front()->getPos().first < 0 || this->Snake.front()->getPos().first > 1920 || this->Snake.front()->getPos().second < 0 || this->Snake.front()->getPos().second > 1080) {
                this->reset();
                return;
            }

            for (int i = 1; i < this->Snake.size(); ++i) {
                if (this->Snake[i]->getPos().first == this->Snake[0]->getPos().first && this->Snake[i]->getPos().second == this->Snake[0]->getPos().second) {
                    this->reset();
                    return;
                }
            }
            this->timer_tot -= this->refreshTime;
        }
        this->timer = NOW;
    }
}

void Arcade::Game::SNAKE::reset()
{
    fbr.clear();

    this->Score = 0;
    this->timer_tot = 0;
    this->timer = NOW;
    this->timerPause = 0;
    this->timerStart = 1;

    this->Snake.clear();
    this->Snake.push_back(std::make_unique<SnakePart>(std::pair<int, int>(960, 540), true));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
    this->Snake.push_back((std::make_unique<SnakePart>(this->Snake.back())));
    this->apple = genApple();
}



Arcade::Game::SNAKE::SnakePart::SnakePart(std::pair<int, int> pos, bool head)
{
    this->head = head;
    this->pos = pos;
    this->dir = TOP;
    this->wait = false;
    this->next = TOP;
}

Arcade::Game::SNAKE::SnakePart::SnakePart(const std::unique_ptr<SnakePart> &obj)
{
    this->pos = obj->getPos();
    this->dir = obj->getDir();
    this->next = obj->getNextDir();
    this->head = false;
    this->wait = obj->getWait() + 1;
}

int Arcade::Game::SNAKE::SnakePart::getWait() const
{
    return this->wait;
}

Arcade::Game::SNAKE::SnakePart::~SnakePart()
{

}

void Arcade::Game::SNAKE::SnakePart::refresh()
{

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

Arcade::Game::SNAKE::Direction Arcade::Game::SNAKE::SnakePart::getDir() const
{
    return this->dir;
}

Arcade::Game::SNAKE::Direction Arcade::Game::SNAKE::SnakePart::getNextDir() const
{
    return this->next;
}

void Arcade::Game::SNAKE::SnakePart::setDir(Arcade::Game::SNAKE::Direction dir)
{

    this->dir = dir;
}

void Arcade::Game::SNAKE::SnakePart::setNextDir(Arcade::Game::SNAKE::Direction dir)
{
    this->next = dir;
}

std::pair<int, int> Arcade::Game::SNAKE::SnakePart::getPos() const
{
    return this->pos;
}