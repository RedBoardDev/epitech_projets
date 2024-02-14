#include <string>
#include <vector>

#pragma once

namespace Arcade
{
    class Library
    {
        private:
            int _gamelibraryNbr;
            int _graphicalLibraryNbr;
            std::string _libraryGame;
            std::string _libraryGraphics;
            std::vector<std::string> _listOfLibraryGame;
            std::vector<std::string> _listOfLibraryGraphic;
        public:
            enum lib_type {
                LIB_GAME,
                LIB_GRAPHIC
            };
            std::string _libPath;
            Library(std::string arg1);
            ~Library() {};
            unsigned int compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            const std::vector<std::string> getListOfLibrary(lib_type type) const;
            bool checkIfLibraryExist(lib_type type, std::string filepath);
            bool checkFileName(std::string file);
            const std::string getActualGameLibrary() const;
            const std::string getActualGraphicalLibrary() const;
            void setActualGameLibrary(std::string filepath);
            void setactualGraphicalLibrary(std::string filepath);
            void setGameLibraryNbr(int nbr);
            int getGameLibraryNbr();
            void setGraphicalibraryNbr(int nbr);
            int getGraphicalibraryNbr();
            void setActualLibraryByNext(lib_type type);
            void setActualLibraryByPrevious(lib_type type);
            const std::string getFilenameOnFilepath(const std::string &filepath) const;
            std::string getFilePath(std::string str);
    };
    int initLibrary(Library &cLibrary, std::string filepath);
}
