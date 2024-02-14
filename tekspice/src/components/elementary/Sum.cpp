#include <sstream>
#include <exception>
#include "Sum.hpp"

using namespace nts;

SumComponent::SumComponent() {}

nts::Tristate SumComponent::compute(std::size_t pin) {
    Tristate pin1 = getLink(1); // a
    Tristate pin2 = getLink(2); // b
    Tristate pin3 = getLink(3); // c in
    // Tristate pin4 = getLink(5); // C out
    // Tristate pin5 = getLink(4); // S

    if (pin1 == Tristate::False && pin2 == Tristate::False) {
        getPin(4).setState(pin3 == Tristate::True ? Tristate::True : Tristate::False);
        getPin(5).setState(Tristate::False);
    } else if (pin1 == Tristate::False && pin2 == Tristate::True) {
        getPin(4).setState(pin3 == Tristate::False ? Tristate::True : Tristate::False);
        getPin(5).setState(pin3 == Tristate::True ? Tristate::True : Tristate::False);
    } else if (pin1 == Tristate::True && pin2 == Tristate::False) {
        getPin(4).setState(pin3 == Tristate::False ? Tristate::True : Tristate::False);
        getPin(5).setState(pin3 == Tristate::True ? Tristate::True : Tristate::False);
    } else if (pin1 == Tristate::True && pin2 == Tristate::True) {
        getPin(4).setState(pin3 == Tristate::True ? Tristate::True : Tristate::False);
        getPin(5).setState(Tristate::True);
    }
    return getPin(pin).getState();
}
