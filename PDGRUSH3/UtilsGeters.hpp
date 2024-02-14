/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGRUSH3-robin.denni
** File description:
** UtilsGeters.hpp
*/

#pragma once

#include <fstream>
#include <iomanip>

class UtilsGeters
{
    public:
        std::string readFile(std::string const &file, int line);
        std::string getNetworkInterface();
};
