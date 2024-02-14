/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#include "sectionCPU.hpp"

void sectionCPU::setText(sf::Vector2f vect, float charSize)
{
    size_t index = 0;
    std::string str;
    this->_font.loadFromFile("SFML/a_absolute_empire/aAbsoluteEmpire.ttf");

    while (index != this->infoTxt.size()) {
        if (index == _MODEL) {
            this->infoTxt.at(index).setString(get.g_cpu_model_name());
            vect.y += 10;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _USAGE) {
            get.s_cpu_usage();
            this->infoTxt.at(index).setString("CPU ACTUAL USAGE : " + get.g_cpu_usage() + "%");
            vect.y += 20;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _NBRCORE) {
            this->infoTxt.at(index).setString("CPU NUMBER CORE : " + get.g_cpu_nbr_core());
            vect.y += 30;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _NBRPORCESS) {
            get.s_cpu_process_running();
            this->infoTxt.at(index).setString("NUMBER OF PROCESS : " + get.g_cpu_process_running());
            vect.y += 40;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _TEMPERATURE) {
            get.s_cpu_temp();
            this->infoTxt.at(index).setString("CPU TEMPERATURE : " + get.g_cpu_temp());
            vect.y += 50;
            this->infoTxt.at(index).setPosition(vect);
        }

        this->infoTxt.at(index).setFont(this->_font);
        this->infoTxt.at(index).setCharacterSize(charSize);
        sf::Color color(37,50,78);
        this->infoTxt.at(index).setFillColor(color);
        index++;
    }
}
