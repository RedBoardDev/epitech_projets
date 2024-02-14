/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#include "sectionPCinfo.hpp"

void sectionPCinfo::setText(sf::Vector2f vect, float charSize)
{
    size_t index = 0;
    std::string str;
    this->_font.loadFromFile("SFML/a_absolute_empire/aAbsoluteEmpire.ttf");

    while (index != this->infoTxt.size()) {
        if (index == _HOSTNAME) {
            this->infoTxt.at(index).setString("Hostname\n" + get.g_hostname());
            vect.x += 50;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _USERNAME) {
            this->infoTxt.at(index).setString("Username\n" + get.g_computer_name());
            vect.x += 200;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _SYSTEMNAME) {
            this->infoTxt.at(index).setString("System Name\n" + get.g_sysname());
            vect.x += 250;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _KERNELVERS) {
            this->infoTxt.at(index).setString("Kernel Version\n" + get.g_kernel_version());
            vect.x += 300;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _DATE) {
            get.s_current_date();
            this->infoTxt.at(index).setString("Date\n" + get.g_current_date());
            vect.x += 350;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _TIME) {
            get.s_current_time();
            this->infoTxt.at(index).setString("Time\n" + get.g_current_time());
            vect.x += 400;
            this->infoTxt.at(index).setPosition(vect);
        }

        this->infoTxt.at(index).setFont(this->_font);
        this->infoTxt.at(index).setCharacterSize(charSize);
        sf::Color color(37,50,78);
        this->infoTxt.at(index).setFillColor(color);
        index++;
    }
}