#include <sstream>
#include <exception>
#include "Xor.hpp"

using namespace nts;

XorComponent::XorComponent() {}

nts::Tristate XorComponent::compute(std::size_t pin) {
    (void)pin;
    Tristate pin1 = getLink(1);
    Tristate pin2 = getLink(2);

    if (pin1 == Tristate::Undefined || pin2 == Tristate::Undefined)
        getPin(3).setState(Tristate::Undefined);
    else if ((pin1 == Tristate::False && pin2 == Tristate::True) || (pin1 == Tristate::True && pin2 == Tristate::False))
        getPin(3).setState(Tristate::True);
    else
        getPin(3).setState(Tristate::False);
    return getPin(3).getState();
}
