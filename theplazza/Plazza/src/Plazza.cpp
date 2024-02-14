#include <iostream>
#include <string>
#include <regex>
#include "./Core/Socket.hpp"
#include "./Status.hpp"
#include "./Core/Reception.hpp"
#include "./Kitchen/Client.hpp"
#include "./Logs/Error.hpp"

bool isNumberSuperiorAt0(const std::string &str) {
    std::regex pattern("^[1-9][0-9]*$");
    return std::regex_match(str, pattern);
}

bool check_args(int argc,char **argv)
{
    if (argc != 4) {
        throw Error("Not enough parameters");
        return false;
    }
    if (!isNumberSuperiorAt0(argv[1])) {
        throw Error("Not a number superior at 0");
        return false;
    }
    if (!isNumberSuperiorAt0(argv[2])) {
        throw Error("Not a number superior at 0");
        return false;
    }
    if (!isNumberSuperiorAt0(argv[3])) {
        throw Error("Not a number superior at 0");
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    try {
        if (!check_args(argc, argv))
            return 84;
        Plazza::Reception::Reception rec(argv[1], argv[2], argv[3]);
        rec.serverRun();
        rec.stdinReaderRun();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
