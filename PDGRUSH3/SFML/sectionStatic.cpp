/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#include "sectionStatic.hpp"
#include <thread>

sectionStatic::sectionStatic() {
    sf::Text Txt;
    this->data = _HOSTNAME;
    this->dataMax = _TIME;
    this->infoTxt.push_back(Txt);
    this->infoTxt.push_back(Txt);
    this->infoTxt.push_back(Txt);
    this->infoTxt.push_back(Txt);
    this->infoTxt.push_back(Txt);
    this->infoTxt.push_back(Txt);
    this->_displaySection = true;
    this->get = Geters();
    this->get.s_kernel_version();
    this->get.s_sysname();
    this->get.s_user();
    this->get.s_computer_name();
    this->get.s_cpu_nbr_core();
    this->get.s_cpu_model_name();
    this->get.s_network_ssid();
    this->get.s_memory_total();
    this->get.s_hostname();
    this->_t_running = true;
}

sectionStatic::~sectionStatic()
{
    this->_t_running = false;
}

void sectionStatic::setText(sf::Vector2f vect, float charSize)
{
    size_t index = 0;
    std::string str;
    this->_font.loadFromFile("SFML/a_absolute_empire/aAbsoluteEmpire.ttf");

    while (index != this->infoTxt.size()) {
        if (index == _HOSTNAME) {
            this->infoTxt.at(index).setString(this->get.g_hostname());
            vect.y += 10;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _USERNAME) {
            this->infoTxt.at(index).setString(this->get.g_computer_name());
            vect.y += 20;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _SYSTEMNAME) {
            this->infoTxt.at(index).setString(this->get.g_sysname());
            vect.y += 30;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _KERNELVERS) {
            this->infoTxt.at(index).setString(this->get.g_kernel_version());
            vect.y += 40;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _DATE) {
            this->infoTxt.at(index).setString(this->get.g_current_date());
            vect.y += 50;
            this->infoTxt.at(index).setPosition(vect);
        }
        if (index == _TIME) {
            this->infoTxt.at(index).setString(this->get.g_current_time());
            vect.y += 60;
            this->infoTxt.at(index).setPosition(vect);
        }

        this->infoTxt.at(index).setFont(this->_font);
        this->infoTxt.at(index).setCharacterSize(charSize);
        sf::Color color(46,40,40);
        this->infoTxt.at(index).setFillColor(color);
        index++;
    }
}

void sectionStatic::setBackground(sf::Vector2f pos, sf::Vector2f size)
{
    sf::Color color(224,224,224);
    this->bck.setFillColor(color);
    this->bck.setPosition(pos);
    this->bck.setSize(size);
    this->bck.setOutlineThickness(10);
    sf::Color color1(85,13,13);
    this->bck.setOutlineColor(color1);
}

void sectionStatic::drawText(sf::RenderWindow &window)
{
    window.draw(this->bck);
    size_t index = 0;
    while (index != this->infoTxt.size()) {
        window.draw(this->infoTxt.at(index));
        index++;
    }
}