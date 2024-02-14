/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** Assistant.cpp
*/

#include "Assistant.hpp"

Assistant::Assistant(int arg1)
{
    ID = arg1;
    check = false;
    std::cout << "Assistant " << ID << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << ID << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *stud, std::string str)
{
    std::cout << "Assistant " << ID << ": drink this, " << stud->getName() << " *sip coffee*" << std::endl;
    stud->drink(str);
}

std::string Assistant::readDrink(std::string stud)
{
    std::string drink_name = "";
    std::string filename = (stud + ".drink");
    std::ifstream file (stud + ".drink");
    if (file.is_open()) {
        getline (file, drink_name);
        std::cout << "Assistant " << ID << ": " << stud << " needs a " << drink_name << " *sip coffee*" << std::endl;
        file.close();
        std::remove(filename.c_str());
        return (drink_name);
    }
    return (drink_name);
}

void Assistant::helpStudent(Student *stud)
{
    std::string drink = readDrink(stud->getName());
    if (!drink.empty()) {
        giveDrink(stud, drink);
    } else
        std::cout << "Assistant " << ID << ": " << stud->getName() << " seems fine *sip coffee*" << std::endl;
}

void Assistant::timeCheck(void)
{
    if (check == true)
        std::cout << "Assistant " << ID << ": Enough teaching for today *sip coffee*" << std::endl;
    else
        std::cout << "Assistant " << ID << ": Time to teach some serious business *sip coffee*" << std::endl;
    check = !check;
}