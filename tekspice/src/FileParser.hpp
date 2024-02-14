#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class FileParser {
    public:
        FileParser(const std::string &fileName);
        ~FileParser();
        void next();

        template<typename T>
        T extract();
        std::string extractStr();

        const std::string &fileName() const;
        const std::size_t &currentLine() const;

        class Error: public std::exception {
            public:
                Error(std::size_t line, const std::string &filename, const std::string &msg);
                const char *what() const noexcept override;

            private:
                std::string _msg;
        };

        class Warning: public std::exception {
            public:
                Warning(std::size_t line, const std::string &filename, const std::string &msg);
                const char *what() const noexcept override;

            private:
                std::string _msg;
        };

    protected:
    private:
        std::ifstream _stream;
        std::string _line;
        std::stringstream _ss;
        std::string _fileName;
        size_t _fileLine = 0;
        bool _comment = false;
};

template<typename T>
T FileParser::extract() {
    if (_comment)
        throw Warning(_fileLine, _fileName, "End of line");

    T res;
    if (!(_ss >> res))
        throw Warning(_fileLine, _fileName, "Invalid conversion");
    return res;
}
