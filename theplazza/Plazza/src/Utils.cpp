#include "Utils.hpp"


std::vector<std::string> Plazza::Utils::split(const std::string &str, const std::string &delim)
{
    std::string line = str;

    line += delim;
    std::vector<std::string> commands;
    size_t pos = 0;
    std::string strTmp;
    while ((pos = line.find(delim)) != std::string::npos) {
        strTmp = line.substr(0, pos);
        if (!strTmp.empty())
            commands.push_back(strTmp);
        line.erase(0, pos + 1);
    }
    return commands;
}