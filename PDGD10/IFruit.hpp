/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** IFruit.hpp
*/

#pragma once

#include <iostream>

class IFruit
{
    protected:
        bool _peeled;
        unsigned int _vitamins;
        std::string _name;
    public:
        IFruit() {};
        virtual ~IFruit() {};
        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &IFruit);
