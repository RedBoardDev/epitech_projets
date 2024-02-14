/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Command.hpp
*/

#pragma once

#include <iostream>
#include <functional>
#include <map>

class Command
{
    public:
        class Error: public std::exception
        {
            public:
                std::string _feurError;
                Error(std::string str) { _feurError = str; };
                ~Error() {};
                virtual const char *what() const noexcept override { return _feurError.c_str(); };
        };
        Command() {};
        ~Command() {};
        void registerCommand(const std::string &name, const std::function<void()>&function);
        void executeCommand(const std::string &name);
    private:
        std::map<std::string, std::function<void()>> _map;
};
