#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <unordered_map>

#include "Brain.hpp"

class Core {
public:
    Core();
    ~Core() = default;

    void loop();

private:
    class EndException: public std::exception {
    public:
        const char *what() const noexcept override { return "End of game"; }
    };

    void route(const std::string &cmd);

    // MANDATORY COMMANDS
    void start(std::stringstream &ss);
    void turn(std::stringstream &ss);
    void begin(std::stringstream &ss);
    void board(std::stringstream &ss);
    void info(std::stringstream &ss);
    void end(std::stringstream &ss);
    void about(std::stringstream &ss);

    // OPTIONAL COMMANDS
    void rectstart(std::stringstream &ss);
    void restart(std::stringstream &ss);

    const std::unordered_map<std::string, void (Core::*)(std::stringstream &)> _functions;
    Brain _brain;
};
