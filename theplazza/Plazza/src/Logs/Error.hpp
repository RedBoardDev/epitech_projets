#pragma once
#include <exception>
#include <string>
#include "Log.hpp"

class Error : public std::exception, Log {
    public:
        Error(const std::string &w_msg);
        ~Error();
        virtual const char* what() const noexcept override;


    protected:
        std::string msg;
        Log log_file;
};
