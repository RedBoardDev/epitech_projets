/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD11-thomas.ott
** File description:
** IDirectoryLister.hpp
*/

#pragma once

#include <dirent.h>
#include <iostream>

class IDirectoryLister
{
    public:
        IDirectoryLister() {};
        virtual ~IDirectoryLister() {};
        virtual bool open(const std::string& path, bool hidden) = 0;
        virtual std::string get() = 0;
};
