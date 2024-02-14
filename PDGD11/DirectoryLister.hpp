/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD11-thomas.ott
** File description:
** DirectoryLister.hpp
*/

#pragma once

#include "IDirectoryLister.hpp"

class DirectoryLister: public IDirectoryLister
{
    protected:
        DIR* _dir;
        struct dirent* _ent;
        bool _hidden;
    public:
        DirectoryLister();
        DirectoryLister(const std::string& path, bool hidden);
        ~DirectoryLister();
        bool open(const std::string& path, bool hidden);
        std::string get();
};
