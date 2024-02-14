/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** Droid.hpp
*/

#pragma once

#include <iostream>
#include "DroidMemory.hpp"

class Droid {
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
        DroidMemory *_battleData;
    public:
        Droid(std::string serial);
        Droid(const Droid &droid);
        bool operator()(const std::string *task, size_t task_nb);
        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t energy);
        ~Droid(void);

        std::string getId() const;
        void setId(std::string id);
        size_t getEnergy() const;
        void setEnergy(size_t energy);
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        DroidMemory *getBattleData() const;
        void setBattleData(DroidMemory *feur);
        void setStatus(std::string *status);

};

std::ostream &operator<<(std::ostream &os, const Droid &d);