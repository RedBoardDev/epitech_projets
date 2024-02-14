/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD07am-thomas.ott
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

using namespace WarpSystem;

QuantumReactor::QuantumReactor(void) {
    _stability = true;
}

bool QuantumReactor::isStable(void) {
    return (_stability);
}

void QuantumReactor::setStability(bool stability) {
    _stability = stability;
}

Core::Core(QuantumReactor *coreReactor) {
    _coreReactor = coreReactor;
}

QuantumReactor *Core::checkReactor(void) {
    return (_coreReactor);
}
