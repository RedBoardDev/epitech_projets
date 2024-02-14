#include "Tristate.hpp"

using namespace nts;

std::ostream &operator<<(std::ostream& s, Tristate v) {
    if (v == Tristate::True)
        s << "1";
    else if (v == Tristate::False)
        s << "0";
    else
        s << "U";
    return s;
}

std::ostream &operator<<(std::ostream& s, PinType v) {
    if (v == PinType::INPUT)
        s << "INPUT";
    else if (v == PinType::OUTPUT)
        s << "OUTPUT";
    else
        s << "INACTIVE";
    return s;
}
