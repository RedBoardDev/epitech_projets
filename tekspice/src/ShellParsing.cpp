#include "Parsing.hpp"

bool loop = false;

void sigHandler(int sig) {
    if (sig == SIGINT) {
        if (loop)
            loop = false;
        else {
            exit(0);
        }
    }
}

static bool testEndLine(Shell &sh) {
    std::string buff;
    try {
        buff = sh.extract<std::string>();
    } catch(const std::exception& e) {
        return true;
    }
    std::cout << buff + ": Unknown expression" << std::endl;
    return false;
}

static void assignNewValue(Circuit &ci, const std::string &line) {
    std::string input = line.substr(0, line.find('='));
    std::string value = line.substr(line.find('=') + 1);
    try {
        ci.changeInputValue(input, value);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

static void loopCircuit(Circuit &ci) {
    loop = true;
    while (loop)
        ci.loop();
}

void nts::shell(Circuit &ci) {
    Shell sh(std::cin);
    std::string buff;

    signal(SIGINT, sigHandler);

    while (true) {
        try {
            sh.next();
            buff = sh.extract<std::string>();
        } catch(const Shell::Warning &e) {
            continue;
        } catch(const Shell::Error &e) {
            break;
        }
        if (!testEndLine(sh))
            continue;
        if (buff == "exit")
            break;
        else if (buff == "display")
            ci.display();
        else if (buff == "simulate")
            ci.simulate();
        else if (buff == "loop")
            loopCircuit(ci);
        else if (buff.find('=') != std::string::npos)
            assignNewValue(ci, buff);
        else
            std::cout << buff + ": Command not found" << std::endl;
    }
}
