/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Peasant.cpp
*/

#include "Peasant.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    _name = name;
    _power = power;
    _hp = 100;
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant(void)
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName(void) const
{
    return (_name);
}

int Peasant::getPower(void) const
{
    return (_power);
}

int Peasant::getHp(void) const
{
    return (_hp);
}

void Peasant::setPower(int power)
{
    this->_power = (power > 100 ? 100 : (power < 0 ? 0 : power ));
}

void Peasant::setHp(int hp)
{
    this->_hp = (hp > 100 ? 100 : (hp < 0 ? 0 : hp ));
}

int Peasant::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 10 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - 10);
    std::cout << _name << " tosses a stone." << std::endl;
    return (5);
}

int Peasant::special(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 0 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return (0);
}

void Peasant::rest(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(this->getPower() + 30);
    std::cout << _name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (_hp <= damage)
        std::cout << _name << " is out of combat." << std::endl;
    else
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    this->setHp(this->getHp() - damage);
}

void Peasant::drink(const IPotion &potion)
{
    potion.giveEffect(*this);
    std::cout << this->getName() << " drinks a mysterious potion." << std::endl;
}

void Peasant::drink(const HealthPotion &potion)
{
    potion.giveEffect(*this);
    std::cout << this->getName() << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PoisonPotion &potion)
{
    potion.giveEffect(*this);
    std::cout << this->getName() << " has been poisoned." << std::endl;
}

void Peasant::drink(const PowerPotion &potion)
{
    potion.giveEffect(*this);
    std::cout << this->getName() << "'s power is restored." << std::endl;
}
