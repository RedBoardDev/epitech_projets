/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** PoisonPotion.hpp
*/

#pragma once

#include "ICharacter.hpp"
#include "IPotion.hpp"

class PoisonPotion: public IPotion {
    public:
        PoisonPotion(void);
        void giveEffect(ICharacter &icharacter) const;
        ~PoisonPotion(void);
};
