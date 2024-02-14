/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGRUSH3-robin.denni
** File description:
** UtilsGeters.cpp
*/

#include "UtilsGeters.hpp"

std::string UtilsGeters::readFile(std::string const &file, int line)
{
    std::ifstream is(file);
    if( !is.good() ){
        throw std::runtime_error("Error: stream has errors.");
    }
    std::stringstream ss;
    ss << is.rdbuf();
	std::string m;
    for (int i = 0; i < line; i++)
        std::getline(ss, m);
    return m;
}

std::string UtilsGeters::getNetworkInterface()
{
    std::string line = this->readFile("/proc/net/arp", 2);

    std::stringstream ss(line);
    std::string word;
    std::string lastWord;
    while(ss >> word) lastWord = word;
    return lastWord;
}
