/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** KoalaBot.cpp
*/

#include "Parts.hpp"
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    std::swap(this->_arms, arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    std::swap(this->_legs, legs);
}

void KoalaBot::swapParts(Head &head)
{
    std::swap(this->_head, head);
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status(void) const
{
    return (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional());
}

KoalaBot::~KoalaBot(void) {}