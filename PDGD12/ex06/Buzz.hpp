/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** Buzz.hpp
*/

#include "Toy.hpp"

class Buzz: public Toy
{
    public:
        Buzz(const std::string &name);
        Buzz(const std::string &name, const std::string &fileName);
        ~Buzz();
        bool speak(const std::string &str);
        bool speak_es(const std::string &str);
};
