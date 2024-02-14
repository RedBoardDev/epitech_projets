/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** FruitBox.hpp
*/

#pragma once

#include "IFruit.hpp"
#include <vector>

class FruitBox
{
    public:
        int _size;
        FruitBox(unsigned int size);
        std::vector<IFruit *>  _list;
        ~FruitBox(void);
        unsigned int getSize(void) const;
        unsigned int nbFruits(void) const;
        std::vector<IFruit *> getList() const;
        bool pushFruit(IFruit *feur);
        IFruit *popFruit(void);
};

std::ostream &operator<<(std::ostream &os, const FruitBox &FruitBox);
