/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks):_name(name), _stimPaks(stimPaks) {}

Skat::~Skat() {}

int &Skat::stimPaks()
{
    return (_stimPaks);
}

const std::string &Skat::name(void)
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimPaks - number < 0) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    std::cout << "Keep the change." << std::endl;
    _stimPaks -= number;
    stock += number;
}

void Skat::addStimPaks(unsigned int number)
{
    _stimPaks += number;
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks(void)
{
    if (_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stimPaks -= 1;
    }
}

void Skat::status(void)
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
