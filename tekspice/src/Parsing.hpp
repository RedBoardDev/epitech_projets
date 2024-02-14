#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <csignal>
#include "Circuit.hpp"
#include "Shell.hpp"
#include "FileParser.hpp"

namespace nts {
    void parseFile(std::string fileName, Circuit &ci);
    void shell(Circuit &ci);
}
