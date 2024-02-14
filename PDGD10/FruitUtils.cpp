/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** FruitUtils.cpp
*/

#include "FruitUtils.hpp"
#include "Lemon.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"

FruitUtils::FruitUtils(void)
{

}

FruitUtils::~FruitUtils()
{

}

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    for (size_t i = 0; i < unsorted.nbFruits(); ++i) {
        IFruit *fds = unsorted.getList()[i];
        if (dynamic_cast<Lemon*>(fds)) {
            if (lemon.pushFruit(fds))
                unsorted._list.erase(unsorted._list.begin() + i--);
        } else if (dynamic_cast<ACitrus*>(fds)) {
            if (citrus.pushFruit(fds))
                unsorted._list.erase(unsorted._list.begin() + i--);
        } else if (dynamic_cast<ABerry*>(fds)) {
            if (berry.pushFruit(fds))
                unsorted._list.erase(unsorted._list.begin() + i--);
        }
    }
}
