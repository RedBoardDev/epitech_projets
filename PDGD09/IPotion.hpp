/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** IPotion.hpp
*/

#pragma once

// #include "ICharacter.hpp"

class ICharacter;

class IPotion {
    protected:
        int _changeHp;
        int _changePp;
    public:
        IPotion(void) {};
        virtual ~IPotion(void) {};
        virtual void giveEffect(ICharacter &icharacter) const = 0;
};
