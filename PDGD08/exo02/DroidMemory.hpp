/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD08-thomas.ott
** File description:
** DroidMemory.hpp
*/

#pragma once

#include <iostream>

class DroidMemory {
    private:
        size_t _fingerprint;
        size_t _exp;
    public:
        DroidMemory(void);
        DroidMemory(DroidMemory &mem1);
        size_t getFingerprint() const;
        void setFingerprint(size_t fingerprint);
        size_t getExp() const;
        void setExp(size_t exp);
        DroidMemory &operator<<(DroidMemory &droidmemory);
        DroidMemory &operator>>(DroidMemory &droidmemory);
        DroidMemory &operator+=(DroidMemory &droidmemory);
        DroidMemory &operator+=(size_t d);
        DroidMemory &operator+(DroidMemory &tmp);
        DroidMemory &operator=(DroidMemory &droidmemory);
        bool operator!=(DroidMemory &droidmemory) const;
        bool operator==(DroidMemory &droidmemory) const;
        bool operator<(DroidMemory &droidmemory) const;
        bool operator>(DroidMemory &droidmemory) const;
        bool operator<=(DroidMemory &droidmemory) const;
        bool operator>=(DroidMemory &droidmemory) const;
        bool operator<(size_t exp) const;
        bool operator>(size_t exp) const;
        bool operator<=(size_t exp) const;
        bool operator>=(size_t exp) const;
        ~DroidMemory(void);
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &d);