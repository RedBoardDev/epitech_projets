#include <sstream>
#include <exception>
#include "False.hpp"

using namespace nts;

FalseComponent::FalseComponent() {
    getPin(1).setState(Tristate::False);
}

nts::Tristate FalseComponent::compute(std::size_t pin) {
    (void)pin;
    getPin(1).setState(Tristate::False);
    return getPin(1).getState();
}
