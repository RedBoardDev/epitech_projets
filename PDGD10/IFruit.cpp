/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** IFruit.cpp
*/

#include "IFruit.hpp"

std::ostream &operator<<(std::ostream &os, const IFruit &IFruit)
{
    os << "[name: \"" << IFruit.getName() << "\", vitamins: " << IFruit.getVitamins() << ", peeled: " << (IFruit.isPeeled() ? "true" : "false") << "]";
    return (os);
}
