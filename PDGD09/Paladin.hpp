/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Paladin.hpp
*/

#pragma once

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin:virtual public Peasant, virtual public Knight, virtual public Priest
{
    public:
        Paladin(const std::string &name, int power);
        ~Paladin(void);
        int attack(void);
        int special(void);
        void rest(void);
};
