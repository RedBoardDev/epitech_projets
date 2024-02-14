#include <sstream>
#include <exception>
#include "Output.hpp"

using namespace nts;

OutputComponent::OutputComponent() {}

nts::Tristate OutputComponent::compute(std::size_t pin) {
    (void)pin;
    if (!this->getPin(1).getProcessed())
        return getLink(pin);
    return getValue(pin);
}
