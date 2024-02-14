/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** AFruit.cpp
*/

#include "AFruit.hpp"

AFruit::AFruit() {}

AFruit::~AFruit() {}

std::string AFruit::getName() const
{
    return (_name);
}

bool AFruit::isPeeled() const
{
    return (_peeled);
}

void AFruit::peel()
{
    _peeled = true;
}

unsigned int AFruit::getVitamins() const
{
    return (isPeeled() ? _vitamins : 0);
}
