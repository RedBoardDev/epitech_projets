/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD12-thomas.ott
** File description:
** Picture.cpp
*/

#include <fstream>
#include <sstream>
#include "Picture.hpp"

Picture::Picture()
{
    _data = "";
}

Picture::Picture(const std::string &file)
{
    std::ifstream ifs;
    ifs.open(file);
    if (ifs.is_open() == true) {
        std::stringstream strStream;
        strStream << ifs.rdbuf();
        _data = strStream.str();
        ifs.close();
    } else {
        _data = "ERROR";
    }
}

Picture::Picture(Picture const &picture)
{
    this->_data = picture._data;
}

Picture::~Picture()
{

}

Picture &Picture::operator=(Picture const &rhs)
{
    this->_data = rhs._data;
    return (*this);
}

bool Picture::getPictureFromFile(const std::string & file)
{
    std::ifstream ifs;
    ifs.open(file);
    if (ifs.is_open() == true) {
        std::stringstream strStream;
        strStream << ifs.rdbuf();
        _data = strStream.str();
        ifs.close();
    } else {
        _data = "ERROR";
        return false;
    }
    return true;
}
