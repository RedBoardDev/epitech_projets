#include <sstream>
#include <exception>
#include "Input.hpp"

using namespace nts;

InputComponent::InputComponent(): _changeValue(false), _nextValue(Tristate::Undefined) {}

void InputComponent::simulate(std::size_t tick) {
    (void)tick;
    if (_changeValue) {
        getPin(1).setState(_nextValue);
        _changeValue = false;
        _nextValue = Tristate::Undefined;
    }
}

nts::Tristate InputComponent::compute(std::size_t pin) {
    (void)pin;
    return getPin(1).getState();
}

void InputComponent::setValue(nts::Tristate value) {
    _changeValue = true;
    _nextValue = value;
}
