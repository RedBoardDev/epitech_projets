#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

class Log {
public:
    enum ERROR_TYPE {
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };
    Log() {};
    Log(std::string file_path);
    void write_error(ERROR_TYPE err_type, std::string text);
    std::string format_timestamp(const std::chrono::system_clock::time_point& tp, std::string format);
    ~Log();

protected:
    std::ofstream file;
    std::vector<std::string> error_text;

private:
};
