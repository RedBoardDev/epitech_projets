/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** RetardUnitConverter.cpp
*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iomanip>

int main(void)
{
    std::string txt;
    std::stringstream ss;

    while (std::getline(std::cin, txt)) {
        float temperature;
        float rsp;
        std::string scale;
        std::stringstream ss(txt);
        ss >> temperature;
        ss >> scale;
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        if (scale == "Fahrenheit") {
            rsp = 5.0 / 9.0 * (temperature - 32);
            std::cout << std::right << std::setw(16) << rsp << std::setw(16) << "Celsius" << std::endl;
        } else if (scale == "Celsius") {
            rsp = (temperature) * 9.0 / 5.0 + 32;
            std::cout << std::right << std::setw(16) << rsp << std::setw(16) << "Fahrenheit" << std::endl;
        }
    }
    return 0;
}
