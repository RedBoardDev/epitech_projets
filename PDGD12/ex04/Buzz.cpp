/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &fileName): Toy(BUZZ, name, fileName) {}

Buzz::Buzz(const std::string &name): Toy(BUZZ, name, "buzz.txt") {}

Buzz::~Buzz()
{

}

void Buzz::speak(const std::string &str)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << str << "\"" << std::endl;
}