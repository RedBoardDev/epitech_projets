/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** Droid.hpp
*/

#pragma once

#include <iostream>

class Droid {
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;

    public:
        Droid(std::string id = "");
        Droid(const Droid &droid);
        ~Droid(void);
        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t &energy);
        std::string getId() const;

        void setId(std::string id);
        size_t getEnergy() const;
        void setEnergy(size_t energy);
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setStatus(std::string *status);

};

std::ostream &operator<<(std::ostream &os, const Droid &d);