/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** Federation.hpp
*/

#pragma once

#include "WarpSystem.hpp"

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Ensign {
        private:
            std::string _name;
        public:
            Ensign(std::string name);
        };

         class Captain {
        private:
            std::string _name;
            int _age;
        public:
            Captain(std::string name);
            std::string getName(void);
            int getAge(void);
            void setAge(int age);
        };

        class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        public:
            Ship(void);
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            void promote(Captain *captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield(void);
            void setShield(int shield);
            int getTorpedo(void);
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        };
    }
    class Ship {
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination _location;
        Destination _home;
        WarpSystem::Core *_core;
    public:
        Ship(int length, int width, std::string name);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        WarpSystem::Core *getCore(void);
    };
}
