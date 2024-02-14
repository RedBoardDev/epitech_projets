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
    this->_type = toyType;
    this->_name = name;
    this->_picture = Picture(fileName);
}

Toy::Toy(const Toy &toy)
{
    this->_name = toy._name;
    this->_picture = toy._picture;
    this->_type = toy._type;
}

Toy::Toy::~Toy()
{

}

Toy &Toy::operator=(const Toy &rhs)
{
    this->_name = rhs._name;
    this->_picture = rhs._picture;
    this->_type = rhs._type;
    return (*this);
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(const std::string &name)
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

void Toy::speak(const std::string &str)
{
    std::cout << this->getName() << " \"" << str << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Toy &d)
{
    os << d.getName() << std::endl << d.getAscii() << std::endl;
    return (os);
}

Toy &Toy::operator<<(const std::string &str)
{
    this->_picture._data = str;
    return (*this);
}