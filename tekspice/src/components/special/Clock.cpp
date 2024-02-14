#include <sstream>
#include <exception>
#include "Clock.hpp"

using namespace nts;

ClockComponent::ClockComponent() {}

void ClockComponent::simulate(std::size_t tick) {
    bool backup = _changeValue;
    InputComponent::simulate(tick);
    Tristate buff = getPin(1).getState();
    if (!backup)
        getPin(1).setState(buff == Tristate::True ? Tristate::False : (buff == Tristate::False ? Tristate::True : Tristate::Undefined));
}

nts::Tristate ClockComponent::compute(std::size_t pin) {
    (void)pin;
    return getPin(1).getState();
}
