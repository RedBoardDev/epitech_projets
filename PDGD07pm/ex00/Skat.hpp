/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** Skat.hpp
*/

#pragma once

#include <iostream>

class Skat {
    private:
        std::string _name;
        int _stimPaks;
    public :
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();
    int &stimPaks();
    const std::string &name(void);
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks(void);
    void status(void);
};
