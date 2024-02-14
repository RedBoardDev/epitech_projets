/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
**  Dean.hpp
*/

#pragma once

#include "Assistant.hpp"

class Dean {
    private:
        std::string name;
        bool check;
    public:
        Dean();
        Dean(std::string name);
        void teachStudent(Student *stud, std::string lesson);
        void timeCheck(void);
        ~Dean();
};
