/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(void)
{
    _exp = 0;
    _fingerprint = random();
}

DroidMemory::DroidMemory(DroidMemory &mem1)
{
    _exp = mem1.getExp();
    _fingerprint = mem1.getFingerprint();
}

size_t DroidMemory::getFingerprint() const
{
    return (_fingerprint);
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const
{
    return (_exp);
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

DroidMemory::~DroidMemory(void)
{

}

DroidMemory &DroidMemory::operator<<(DroidMemory &droidmemory)
{
    this->_exp += droidmemory.getExp();
    this->_fingerprint ^= droidmemory.getFingerprint();
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &droidmemory)
{
    droidmemory.setExp(droidmemory.getExp() + this->getExp());
    droidmemory.setFingerprint(droidmemory.getFingerprint() ^ this->getFingerprint());
    return (droidmemory);
}

DroidMemory &DroidMemory::operator+=(DroidMemory &droidmemory)
{
    this->_exp += droidmemory.getExp();
    this->_fingerprint ^= droidmemory.getFingerprint();
    return (*this);
}

DroidMemory &DroidMemory::operator+=(size_t d)
{
    this->_exp += d;
    this->_fingerprint ^= d;
    return (*this);
}

DroidMemory &DroidMemory::operator+(DroidMemory &tmp)
{
    DroidMemory *droidmemory = new DroidMemory;
    droidmemory->_exp = _exp + tmp._exp;
    droidmemory->_exp = _fingerprint ^ tmp._fingerprint;
    return (*droidmemory);
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &d)
{
    os << "DroidMemory '" << d.getFingerprint() << "', " << d.getExp();
    return (os);
}

bool DroidMemory::operator==(DroidMemory &droidmemory) const
{
    return (droidmemory.getExp() == droidmemory.getFingerprint());
}

bool DroidMemory::operator!=(DroidMemory &droidmemory) const
{
    return (droidmemory.getExp() != droidmemory.getFingerprint());
}

DroidMemory &DroidMemory::operator=(DroidMemory &droidmemory)
{
    if (&droidmemory != this) {
        this->_exp = droidmemory.getExp();
        this->_fingerprint = droidmemory.getFingerprint();
    }
    return (*this);
}

bool DroidMemory::operator<(DroidMemory &droidmemory) const
{
    return (this->getExp() < droidmemory.getExp());
}

bool DroidMemory::operator>(DroidMemory &droidmemory) const
{
    return (this->getExp() > droidmemory.getExp());
}

bool DroidMemory::operator<=(DroidMemory &droidmemory) const
{
    return (this->getExp() <= droidmemory.getExp());
}

bool DroidMemory::operator>=(DroidMemory &droidmemory) const
{
    return (this->getExp() >= droidmemory.getExp());
}

// size_t
bool DroidMemory::operator<(size_t exp) const
{
    return (this->getExp() < exp);
}

bool DroidMemory::operator>(size_t exp) const
{
    return (this->getExp() > exp);
}

bool DroidMemory::operator<=(size_t exp) const
{
    return (this->getExp() <=exp);
}

bool DroidMemory::operator>=(size_t exp) const
{
    return (this->getExp() >=exp);
}
