/*
** EPITECH PROJECT, 2022
** ex06
** File description:
** ToyStory.hpp
*/

#include "Toy.hpp"

class ToyStory: public Toy
{
    public:
        static void tellMeAStory(const std::string &story, Toy &toy1, bool (Toy::*func1)(const std::string &str), Toy &toy2, bool (Toy::*func2)(const std::string &str));
};