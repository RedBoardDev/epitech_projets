/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#include "sectionRAM.hpp"

void sectionRAM::setText(sf::Vector2f vect, float charSize)
{
    size_t index = 0;
    std::string str;
    this->_font.loadFromFile("SFML/a_absolute_empire/aAbsoluteEmpire.ttf");

    while (index != this->infoTxt.size()) {
        if (index == _TOTALRAMAVAILABLE) {
            this->infoTxt.at(index).setString("TOTAL : " + get.g_memory_total() + "GB");
            vect.y += 10;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _RAMAVAILABLE) {
            get.s_memory_available();
            this->infoTxt.at(index).setString("USED : " + get.g_memory_available() + "GB");
            vect.y += 20;
            this->infoTxt.at(index).setPosition(vect);
        }
        this->infoTxt.at(index).setFont(this->_font);
        this->infoTxt.at(index).setCharacterSize(charSize);
        sf::Color color(37,50,78);
        this->infoTxt.at(index).setFillColor(color);
        index++;
    }
}
