/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGRUSH3-robin.denni
** File description:
** thread_usage.cpp
*/

#include "ThreadUsage.hpp"

ThreadUsage::ThreadUsage()
{
    this->_thread_data = "0";
    this->_thread_columns = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    this->_thread_last_columns = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void ThreadUsage::s_thread_usage(int i)
{
    std::string line = this->readFile("/proc/stat", i + 1);
    sscanf(line.c_str(), "%*s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &this->_thread_columns[0], &this->_thread_columns[1], &this->_thread_columns[2], &this->_thread_columns[3], &this->_thread_columns[4], &this->_thread_columns[5], &this->_thread_columns[6], &this->_thread_columns[7], &this->_thread_columns[8], &this->_thread_columns[9]);

    std::array<long long, 10> delta{};
    for (int i = 0; i < 10; i++) {
        delta[i] = this->_thread_columns[i] - this->_thread_last_columns[i];
    }
    this->_thread_last_columns = this->_thread_columns;
    long long used_delta = delta[0] + delta[1] + delta[2] + delta[5] + delta[6] + delta[7];
    _thread_data = std::to_string(100.0 * used_delta / (used_delta + (delta[3] + delta[4])));
}

