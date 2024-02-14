/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** PowerPotion.cpp
*/

#include "PowerPotion.hpp"
#include "IPotion.hpp"

PowerPotion::PowerPotion(void)
{
    _changeHp = 0;
    _changePp = 50;
}

void PowerPotion::giveEffect(ICharacter &icharacter) const
{
    icharacter.setHp(icharacter.getHp() - this->_changeHp);
    icharacter.setPower(icharacter.getPower() - this->_changePp);
}

PowerPotion::~PowerPotion(void) {}
