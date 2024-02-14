/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"
#include <algorithm>

FruitBox::FruitBox(unsigned int size)
{
    _size = size;
}

FruitBox::~FruitBox(void)
{
    for (const auto &f : this->getList())
        delete f;
}

unsigned int FruitBox::getSize(void) const
{
    return (_size);
}

unsigned int FruitBox::nbFruits(void) const
{
    return (this->_list.size());
}

bool FruitBox::pushFruit(IFruit *feur)
{
    if (this->nbFruits() >= this->getSize() || std::find(std::begin(this->_list), std::end(this->_list), feur) != std::end(this->_list))
        return (false);
    this->_list.push_back(feur);
    return (true);
}

IFruit *FruitBox::popFruit(void)
{
    if (this->nbFruits() <= 0)
        return (nullptr);
    IFruit *first = this->_list.front();
    this->_list.erase(this->_list.begin());
    return (first);
}

std::vector<IFruit *> FruitBox::getList() const
{
    return (this->_list);
}

std::ostream &operator<<(std::ostream &os, const FruitBox &box)
{
    int i = 0;
    int len = box.nbFruits();
    os << "[";
    for (const auto &f : box.getList()) {
        os << "[name: \"" << f->getName() << "\", vitamins: " << f->getVitamins() << ", peeled: " << (f->isPeeled() ? "true" : "false");
        ++i;
        if (i < len)
            os << "], ";
        else
            os << "]";
    }
    os << "]";
    return (os);
}
