/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Knight.hpp
*/

#pragma once

#include "Peasant.hpp"

class Knight:virtual public Peasant
{
    public:
        Knight(const std::string &name, int power);
        ~Knight(void);
        int attack(void);
        int special(void);
        void rest(void);
};
