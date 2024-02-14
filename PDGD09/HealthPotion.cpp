/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** HealthPotion.cpp
*/

#include "HealthPotion.hpp"
#include <iostream>

HealthPotion::HealthPotion(void)
{
    _changeHp = 50;
    _changePp = 0;
}


void HealthPotion::giveEffect(ICharacter &icharacter) const
{
    icharacter.setHp(icharacter.getHp() - this->_changeHp);
    icharacter.setPower(icharacter.getPower() - this->_changePp);
}

HealthPotion::~HealthPotion(void) {}
