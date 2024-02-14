/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

// Arms

Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Arms::isFunctional(void) const
{
    return (_functional);
}

std::string Arms::serial(void) const
{
    return (_serial);
}

void Arms::informations(void) const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

Arms::~Arms(void) {}

// Legs

Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Legs::isFunctional(void) const
{
    return (_functional);
}

std::string Legs::serial(void) const
{
    return (_serial);
}

void Legs::informations(void) const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

Legs::~Legs(void) {}

// Head

Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Head::isFunctional(void) const
{
    return (_functional);
}

std::string Head::serial(void) const
{
    return (_serial);
}

void Head::informations(void) const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

Head::~Head(void) {}
