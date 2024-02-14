/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Enchanter.hpp
*/

#pragma once

#include "Peasant.hpp"

class Enchanter:virtual public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter(void);
        int attack(void);
        int special(void);
        void rest(void);
};
