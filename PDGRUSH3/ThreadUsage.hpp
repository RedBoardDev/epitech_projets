/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGRUSH3-robin.denni
** File description:
** thread_usage.hpp
*/

#pragma once

#include <array>
#include "UtilsGeters.hpp"
#include <iostream>

class ThreadUsage: virtual public UtilsGeters
{
    protected:
        std::array<long long, 10> _thread_columns;
        std::array<long long, 10> _thread_last_columns;
        std::string _thread_data;

    public:
        ThreadUsage();
        ~ThreadUsage() {};
        void s_thread_usage(int i);
        std::string g_thread_usage() { return _thread_data; };
};
