/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** ICharacter.hpp
*/

#pragma once

#include <iostream>

class IPotion;
class HealthPotion;
class PoisonPotion;
class PowerPotion;

class ICharacter
{
    public:
        ICharacter(void) {};
        virtual ~ICharacter(void) {};
        virtual const std::string &getName(void) const = 0;
        virtual int getPower(void) const = 0;
        virtual void setPower(int power) = 0;
        virtual int getHp(void) const = 0;
        virtual void setHp(int hp) = 0;
        virtual int attack(void) = 0;
        virtual int special(void) = 0;
        virtual void rest(void) = 0;
        virtual void damage(int damage) = 0;
        virtual void drink(const IPotion &potion) = 0;
        virtual void drink(const HealthPotion &potion) = 0;
        virtual void drink(const PoisonPotion &potion) = 0;
        virtual void drink(const PowerPotion &potion) = 0;
};
