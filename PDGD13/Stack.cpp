/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Stack.cpp
*/

#include "Stack.hpp"
#include <stdexcept>

void Stack::push(double value)
{
    this->_stack.push(value);
}

double Stack::pop()
{
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");
    double t = this->_stack.top();
    this->_stack.pop();
    return (t);
}

double Stack::top() const
{
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");
    return this->_stack.top();
}

void Stack::add()
{
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double feur1 = this->_stack.top();
    this->_stack.pop();
    double feur2 = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(feur1 + feur2);
}

void Stack::sub()
{
     if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double feur1 = this->_stack.top();
    this->_stack.pop();
    double feur2 = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(feur1 - feur2);
}

void Stack::mul()
{
     if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double feur1 = this->_stack.top();
    this->_stack.pop();
    double feur2 = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(feur1 * feur2);
}

void Stack::div()
{
     if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double feur1 = this->_stack.top();
    this->_stack.pop();
    double feur2 = this->_stack.top();
    this->_stack.pop();
    if (feur2 != 0)
        this->_stack.push(feur1 / feur2);
    else
        this->_stack.push(0);
}
