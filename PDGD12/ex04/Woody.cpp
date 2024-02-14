/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &fileName): Toy(WOODY, name, fileName) {}

Woody::Woody(const std::string &name): Toy(WOODY, name, "woody.txt") {}

Woody::~Woody()
{

}

void Woody::speak(const std::string &str)
{
    std::cout << "WOODY: " << this->getName() << " \"" << str << "\"" << std::endl;
}
