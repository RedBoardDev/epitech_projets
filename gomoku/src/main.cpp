#include <iostream>
#include "Args.hpp"
#include "Core.hpp"

int main(void) {
    Core core;
    try {
        core.loop();
    } catch (const std::exception &e) {
        std::cout << "DEBUG " << e.what() << std::endl;
    }
    return 0;
}
