#include "../includes/SFML.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <dirent.h>


static std::string findAFont()
{
    DIR *dir;
    struct dirent *ent;
    std::string tmp;
    std::string path;

    DIR *indir;
    struct dirent *inent;

    if ((dir = opendir("/usr/share/fonts")) == NULL) {
        exit(84);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            tmp = "/usr/share/fonts/";
            tmp += ent->d_name;
            if (tmp != "." && tmp != ".." && (indir = opendir(tmp.c_str())) != NULL) {
                path = tmp.c_str();
                path += "/";
                while ((inent = readdir(indir)) != NULL) {
                    if (inent->d_type == DT_REG) {
                        tmp = inent->d_name;
                        if (tmp.find(".ttf") != std::string::npos) {
                            path += tmp;
                            closedir(indir);
                            closedir(dir);
                            return path;
                        }
                    }
                }
                closedir(indir);
            }
        }
    }
    closedir(dir);
    exit(84);
}

Arcade::Graphics::SFML::SFML(size_t winX, size_t winY)
{
    this->win = std::make_unique<sf::RenderWindow>(sf::VideoMode(winX, winY), "SFML", 0);
    this->texture = std::make_unique<sf::Texture>();
    this->texture.get()->create(winX, winY);
    this->sprite = std::make_unique<sf::Sprite>();
    this->fbr = new sf::Uint8[winX * winY * 4];
    this->sprite.get()->setTexture(*(this->texture.get()));
    this->winSize.first = winX;
    this->winSize.second = winY;
    this->win.get()->setFramerateLimit(60);
    if (!(this->font.loadFromFile("/usr/share/fonts/dejavu-sans-fonts/DejaVuSans.ttf")))
        if (!(this->font.loadFromFile(findAFont())))
            exit(84);

    text.setFont(this->font);
    text.setCharacterSize(20);
}

Arcade::Graphics::SFML::~SFML()
{

}

void Arcade::Graphics::SFML::setFrameRateLimit(int limit)
{
    this->win->setFramerateLimit(limit);
}

bool Arcade::Graphics::SFML::isOpen()
{
    return this->win->isOpen();
}

static bool isInEvents(std::vector<Arcade::Graphics::IDisplayModule::Events> events, Arcade::Graphics::IDisplayModule::Events event)
{
    for (int i = 0; i < events.size(); ++i) {
        if (events[i] == event)
            return true;
    }
    return false;
}

void Arcade::Graphics::SFML::refreshWin()
{
    eventList.clear();
    sf::Event event;
    Arcade::Graphics::IDisplayModule::Events tmp;
    bool pass = false;

    while(this->win.get()->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (event.key.code >= 0 && event.key.code <= 25) {
                tmp = (Arcade::Graphics::IDisplayModule::Events)event.key.code;
                pass = true;
            }
            if (event.key.code == 73) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyUp;
                pass = true;
            }
            if (event.key.code == 74) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyDown;
                pass = true;
            }
            if (event.key.code == 71) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyLeft;
                pass = true;
            }
            if (event.key.code == 72) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyRight;
                pass = true;
            }
            if (event.key.code >= 76 && event.key.code <= 84) {
                tmp = (Arcade::Graphics::IDisplayModule::Events)(event.key.code - 46);
                pass = true;
            }
            if (event.key.code == 57) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keySpace;
                pass = true;
            }
            if (event.key.code == 36) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyEscape;
                pass = true;
            }
            if (event.key.code == 58) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyEnter;
                pass = true;
            }
            if (event.key.code == 59) {
                tmp = Arcade::Graphics::IDisplayModule::Events::backSpace;
                pass = true;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
            if (event.key.code == 0)
                tmp = Arcade::Graphics::IDisplayModule::Events::leftClic;
            else if (event.key.code == 1)
                tmp = Arcade::Graphics::IDisplayModule::Events::rightClic;
            pass = true;
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
            if (pass && !isInEvents(this->eventList, tmp))
                this->eventList.push_back(tmp);
        }
        if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased ) {
            if (pass) {
                for (auto i = this->eventList.begin(); i != this->eventList.end(); ++i) {
                    if ((*i) == tmp) {
                        this->eventList.erase(i);
                        break;
                    }
                }
            }
        }
        if (event.type == sf::Event::Closed) {
            tmp = Arcade::Graphics::IDisplayModule::Events::close;
            if (!isInEvents(this->eventList, tmp))
                this->eventList.push_back(tmp);
        }
    }

    sf::Vector2i temp = sf::Mouse::getPosition(*(this->win.get()));
    this->mousePos.first = (int) temp.x;
    this->mousePos.second = (int) temp.y;

    this->texture.get()->update(this->fbr,this->winSize.first, this->winSize.second, 0, 0);
    this->win.get()->draw(*(this->sprite.get()));
    this->win.get()->display();
}

void Arcade::Graphics::SFML::putpixel(int x, int y, unsigned int color)
{
    this->fbr[(y * this->winSize.first + x) * 4] = (color >> 24) % 256;
    this->fbr[(y * this->winSize.first + x) * 4 + 1] = (color >> 16) % 256;
    this->fbr[(y * this->winSize.first + x) * 4 + 2] = (color >> 8) % 256;
    this->fbr[(y * this->winSize.first + x) * 4 + 3] = color % 256;
}

void Arcade::Graphics::SFML::clearWin()
{
    for (int i = 0; i < this->winSize.first * this->winSize.second * 4; ++i) {
        this->fbr[i] = 0;
    }
    this->win.get()->clear(sf::Color::Black);

}

std::vector<Arcade::Graphics::IDisplayModule::Events> Arcade::Graphics::SFML::getEvents()
{
    return this->eventList;
}

std::pair<int, int> Arcade::Graphics::SFML::getMousePos()
{
    return this->mousePos;
}

void Arcade::Graphics::SFML::puttext(int x, int y, unsigned int color, const std::string &str)
{
    text.setString(str);
    text.setFillColor(sf::Color((color >> 24) % 256, (color >> 16) % 256,(color >> 8) % 256,color % 256));
    text.setPosition(sf::Vector2f(x, y));
    this->win->draw(text);
    return;
}
