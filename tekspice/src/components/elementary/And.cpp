#include <sstream>
#include <exception>
#include "And.hpp"

using namespace nts;

AndComponent::AndComponent() {}

nts::Tristate AndComponent::compute(std::size_t pin) {
    (void)pin;
    Tristate pin1 = getLink(1);
    Tristate pin2 = getLink(2);

    if (pin1 == Tristate::False || pin2 == Tristate::False)
        getPin(3).setState(Tristate::False);
    else if (pin1 == Tristate::Undefined || pin2 == Tristate::Undefined)
        getPin(3).setState(Tristate::Undefined);
    else
        getPin(3).setState(Tristate::True);

    return getPin(3).getState();
}
