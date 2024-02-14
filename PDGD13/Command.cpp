/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Command.cpp
*/

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()>&function)
{
    if (this->_map.count(name) > 0)
        throw Command::Error("Already registered command");
    else
        this->_map[name] = function;

}

void Command::executeCommand(const std::string &name)
{
    if (this->_map.count(name) > 0)
        this->_map[name]();
    else
        throw Command::Error("Unknow command");
}