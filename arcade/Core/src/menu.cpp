#include "../includes/menu.hpp"
#include "../includes/core.hpp"
#include "../includes/DlLoad.hpp"
#include <algorithm>

void Arcade::Core::Menu::putGameScoreBoard(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical, const std::string &library) {
    int YMove = 0;
    int XMove = 0;
    std::vector<std::pair<std::string, int>> scores = this->getScoreForGame(library);
    graphical->puttext(900 + XMove, 100 + YMove, cLibrary.compresFromRgba(255,255,255,255), (library + " scoreboard:"));
    for (const auto &score : scores) {
        YMove += 50;
        graphical->puttext(900 + XMove, 100 + YMove, cLibrary.compresFromRgba(255,255,255,255), (score.first + " has " + std::to_string(score.second)) + " points.");
    }
}

void Arcade::Core::Menu::handlingLibrary(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical) {
    int YCenter = 100;
    int XCenter = 100;
    int YMove = 100;
    int XMove = 0;
    int cursor = 0;
    std::vector<std::string> listOfLibrary;
    int allLibraryNbr = cLibrary.getGameLibraryNbr() + cLibrary.getGraphicalibraryNbr();
    std::vector<Arcade::Graphics::IDisplayModule::Events> events = graphical->getEvents();

    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyDown) && NOW - this->timerKey >= M_DELAY_KEYBOARD) {
        this->timerKey = NOW;
        if (this->_statusSelectGraphicalLibrary == -1)
            this->_cursorLibrary = this->_cursorLibrary + 1 >= cLibrary.getGraphicalibraryNbr() ? 0 : this->_cursorLibrary += 1;
        else
            this->_cursorLibrary = this->_cursorLibrary + 1 >= allLibraryNbr ? cLibrary.getGraphicalibraryNbr() : this->_cursorLibrary += 1;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyUp) && NOW - this->timerKey >= M_DELAY_KEYBOARD) {
        this->timerKey = NOW;
        if (this->_statusSelectGraphicalLibrary == -1)
            this->_cursorLibrary = this->_cursorLibrary - 1 < 0 ? cLibrary.getGraphicalibraryNbr() - 1 : this->_cursorLibrary -= 1;
        else
            this->_cursorLibrary = this->_cursorLibrary - 1 < cLibrary.getGraphicalibraryNbr() ? allLibraryNbr - 1 : this->_cursorLibrary -= 1;
    }

    graphical->puttext(1500, 50, cLibrary.compresFromRgba(255,255,255,255), "Your pseudo: " + this->_username);

    graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), "Graphical library:");
    XMove += 60;
    listOfLibrary = cLibrary.getListOfLibrary(Arcade::Library::LIB_GRAPHIC);
    for (const auto library: listOfLibrary) {
        if (cursor == this->_cursorLibrary) {
            graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), "|- " + library);
            cLibrary.setactualGraphicalLibrary(library);
        } else
            graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), library);
        cursor++;
        XMove += 50;
    }

    XMove += 100;
    graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), "Game library:");
    XMove += 60;
    listOfLibrary = cLibrary.getListOfLibrary(Arcade::Library::LIB_GAME);
    for (const auto library: listOfLibrary) {
        if (cursor == this->_cursorLibrary) {
            graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), "|-" + library);
            cLibrary.setActualGameLibrary(library);

            this->putGameScoreBoard(cLibrary, graphical, library.substr(0, library.length() - 3));

        } else
            graphical->puttext(YCenter + YMove, XCenter + XMove, cLibrary.compresFromRgba(255,255,255,255), library);
        cursor++;
        XMove += 50;
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyEnter) && NOW - this->timerKey >= M_DELAY_KEYBOARD) {
        this->timerKey = NOW;
        if (this->_statusSelectGraphicalLibrary == -1) {
            this->_cursorLibrary = cLibrary.getGraphicalibraryNbr();
            this->_statusSelectGraphicalLibrary = cursor;
        } else {
            this->_menu = M_GAME;
            this->_cursorLibrary = 0;
            this->_statusSelectGraphicalLibrary = -1;
        }
    }
    int i = 500;
    graphical->puttext(1500, 680 - i, cLibrary.compresFromRgba(255,255,255,255), "Key mapping:");
    graphical->puttext(1500, 750 - i, cLibrary.compresFromRgba(255,255,255,255), "E - reset the game");
    graphical->puttext(1500, 800 - i, cLibrary.compresFromRgba(255,255,255,255), "ECHAP - quit the game");
    graphical->puttext(1500, 850 - i, cLibrary.compresFromRgba(255,255,255,255), "O - set the previous graphical library");
    graphical->puttext(1500, 900 - i, cLibrary.compresFromRgba(255,255,255,255), "P - set the next graphical library");
    graphical->puttext(1500, 950 - i, cLibrary.compresFromRgba(255,255,255,255), "L - set the previous game library");
    graphical->puttext(1500, 1000 - i, cLibrary.compresFromRgba(255,255,255,255), "M - set the next game library");
}

void Arcade::Core::Menu::configUsername(Arcade::Library &cLibrary, const std::unique_ptr<Arcade::Graphics::IDisplayModule> &graphical) {
    std::vector<Arcade::Graphics::IDisplayModule::Events> events = graphical->getEvents();

    graphical->puttext(1920 / 2 - 140, 1080 / 2 - 100, cLibrary.compresFromRgba(255,255,255,255), "Put your username:");
    for (const Arcade::Graphics::IDisplayModule::Events &event : events) {
        if (event >= Arcade::Graphics::IDisplayModule::Events::A && event <= Arcade::Graphics::IDisplayModule::Events::Z)
            this->_username += static_cast<char>(event - Arcade::Graphics::IDisplayModule::Events::A + 'a');
    }
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::keyEnter) && NOW - this->timerKey >= M_DELAY_KEYBOARD && this->_username.size() > 0)
        this->_menu = M_MENU;
    if (Arcade::checkEventKey(events, Arcade::Graphics::IDisplayModule::Events::backSpace) && NOW - this->timerKey >= M_DELAY_KEYBOARD)
        if (!this->_username.empty()) this->_username.pop_back();
    graphical->puttext(1920 / 2 - 140, 1080 / 2 - 50, cLibrary.compresFromRgba(255,255,255,255), this->_username);
}
