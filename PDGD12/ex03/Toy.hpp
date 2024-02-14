/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD12-thomas.ott
** File description:
** Toy.hpp
*/

#pragma once

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(ToyType toyType, const std::string &name, const std::string &str);
        Toy(Toy const &toy);
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
        Toy &operator=(Toy const &rhs);
        virtual void speak(const std::string &str);
    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
};
