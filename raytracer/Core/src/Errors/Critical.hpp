/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** CustomException
*/

#pragma once
#include <exception>
#include <string>
#include "Log.hpp"

class Critical : public std::exception, Log {
    public:
        Critical(const std::string &w_msg);
        ~Critical();
        virtual const char* what() const noexcept override;

    protected:
        std::string msg;
        Log log_file;
};
