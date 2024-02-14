/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")) {
    std::cout << "Droid '" << id << "' Activated" << std::endl;
}


Droid::Droid(const Droid &tmp) : _id(tmp._id), _energy(50), _attack(25), _toughness(15), _status(new std::string (*tmp._status)), _battleData(tmp._battleData) {
    std::cout << "Droid '" << tmp._id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void) {
    delete _status;
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &tmp)
{
    if (&tmp != this) {
        this->_id = tmp._id;
        this->_energy = tmp._energy;
        _status = tmp._status;
    }
    return (*this);
}

bool Droid::operator==(const Droid &tmp) const
{
    return (_status == tmp._status);
}

bool Droid::operator!=(const Droid &tmp) const
{
    return (!(this->_status == tmp._status));
}

Droid &Droid::operator<<(size_t energy)
{
    this->_energy += energy;
    if (this->_energy > 100)
        this->_energy = 100;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Droid &d)
{
    os << "Droid '" << d.getId() << "', " << *d.getStatus() << ", " << d.getEnergy() << "";
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
    _status = status;
}

DroidMemory *Droid::getBattleData() const
{
    return (_battleData);
}

void Droid::setBattleData(DroidMemory *feur)
{
    delete _battleData;
    _battleData = feur;
}

bool Droid::operator()(const std::string* task, size_t task_nb) {
        if (_energy < 10) {
            _status = new std::string ("Battery Low");
            return false;
        }
        if (task_nb <= getBattleData()->getExp()) {
            this->getBattleData()->setExp(this->getBattleData()->getExp() + task_nb / 2);
            _status = new std::string (*task + " - Completed!");
        } else {
            this->getBattleData()->setExp(this->getBattleData()->getExp() + task_nb);
            _status = new std::string (*task + " - Failed!");
        }
        _energy -= 10;
        return true;
}
