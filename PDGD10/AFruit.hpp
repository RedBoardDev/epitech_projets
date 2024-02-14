/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD10-thomas.ott
** File description:
** AFruit.hpp
*/

#pragma once

#include "IFruit.hpp"

class AFruit:public IFruit
{
    public:
        AFruit();
        virtual ~AFruit();
        virtual unsigned int getVitamins() const;
        virtual std::string getName() const;
        virtual bool isPeeled() const;
        virtual void peel();
};
