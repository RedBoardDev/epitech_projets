#include "Shell.hpp"

Shell::Shell(std:: istream &stream): _stream(stream) {}

Shell::~Shell() {}

void Shell::next() {
    if (!_stream.good())
        throw Error("Input failed");
    std::cout << "> ";
    if (!getline(_stream, _line))
        throw Error("End of input");
    _ss.str(_line);
    _ss.clear();
}

Shell::Error::Error(const std::string &msg): _msg(msg) {}

const char *Shell::Error::what() const noexcept {
    return _msg.c_str();
}

Shell::Warning::Warning(const std::string &msg): _msg(msg) {}

const char *Shell::Warning::what() const noexcept {
    return _msg.c_str();
}
