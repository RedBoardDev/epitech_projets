/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07pm-thomas.ott
** File description:
** KoalaBot.hpp
*/

#pragma once

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial;
    public:
        KoalaBot(std::string serial = "Bob-01");
        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations(void) const;
        bool status(void) const;
        ~KoalaBot(void);
};
