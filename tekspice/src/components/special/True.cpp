#include <sstream>
#include <exception>
#include "True.hpp"

using namespace nts;

TrueComponent::TrueComponent() {
    getPin(1).setState(Tristate::True);
}

nts::Tristate TrueComponent::compute(std::size_t pin) {
    (void)pin;
    getPin(1).setState(Tristate::True);
    return getPin(1).getState();
}
