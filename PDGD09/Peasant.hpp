/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Peasant.hpp
*/

#pragma once

#include "ICharacter.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

class Peasant: public ICharacter
{
    protected:
        std::string _name;
        int _power;
        int _hp;
    public:
        Peasant(const std::string &name, int power);
        ~Peasant(void);
        const std::string &getName(void) const;
        int getPower(void) const;
        void setPower(int power);
        int getHp(void) const;
        void setHp(int hp);
        int attack(void);
        int special(void);
        void rest(void);
        void damage(int damage);
        void drink(const IPotion &potion);
        void drink(const HealthPotion &potion);
        void drink(const PoisonPotion &potion);
        void drink(const PowerPotion &potion);
};
