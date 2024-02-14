#pragma once

#include <iostream>
#include <sstream>

class Shell {
    public:
        Shell(std::istream &stream);
        ~Shell();
        void next();

        template<typename T>
        T extract();

        class Error : public std::exception {
            public:
                Error(const std::string &msg);
                const char *what() const noexcept override;

            private:
                std::string _msg;
        };

        class Warning : public std::exception {
            public:
                Warning(const std::string &msg);
                const char *what() const noexcept override;

            private:
                std::string _msg;
        };

    protected:
    private:
        std::istream &_stream;
        std::string _line;
        std::stringstream _ss;
};

template<typename T>
T Shell::extract() {
    T res;
    if (!(_ss >> res))
        throw Warning("Invalid conversion");
    return res;
}
