#include <sstream>
#include <exception>
#include "Nor.hpp"

using namespace nts;

NorComponent::NorComponent() {}

nts::Tristate NorComponent::compute(std::size_t pin) {
    (void)pin;
    Tristate pin1 = getLink(1);
    Tristate pin2 = getLink(2);

    if (pin1 == Tristate::False && pin2 == Tristate::False)
        getPin(3).setState(Tristate::True);
    else if (pin1 == Tristate::True || pin2 == Tristate::True)
        getPin(3).setState(Tristate::False);
    else
        getPin(3).setState(Tristate::Undefined);
    return getPin(3).getState();
}
