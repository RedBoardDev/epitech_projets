#include <sstream>
#include <exception>
#include "Not.hpp"

using namespace nts;

NotComponent::NotComponent() {}

nts::Tristate NotComponent::compute(std::size_t pin) {
    (void)pin;
    Tristate buff = getLink(1);
    getPin(2).setState(buff == Tristate::True ? Tristate::False : (buff == Tristate::False ? Tristate::True : Tristate::Undefined));
    return getPin(2).getState();
}
