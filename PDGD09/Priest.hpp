/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Priest.hpp
*/

#pragma once

#include "Enchanter.hpp"

class Priest:public Enchanter
{
    public:
        Priest(const std::string &name, int power);
        ~Priest(void);
        void rest(void);
};
