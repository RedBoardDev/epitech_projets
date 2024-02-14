/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** Borg.hpp
*/

#pragma once

#include "WarpSystem.hpp"

namespace Federation {
    namespace Starfleet {
        class Enseign;
        class Captain;
        class Ship;
    }
    class Ship;
}

namespace Borg {
    class Ship {
    private:
        int _side;
        short _maxWarp;
        int _shield;
        int _weaponFrequency;
        short _repair;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    public:
        Ship(int weaponFrequency);
        Ship(int weaponFrequency, short repair);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield(void);
        void setShield(int shield);
        int getWeaponFrequency(void);
        void setWeaponFrequency(int frequency);
        short getRepair(void);
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair(void);
    };
}
