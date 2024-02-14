/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** Assistant.hpp
*/

#pragma once

#include "Student.hpp"

class Assistant {
    private:
        unsigned int ID;
        bool check;
    public:
        Assistant();
        Assistant(int arg1);
        void giveDrink(Student *stud, std::string str);
        std::string readDrink(std::string stud);
        void helpStudent(Student *stud);
        void timeCheck(void);
        ~Assistant();
};
