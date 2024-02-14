#pragma once

#include <iostream>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    enum PinType {
        INACTIVE,
        OUTPUT,
        INPUT
    };
}

std::ostream &operator<<(std::ostream& s, nts::Tristate v);
std::ostream &operator<<(std::ostream& s, nts::PinType v);
