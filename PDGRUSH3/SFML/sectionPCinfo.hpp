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
#include <vector>
#include "../Geters.hpp"
#include "sectionStatic.hpp"

class sectionPCinfo: public sectionStatic {
    public:
        sectionPCinfo(){}
        ~sectionPCinfo(){}
        void setText(sf::Vector2f vect, float charSize);
};