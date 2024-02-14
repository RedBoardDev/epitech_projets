/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Stack.hpp
*/

#pragma once

#include <stack>
#include <iostream>

class Stack
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

        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();

    private:
        std::stack<double> _stack;
};
