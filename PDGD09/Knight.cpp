/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Knight.cpp
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power): Peasant (name, power) {;
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight(void) {
    std::cout << getName() << " takes off his armor." << std::endl;
}

int Knight::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 10 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - 10);
    std::cout << _name << " strikes with his sword." << std::endl;
    return (20);
}

int Knight::special(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power - 30 < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - 30);
    std::cout << _name << " impales his enemy." << std::endl;
    return (50);
}

void Knight::rest(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(this->getPower() + 50);
    std::cout << _name << " eats." << std::endl;
}
