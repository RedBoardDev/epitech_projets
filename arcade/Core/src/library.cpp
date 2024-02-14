#include "../includes/core.hpp"
#include "../includes/library.hpp"
#include "../includes/DlLoad.hpp"

#include <memory>
#include <dirent.h>
#include <algorithm>
#include <filesystem>

Arcade::Library::Library(std::string arg1)
{
    std::string tmp;
    std::string path = this->getFilePath(arg1);
    this->setGameLibraryNbr(0);
    this->setGraphicalibraryNbr(0);
    this->_libPath = this->getFilePath(arg1);
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        tmp = entry.path().filename().string();
        if (tmp == "." || tmp == "..") continue;
        if (this->checkFileName(tmp) == false) continue;
        DLLoader tempDisplay(this->_libPath + tmp);
        bool (*isGraphic)() = tempDisplay.getInstance<bool ()>("isGraphic");
        if (isGraphic()) {
            this->_listOfLibraryGraphic.push_back(tmp);
            this->setGraphicalibraryNbr(this->getGraphicalibraryNbr() + 1);
        } else {
            this->_listOfLibraryGame.push_back(tmp);
            this->setGameLibraryNbr(this->getGameLibraryNbr() + 1);
        }
    }
    this->_libraryGame = "";
    this->_libraryGraphics = "";
}

std::string Arcade::Library::getFilePath(std::string str)
{
    int i = str.length();
    std::string filepath;

    for (; str[i] != '/'; --i);
    ++i;
    for (int r = 0; r < i; ++r)
        filepath += str[r];
    return filepath;
}

void Arcade::Library::setGameLibraryNbr(int nbr)
{
    this->_gamelibraryNbr = nbr;
}

int Arcade::Library::getGameLibraryNbr()
{
    return this->_gamelibraryNbr;
}

void Arcade::Library::setGraphicalibraryNbr(int nbr)
{
    this->_graphicalLibraryNbr = nbr;
}

int Arcade::Library::getGraphicalibraryNbr()
{
    return this->_graphicalLibraryNbr;
}

void Arcade::Library::setActualLibraryByNext(lib_type type)
{
    int i = 0;
    int size = 0;

    std::string buffStr = (type == Arcade::Library::LIB_GRAPHIC ? this->_libraryGraphics : this->_libraryGame);
    std::vector<std::string> buffVect = (type == Arcade::Library::LIB_GRAPHIC ? this->_listOfLibraryGraphic : this->_listOfLibraryGame);
    size = buffVect.size();
    for (const std::string item: buffVect) {
        if (item == buffStr) {
            if (i >= size - 1) {
                buffStr = buffVect.front();
            } else
                buffStr = buffVect[i + 1];
            if (type == Arcade::Library::LIB_GRAPHIC)
                this->_libraryGraphics = buffStr;
            else
                this->_libraryGame = buffStr;
            break;
        }
        ++i;
    }
}

void Arcade::Library::setActualLibraryByPrevious(lib_type type)
{
    int i = 0;

    std::string buffStr = (type == Arcade::Library::LIB_GRAPHIC ? this->_libraryGraphics : this->_libraryGame);
    std::vector<std::string> buffVect = (type == Arcade::Library::LIB_GRAPHIC ? this->_listOfLibraryGraphic : this->_listOfLibraryGame);
    for (const std::string item: buffVect) {
        if (item == buffStr) {
            if (i <= 0) {
                buffStr = buffVect.back();
            } else
                buffStr = buffVect[i - 1];
            if (type == Arcade::Library::LIB_GRAPHIC)
                this->_libraryGraphics = buffStr;
            else
                this->_libraryGame = buffStr;
            break;
        }
        ++i;
    }
}

bool Arcade::Library::checkFileName(std::string file)
{
    int i = 0;
    int r = 0;
    std::string eq = "arcade";
    std::string extension = ".so";

    if (file.find("arcade", 0, 6) != 0) return false;
    for (r = 3, i = file.length(); r > 0 && file[i] == extension[r]; --i, --r);
    if (extension[r] - file[i] != 0) return false;
    return true;
}

const std::vector<std::string> Arcade::Library::getListOfLibrary(lib_type type) const
{
    return (type == LIB_GRAPHIC ? this->_listOfLibraryGraphic : this->_listOfLibraryGame);
}

bool Arcade::Library::checkIfLibraryExist(lib_type type, std::string filename)
{
    std::vector<std::string> library = this->getListOfLibrary(type);
    if (std::find(library.begin(), library.end(), filename) != library.end())
        return true;
    return false;
}

const std::string Arcade::Library::getActualGameLibrary() const
{
    return this->_libraryGame;
}

const std::string Arcade::Library::getActualGraphicalLibrary() const
{
    return this->_libraryGraphics;
}

void Arcade::Library::setActualGameLibrary(std::string filepath)
{
    this->_libraryGame = filepath;
}

void Arcade::Library::setactualGraphicalLibrary(std::string filename)
{
    this->_libraryGraphics = filename;
}

const std::string Arcade::Library::getFilenameOnFilepath(const std::string &filepath) const
{
    int i = 0;
    int r = 0;
    std::string filename;

    for (; filepath[i] != '\0'; ++i)
        if (filepath[i] == '/') r = i;
    for (i = 0, ++r; filepath[r] != '\0'; ++r, ++i)
        filename += filepath[r];
    return filename;
}

int Arcade::initLibrary(Arcade::Library &cLibrary, std::string filepath)
{
    std::string filename = cLibrary.getFilenameOnFilepath(filepath);
    if (!cLibrary.checkIfLibraryExist(Arcade::Library::LIB_GRAPHIC, filename))
        return 84;
    cLibrary.setactualGraphicalLibrary(filename);
    return 0;
}

unsigned int Arcade::Library::compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return r << 24 | g << 16 | b << 8 | a;
}
