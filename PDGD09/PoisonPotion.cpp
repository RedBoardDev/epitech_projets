/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** PoisonPotion.cpp
*/

#include "PoisonPotion.hpp"

PoisonPotion::PoisonPotion(void)
{
    _changeHp = -50;
    _changePp = 0;
}


void PoisonPotion::giveEffect(ICharacter &icharacter) const
{
    icharacter.setHp(icharacter.getHp() - this->_changeHp);
    icharacter.setPower(icharacter.getPower() - this->_changePp);
}

PoisonPotion::~PoisonPotion(void) {}
