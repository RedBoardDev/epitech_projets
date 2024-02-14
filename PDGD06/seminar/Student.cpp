/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** Student.cpp
*/

#include "Student.hpp"
#include <algorithm>

Student::Student(std::string naaame)
{
    name = naaame;
    energy_pts = 100;
    std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;
    return;
}

bool Student::learn(std::string str)
{
    if (energy_pts >= 42) {
        energy_pts -= 42;
        std::cout << "Student "<< name << ": " << str << std::endl;
        return true;
    }
    int pos = str.find("C++");
    while (pos != -1) {
        str.replace(pos, 3, "shit");
        pos = str.find("C++");
    }
    std::cout << "Student "<< name << ": " << str << std::endl;
    return false;
}

void Student::drink(std::string str)
{
    if (str == "Red Bull") {
        std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
        energy_pts += 32;
    } else if (str == "Monster") {
        std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
        energy_pts += 64;
    } else {
        std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;
        energy_pts += 1;
    }
}

std::string Student::getName(void)
{
    return (name);
}
