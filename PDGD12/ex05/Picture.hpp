/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD12-thomas.ott
** File description:
** Picture.hpp
*/

#pragma once

#include <iostream>

class Picture
{
    public:
        std::string _data;
        Picture();
        Picture(const std::string &file);
        Picture(const Picture &picture);
        ~Picture();
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(const Picture &rhs);
};
