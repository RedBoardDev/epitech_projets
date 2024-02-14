/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD09-thomas.ott
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power): Peasant(name, power), Knight(name, power), Priest(name, power) {
    std::cout << this->getName() << " fights for the light." << std::endl;
}

Paladin::~Paladin(void) {
    std::cout << this->getName() << " is blessed." << std::endl;
}

int Paladin::attack(void) {
    return (Knight::attack());
}

int Paladin::special(void) {
    return (Enchanter::special());
}

void Paladin::rest(void) {
    Priest::rest();
}
