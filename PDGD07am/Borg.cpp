/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** Borg.cpp
*/

#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship(int weaponFrequency)
{
    _side = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _shield = 100;
    _repair = 3;
    _weaponFrequency = weaponFrequency;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    _side = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _shield = 100;
    _repair = repair;
    _weaponFrequency = weaponFrequency;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore(void)
{
    std::cout << (_core->checkReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move()
{
    if (_core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield(void)
{
    return(_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency(void)
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair(void)
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(_weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << " GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency << " GW frequency." << std::endl;
}

void Borg::Ship::repair(void)
{
    if (_repair > 0) {
        _repair -= 1;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else {
        _repair = 100;
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}
