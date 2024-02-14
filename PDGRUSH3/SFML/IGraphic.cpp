/*
** EPITECH PROJECT, 2023
** Igrapghic.cpp
** File description:
** IGraphic.cpp
*/

#include "IGraphic.hpp"

IGraphic::IGraphic()
{
    this->infos = sectionStatic();
    this->_displaySection = false;
    this->infosSection.push_back(this->infos);
    this->infosSection.push_back(this->infos);
    this->infosSection.push_back(this->infos);
    this->infosSection.push_back(this->infos);
}

IGraphic::~IGraphic()
{
}

void IGraphic::setInfoSection(void)
{

    size_t index = 0;
    this->infoPC.setText(sf::Vector2f(100, 50), 16);
    this->infoPC.setBackground(sf::Vector2f(50, 50), sf::Vector2f(1800, 100));

    this->infoCPU.setText(sf::Vector2f(100, 200), 16);
    this->infoCPU.setBackground(sf::Vector2f(50, 200), sf::Vector2f(450, 800));

    this->infoNetwork.setText(sf::Vector2f(550, 200), 16);
    this->infoNetwork.setBackground(sf::Vector2f(500, 200), sf::Vector2f(450, 800));

    this->infoRAM.setText(sf::Vector2f(1000, 200), 16);
    this->infoRAM.setBackground(sf::Vector2f(950, 200), sf::Vector2f(450, 800));

    while (index != this->infosSection.size()) {
        if (index == 0) {
            this->infosSection.at(index).setText(sf::Vector2f(100, 200), 16);
            this->infosSection.at(index).setBackground(sf::Vector2f(50, 200), sf::Vector2f(450, 800));
        }
        if (index == 1) {
            this->infosSection.at(index).setText(sf::Vector2f(550, 200), 16);
            this->infosSection.at(index).setBackground(sf::Vector2f(500, 200), sf::Vector2f(450, 800));
        }
        if (index == 2) {
            this->infosSection.at(index).setText(sf::Vector2f(1000, 200), 16);
            this->infosSection.at(index).setBackground(sf::Vector2f(950, 200), sf::Vector2f(450, 800));
        }
        if (index == 3) {
            this->infosSection.at(index).setText(sf::Vector2f(1450, 200), 16);
            this->infosSection.at(index).setBackground(sf::Vector2f(1400, 200), sf::Vector2f(450, 800));
        }
        index++;
    }
}

void IGraphic::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window");
    window.setFramerateLimit(5);
    while (window.isOpen())
    {
        this->setInfoSection();
        while (window.pollEvent(this->_event))
        {
            switch (this->_event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (this->_event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::C:
                            switch(this->infoCPU._displaySection)
                            {
                                case true:
                                    this->infoCPU._displaySection = false;
                                    break;
                                case false:
                                    this->infoCPU._displaySection = true;
                                    break;
                            }
                            break;
                        case sf::Keyboard::D:
                            switch(this->infoNetwork._displaySection)
                            {
                                case true:
                                    this->infoNetwork._displaySection = false;
                                    break;
                                case false:
                                    this->infoNetwork._displaySection = true;
                                    break;
                            }
                            break;
                        case sf::Keyboard::R:
                            switch(this->infoRAM._displaySection)
                            {
                                case true:
                                    this->infoRAM._displaySection = false;
                                    break;
                                case false:
                                    this->infoRAM._displaySection = true;
                                    break;
                            }
                            break;
                        case sf::Keyboard::M:
                            switch(this->infosSection.at(3)._displaySection)
                            {
                                case true:
                                    this->infosSection.at(3)._displaySection = false;
                                    break;
                                case false:
                                    this->infosSection.at(3)._displaySection = true;
                                    break;
                            }
                            break;
                        case sf::Keyboard::P:
                            switch(this->infoPC._displaySection)
                            {
                                case true:
                                    this->infoPC._displaySection = false;
                                    break;
                                case false:
                                    this->infoPC._displaySection = true;
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear();

        if (this->infoPC._displaySection == true)
            this->infoPC.drawText(window);

        if (this->infoCPU._displaySection == true)
            this->infoCPU.drawText(window);

        if (this->infoNetwork._displaySection == true)
            this->infoNetwork.drawText(window);

        if (this->infoRAM._displaySection == true)
            this->infoRAM.drawText(window);
        window.display();
    }
}
