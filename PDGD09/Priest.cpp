/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power): Peasant (name, power), Enchanter (name, power) {
    std::cout << getName() << " enters in the order." << std::endl;
}
Priest::~Priest(void) {
    std::cout << getName() << " finds peace." << std::endl;
}

void Priest::rest(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(100);
    this->setHp(100);
    std::cout << _name << " prays." << std::endl;
}
