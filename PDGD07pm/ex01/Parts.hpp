/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** Parts.hpp
*/

#pragma once

#include <iostream>

class Arms {
    private:
        bool _functional;
        std::string _serial;
    public:
        Arms(std::string serial = "A-01", bool functional = true);
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;
        ~Arms(void);
};

class Legs {
    private:
        bool _functional;
        std::string _serial;
    public:
        Legs(std::string serial = "L-01", bool functional = true);
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;
        ~Legs(void);
};

class Head {
    private:
        bool _functional;
        std::string _serial;
    public:
        Head(std::string serial = "H-01", bool functional = true);
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;
        ~Head(void);
};
