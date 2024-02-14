/*
** EPITECH PROJECT, 2022
** ex06
** File description:
** ToyStory.cpp
*/

#include <fstream>
#include "ToyStory.hpp"

void ToyStory::tellMeAStory(const std::string &story, Toy &toy1, bool (Toy::*func1)(const std::string &str), Toy &toy2, bool (Toy::*func2)(const std::string &str))
{
    std::cout << toy1.getAscii() << std::endl << toy2.getAscii() << std::endl;

    bool f = true;
    std::ifstream ifs;
    std::string line;
    int pos;

    ifs.open(story);
    if (!ifs.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    while (toy1.getLastError().type == Toy::Error::ErrorType::UNKNOWN && toy2.getLastError().type == Toy::Error::ErrorType::UNKNOWN && std::getline(ifs, line)) {
        if ((pos = line.find("picture:")) != -1) {
            if (f == true) {
                toy1.setAscii(line.substr(8));
                std::cout << toy1.getAscii() << std::endl;
            } else {
                toy2.setAscii(line.substr(8));
                std::cout << toy2.getAscii() << std::endl;
            }

        } else {
            if (f == true) {
                (toy1.*func1)(line);

            } else {
                (toy2.*func2)(line);
            }
        }
        f = (f == true ? false : true);
    }
    if (toy1.getLastError().type != Toy::Error::ErrorType::UNKNOWN)
        std::cout << toy1.getLastError().what() << ": " << toy1.getLastError().where() << std::endl;
    if (toy2.getLastError().type != Toy::Error::ErrorType::UNKNOWN)
        std::cout << toy2.getLastError().what() << ": " << toy2.getLastError().where() << std::endl;
}
