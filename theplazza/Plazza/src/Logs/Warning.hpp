#pragma once
#include <exception>
#include <string>
#include "Log.hpp"

class Warning : public std::exception {
    public:
        Warning(const std::string &w_msg);
        ~Warning();
        virtual const char* what() const noexcept override;

    protected:
        std::string msg;
        Log log_file;
};
