/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** WarpSystem.hpp
*/

#pragma once
#include <iostream>
#include "Destination.hpp"

namespace WarpSystem {
    class QuantumReactor {
    private:
        bool _stability;
    public:
        QuantumReactor();
        bool isStable(void);
        void setStability(bool stability);
    };

    class Core {
    private:
        QuantumReactor *_coreReactor;
    public:
        Core();
        Core(WarpSystem::QuantumReactor *coreReactor);
        QuantumReactor *checkReactor(void);
    };
}
