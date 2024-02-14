/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** Woody.hpp
*/

#include "Toy.hpp"

class Woody: public Toy
{
    public:
        Woody(const std::string &name);
        Woody(const std::string &name, const std::string &fileName);
        ~Woody();
        bool speak(const std::string &str);
};
