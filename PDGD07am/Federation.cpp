/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** Federation.cpp
*/

#include "Federation.hpp"
#include "Borg.hpp"

using namespace Federation;

Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = torpedo;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Starfleet::Ship::Ship(void)
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    _home = EARTH;
    _shield = 100;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

void Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Starfleet::Ship::checkCore(void)
{
    std::cout << "USS " << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

void Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

bool Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Starfleet::Ship::move()
{
    if (_core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

// SHIIIIIIEEEEEELD

int Starfleet::Ship::getShield(void)
{
    return (_shield);
}

void Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Starfleet::Ship::getTorpedo(void)
{
    return (_photonTorpedo);
}

void Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo >= 1) {
        _photonTorpedo -= 1;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - (50 * 1));
        if (_photonTorpedo == 0)
            std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
    } else
        std::cout << _name << ": No enough torpedoes to fire , " << _captain << "!" << std::endl;
}

void Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo >= torpedoes) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - (50 * torpedoes));
        if (_photonTorpedo == 0)
            std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
    } else
        std::cout << _name << ": No enough torpedoes to fire , " << _captain << "!" << std::endl;
}


// A PU STARFLEET

Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _home = VULCAN;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

void Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Ship::checkCore(void)
{
    std::cout << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Ship::move()
{
    if (_core->checkReactor()->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Ship::getCore(void)
{
    return (this->_core);
}

// CAPITAAIIIIIIIIIINN

Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

std::string Starfleet::Captain::getName(void)
{
    return (_name);
}

int Starfleet::Captain::getAge(void)
{
    return (_age);
}

void Starfleet::Captain::setAge(int age)
{
    _age = age;
}
