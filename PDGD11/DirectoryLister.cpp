/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD11-thomas.ott
** File description:
** DirectoryLister.cpp
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister()
{
    _dir = nullptr;
    _ent = nullptr;
    _hidden = false;
}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden)
{
    _dir = nullptr;
    _ent = nullptr;
    this->_hidden = hidden;
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (_dir != nullptr)
        closedir(_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    this->_hidden = hidden;
    if (_dir != nullptr)
        closedir(_dir);
    _dir = opendir(path.c_str());
    if (_dir == nullptr) {
        perror(path.c_str());
        return (false);
    }
    return (true);
}

std::string DirectoryLister::get()
{
    if (!_dir)
        return "";
    _ent = readdir(_dir);
    if (!_ent)
        return "";
    if (!_hidden && _ent->d_name[0] == '.')
        return get();
    return _ent->d_name;
}
