/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")) {
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}


Droid::Droid(const Droid &droid) : _id(droid._id), _energy(droid._energy), _attack(droid._attack), _toughness(droid._toughness), _status(new std::string (*droid._status)) {
    std::cout << "Droid '" << droid._id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void) {
    delete _status;
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}


Droid &Droid::operator=(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete _status;
    _status = new std::string(*droid._status);
    return (*this);
}

bool Droid::operator==(const Droid &droid) const
{
    return (_id == droid._id && _energy == droid._energy && _attack == droid._attack && _toughness == droid._toughness && *_status == *droid._status);
}

bool Droid::operator!=(const Droid &droid) const
{
    return (!(*this == droid));
}

Droid &Droid::operator<<(size_t &energy)
{
    if ((energy + _energy) > 100) {
        energy = energy - (100 - _energy);
        _energy = 100;
    } else {
        _energy += energy;
        energy = 0;
    }
    return (*this);
}


std::ostream &operator<<(std::ostream &os, const Droid &droid)
{
    os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy() ;
    return (os);
}

std::string Droid::getId() const
{
    return _id;
}

void Droid::setId(std::string id)
{
    _id = id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

void Droid::setEnergy(size_t energy)
{
    _energy = (energy > 100 ? 100 : energy);
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _toughness;
}

std::string *Droid::getStatus() const
{
    return _status;
}

void Droid::setStatus(std::string *status)
{
    delete _status;
    _status = (new std::string(*status));
}