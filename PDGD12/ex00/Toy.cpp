/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD12-thomas.ott
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = Picture();
}

Toy::Toy(Toy::ToyType toyType, const std::string &name, const std::string &fileName)
{
    _type = toyType;
    _name = name;
    _picture = Picture(fileName);
}

Toy::~Toy()
{

}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(const std::string name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return(_picture.getPictureFromFile(file));
}

std::string Toy::getAscii() const
{
    return (_picture._data);
}
