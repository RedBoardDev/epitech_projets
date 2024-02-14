/*
** EPITECH PROJECT, 2023
** sectionStatic.hpp
** File description:
** sectionStatic.hpp
*/

#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/GpuPreference.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <thread>
#include <vector>
#include "../Geters.hpp"

class sectionStatic {
    public:
        enum Data {
            _HOSTNAME,
            _USERNAME,
            _SYSTEMNAME,
            _KERNELVERS,
            _DATE,
            _TIME,
        };
        sectionStatic();
        ~sectionStatic();

        Data dataMax;
        Data data;
        sf::RectangleShape bck;
        void setText(sf::Vector2f vect, float charSize);
        void setBackground(sf::Vector2f pos, sf::Vector2f size);
        void drawText(sf::RenderWindow &window);
        void drawSectionBackground();
        Geters get;
        bool _displaySection;
        std::vector<sf::Text> infoTxt;
        sf::Font _font;
        bool _t_running;
        std::thread *_t_infos;
};

void t_memory_available(sectionStatic &section);
void t_bandwith(sectionStatic &section);