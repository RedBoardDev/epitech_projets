#pragma once
#include <exception>
#include <string>
#include "Log.hpp"

class Info : public std::exception, Log {
    public:
        Info(const std::string &w_msg);
        ~Info();
        virtual const char* what() const noexcept override;
    protected:
        std::string msg;
        Log log_file;
};
