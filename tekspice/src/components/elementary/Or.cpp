#include <sstream>
#include <exception>
#include "Or.hpp"

using namespace nts;

OrComponent::OrComponent() {}

nts::Tristate OrComponent::compute(std::size_t pin) {
    (void)pin;
    Tristate pin1 = getLink(1);
    Tristate pin2 = getLink(2);

    if (pin1 == Tristate::True || pin2 == Tristate::True)
        getPin(3).setState(Tristate::True);
    else if (pin1 == Tristate::Undefined || pin2 == Tristate::Undefined)
        getPin(3).setState(Tristate::Undefined);
    else
        getPin(3).setState(Tristate::False);
    return getPin(3).getState();
}
