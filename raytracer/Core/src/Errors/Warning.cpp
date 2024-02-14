/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** CustomException
*/

#include "Warning.hpp"

Warning::Warning(const std::string &w_msg) : log_file("err-code.txt")
{
    this->log_file.write_error(Log::WARNING, w_msg);
    this->msg = "[WARNING] " + w_msg;
}

const char* Warning::what() const noexcept
{
    return this->msg.c_str();
}


Warning::~Warning()
{
}
