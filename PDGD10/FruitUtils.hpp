/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** FruitUtils.hpp
*/

#include "FruitBox.hpp"

class FruitUtils
{
    public:
        FruitUtils(void);
        ~FruitUtils();
        void static sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
};
