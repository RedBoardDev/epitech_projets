/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Enchanter.cpp
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power): Peasant (name, power) {
    std::cout << getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter(void) {
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 0 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    std::cout << _name << " doesn't know how to fight." << std::endl;
    return (0);
}

int Enchanter::special(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 50 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - 50);
    std::cout << _name << " casts a fireball." << std::endl;
    return (99);
}

void Enchanter::rest(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(100);
    std::cout << _name << " meditates." << std::endl;
}
