/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Log
*/

#include "Log.hpp"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <filesystem>

std::string Log::format_timestamp(const std::chrono::system_clock::time_point& tp, std::string format) {
    auto now_time_t = std::chrono::system_clock::to_time_t(tp);
    auto now_tm = *std::localtime(&now_time_t);
    std::stringstream ss;

    ss << std::put_time(&now_tm, format.c_str());
    return ss.str();
}

Log::Log(std::string file_path)
{
    std::filesystem::create_directory("logs");
    this->file.open(file_path, std::ios_base::app | std::ios_base::out);
    this->error_text = {"INFO", "WARNING", "ERROR", "CRITICAL"};
}

void Log::write_error(Log::ERROR_TYPE err_type, std::string text)
{
    if (!this->file.is_open())
        return;
    auto now = std::chrono::system_clock::now();

    this->file << format_timestamp(now, "%H:%M:%S") << " [" << this->error_text[err_type] << "] " << text << std::endl;
}

Log::~Log()
{
    if (!this->file.is_open())
        return;
    this->file.close();
}
