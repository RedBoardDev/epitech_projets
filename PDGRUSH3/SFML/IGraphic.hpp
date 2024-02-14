/*
** EPITECH PROJECT, 2023
** IGraphic.hpp
** File description:
** IGraphic.hpp
*/

#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/GpuPreference.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <vector>
#include "sectionStatic.hpp"
#include "sectionPCinfo.hpp"
#include "sectionCPU.hpp"
#include "sectionNetwork.hpp"
#include "sectionRAM.hpp"

class IGraphic {
    public:
        IGraphic();
        ~IGraphic();
        virtual void createWindow();

        sectionPCinfo infoPC;
        sectionCPU infoCPU;
        sectionNetwork infoNetwork;
        sectionRAM infoRAM;
        
        std::vector<sectionStatic> infosSection;
        sectionStatic infos;
        bool _displaySection;
        void setInfoSection(void);

    protected:
        sf::Event _event;

    private:
};
