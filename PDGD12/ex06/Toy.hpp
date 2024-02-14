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

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                ErrorType type;
                const std::string what() const;
                const std::string where() const;
        };

        Toy();
        Toy(ToyType toyType, const std::string &name, const std::string &str);
        Toy(const Toy &toy);
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
        Toy &operator=(const Toy &rhs);
        virtual bool speak(const std::string &str);
        virtual bool speak_es(const std::string &str);
        void operator<<(const std::string &str);
        Error &getLastError();

        protected:
            Toy::Error _err;

        private:
            ToyType _type;
            std::string _name;
            Picture _picture;
};

std::ostream &operator<<(std::ostream &os, const Toy &d);
