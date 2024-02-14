/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** PowerPotion.hpp
*/

#pragma once

#include "ICharacter.hpp"
#include "IPotion.hpp"

class PowerPotion: public IPotion {
    public:
        PowerPotion(void);
        void giveEffect(ICharacter &icharacter) const;
        ~PowerPotion(void);
};
