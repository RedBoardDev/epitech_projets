#include "nts.hpp"
#include "Circuit.hpp"

int main(int ac, char **av) {
    Circuit ci;

    if (ac > 1) {
        std::string f(av[1]);
        try {
            nts::parseFile(f, ci);
            if (!ci.size())
                return 84;
            nts::shell(ci);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            return 84;
        }
        return 0;
    }
    return 84;
}
