/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** Student.hpp
*/

#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

class Student {
    private:
        unsigned int energy_pts;
        std::string name;
        std::string text;
    public:
        Student();
        Student(std::string name);
        bool learn(std::string str);
        void drink(std::string str);
        std::string getName(void);
        ~Student();
};
