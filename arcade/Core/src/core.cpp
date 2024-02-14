#include "../includes/core.hpp"
#include "../includes/DlLoad.hpp"
#include "../includes/library.hpp"
#include <algorithm>
#include <unistd.h>


Arcade::Core::Core() {
    this->_menu = M_MENU_USERNAME;
    this->_score = 0;
    this->_cursorLibrary = 0;
}

// EVENTS

bool Arcade::checkEventKey(std::vector<Arcade::Graphics::IDisplayModule::Events> events, Arcade::Graphics::IDisplayModule::Events key) {
    return (std::find(events.begin(), events.end(), key) != events.end());
}

int Arcade::Core::keyEventForGameLoop(Arcade::Library &cLibrary, std::vector<Arcade::Graphics::IDisplayModule::Events> events) {
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyEscape) && NOW - this->timerKey >= 200) {
        this->timerKey = NOW;
        this->setScoreForPlayer(this->_username, cLibrary.getActualGameLibrary(), this->_score);
        return A_LEAVE;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::close) && NOW - this->timerKey >= 200) {
        this->timerKey = NOW;
        this->setScoreForPlayer(this->_username, cLibrary.getActualGameLibrary(), this->_score);
        return A_CLOSE;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::R) && NOW - this->timerKey >= 200) {
        this->timerKey = NOW;
        return A_RESET;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::O) && NOW - this->timerKey >= 200) {
        cLibrary.setActualLibraryByPrevious(Arcade::Library::LIB_GRAPHIC);
        this->timerKey = NOW;
        if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::P) && NOW - this->timerKey >= 200) {
        cLibrary.setActualLibraryByNext(Arcade::Library::LIB_GRAPHIC);
        this->timerKey = NOW;
        if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::L) && NOW - this->timerKey >= 200) {
        cLibrary.setActualLibraryByPrevious(Arcade::Library::LIB_GAME);
        this->timerKey = NOW;
        this->setScoreForPlayer(this->_username, cLibrary.getActualGameLibrary(), this->_score);
        if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
        if (this->loadNewGameLib(cLibrary) == A_ERROR) return A_ERROR;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::M) && NOW - this->timerKey >= 200) {
        cLibrary.setActualLibraryByNext(Arcade::Library::LIB_GAME);
        this->timerKey = NOW;
        this->setScoreForPlayer(this->_username, cLibrary.getActualGameLibrary(), this->_score);
        if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
        if (this->loadNewGameLib(cLibrary) == A_ERROR) return A_ERROR;
    }
    return A_NOTHING;
}

// LIBRARY

int Arcade::Core::loadNewGraphicalLib(Arcade::Library &cLibrary) {
    std::unique_ptr<Arcade::Graphics::IDisplayModule> (*graphicalEntry)(int, int);
    this->_graphicLib.reset();
    this->_graphicLoader.closeDL();
    try {
        this->_graphicLoader.openDL(cLibrary._libPath + cLibrary.getActualGraphicalLibrary());
    } catch(const std::exception &e) {
        std::cerr << "Error: graphical library can't be load." << std::endl;
        return A_ERROR;
    }
    graphicalEntry = this->_graphicLoader.getInstance<std::unique_ptr<Arcade::Graphics::IDisplayModule>(int, int)>("entryPoint");
    this->_graphicLib = graphicalEntry(1920, 1080);
    return A_NOTHING;
}

int Arcade::Core::loadNewGameLib(Arcade::Library &cLibrary) {
    std::unique_ptr<Arcade::Game::IGameModule> (*gameEntry)();
    this->_gameLib.reset();
    this->_gameLoader.closeDL();
    try {
        this->_gameLoader.openDL(cLibrary._libPath + cLibrary.getActualGameLibrary());
    } catch(const std::exception &e) {
        std::cerr << "Error: game library can't be load." << std::endl;
        return A_ERROR;
    }
    gameEntry = this->_gameLoader.getInstance<std::unique_ptr<Arcade::Game::IGameModule>()>("entryPoint");
    this->_gameLib = gameEntry();
    return A_NOTHING;
}

// UTILS FUNCTION

std::pair<int, int> Arcade::Core::long_to_coords(long nbr) {
    return {nbr >> 32, static_cast<int>(nbr)};
}

void Arcade::Core::display_putPixel()
{
    const std::unordered_map<long, unsigned int> &pixelsMap = this->_gameLib->getPixels();
    for (auto it = pixelsMap.begin(); it != pixelsMap.end(); ++it) {
        std::pair<int, int> coords = this->long_to_coords(it->first);
        this->_graphicLib->putpixel(coords.first, coords.second, it->second);
    }
}

// LOOP

int Arcade::Core::mainLoop(Arcade::Library &cLibrary) {
    int ret = 0;

    while (true) {
        if (this->_menu != M_GAME) {
            if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
            ret = this->loopMenu(cLibrary);
            if (ret == A_ERROR) return A_ERROR;
            if (ret == A_LEAVE || ret == A_CLOSE) break;
        } else {
            ret = this->gameLoop(cLibrary);
            if (ret == A_LEAVE || ret == A_CLOSE) this->_menu = M_MENU;
            if (ret == A_ERROR) return A_ERROR;
        }
    }
    this->_graphicLib.reset();
    this->_graphicLoader.closeDL();
    return ret;
}

int Arcade::Core::loopMenu(Arcade::Library &cLibrary) {
    std::vector<Arcade::Graphics::IDisplayModule::Events> events;

    this->_graphicLib->setFrameRateLimit(30);
    this->_cursorLibrary = 0;
    this->_statusSelectGraphicalLibrary = -1;
    while (this->_graphicLib->isOpen()) {
        this->_graphicLib->clearWin();
        events = this->_graphicLib->getEvents();
        if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyEscape)) return A_LEAVE;
        if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::close)) return A_CLOSE;
        if (this->_menu == M_MENU_USERNAME)
            this->configUsername(cLibrary, this->_graphicLib);
        else
            this->handlingLibrary(cLibrary, this->_graphicLib);
        this->_graphicLib->refreshWin();
        if (this->_menu == M_GAME) break;
    }
    return A_NOTHING;
}

int Arcade::Core::gameLoop(Arcade::Library &cLibrary) {
    int ret = A_NOTHING;
    std::vector<Arcade::Graphics::IDisplayModule::Events> events;

    if (this->loadNewGraphicalLib(cLibrary) == A_ERROR) return A_ERROR;
    if (this->loadNewGameLib(cLibrary) == A_ERROR) return A_ERROR;
    this->_graphicLib->setFrameRateLimit(60);
    this->_gameLib->start();
    while (this->_graphicLib->isOpen()) {
        this->_graphicLib->clearWin();
        events = this->_graphicLib->getEvents();
        this->_gameLib->setInputs(events);
        ret = this->keyEventForGameLoop(cLibrary, events);
        if (ret != A_NOTHING) return ret;
        this->_gameLib->refresh();
        this->_graphicLib->puttext(900, 50, cLibrary.compresFromRgba(255,255,255,255), ("Score: " + std::to_string(this->_score)));
        this->display_putPixel();
        this->_graphicLib->refreshWin();
        this->_score = this->_gameLib->getScore();
    }
    return A_NOTHING;
}
