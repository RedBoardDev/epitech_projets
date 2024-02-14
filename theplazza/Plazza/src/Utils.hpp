#pragma once
#include <memory>
#include <vector>
#include <iostream>

namespace Plazza {
    class Utils {
        public:
            static std::vector<std::string> split(const std::string &str, const std::string &delim);
    };
}