/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** HealthPotion.hpp
*/

#pragma once

#include "ICharacter.hpp"
#include "IPotion.hpp"

class HealthPotion: public IPotion {
    public:
        HealthPotion(void);
        void giveEffect(ICharacter &icharacter) const;
        ~HealthPotion(void);
};
