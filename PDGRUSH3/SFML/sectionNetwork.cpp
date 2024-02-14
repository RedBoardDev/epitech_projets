/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#include "sectionNetwork.hpp"

void sectionNetwork::setText(sf::Vector2f vect, float charSize)
{
    size_t index = 0;
    std::string str;
    this->_font.loadFromFile("SFML/a_absolute_empire/aAbsoluteEmpire.ttf");

    while (index != this->infoTxt.size()) {
        if (index == _NAME) {
            this->infoTxt.at(index).setString("Name : " + get.g_network_ssid());
            vect.y += 10;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _PING) {
            get.s_network_ping();
            this->infoTxt.at(index).setString("Ping : " + get.g_network_ping());
            vect.y += 20;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _HOSTNAME) {
            this->infoTxt.at(index).setString("Hostname : " + get.g_hostname());
            vect.y += 30;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _Bandwidth) {
            this->infoTxt.at(index).setString("Bandwidth : " + get.g_bandwidth());
            vect.y += 40;
            this->infoTxt.at(index).setPosition(vect);
        }

        this->infoTxt.at(index).setFont(this->_font);
        this->infoTxt.at(index).setCharacterSize(charSize);
        sf::Color color(37,50,78);
        this->infoTxt.at(index).setFillColor(color);
        index++;
    }
}
