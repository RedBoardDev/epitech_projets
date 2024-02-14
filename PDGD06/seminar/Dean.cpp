/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
**  Dean.cpp
*/

#include "Dean.hpp"

Dean::Dean(std::string naaame)
{
    name = naaame;
    check = false;
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids ?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << name << ": Time to go home." << std::endl;
    return;
}

void Dean::teachStudent(Student *stud, std::string lesson)
{
    if (stud->learn(lesson) == false)
        std::cout << "Dean " << name << ": All work and no play makes " << stud->getName() << " a dull student ." << std::endl;
    std::ofstream file (stud->getName() + ".drink");
    int random_variable = std::rand() % 5;
    std::string drink_select = (random_variable == 0) ? "Cristaline" : ((random_variable == 1) ? "Monster" : ((random_variable == 2) ? "Evian" : ((random_variable == 3) ? "Red Bull" : "Sierra Springs")));
    file << drink_select;
    file.close();
}

void Dean::timeCheck(void)
{
    if (check == true)
        std::cout << "Dean " << name << ": Don't forget to close the windows when you leave." << std::endl;
    else
        std::cout << "Dean " << name << ": Where is everyone?" << std::endl;
    check = !check;
}