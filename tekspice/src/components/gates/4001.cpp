#include <sstream>
#include <exception>
#include "../../nts.hpp"

using namespace nts;

Component4001::Component4001() {
    _gates.insert({1, createComponent("nor")});
    _gates.insert({2, createComponent("nor")});
    _gates.insert({3, createComponent("nor")});
    _gates.insert({4, createComponent("nor")});

    _gates[1]->setInternLink(1, *this, 1);
    _gates[1]->setInternLink(2, *this, 2);
    this->setInternLink(3, *(_gates[1]), 3);

    _gates[2]->setInternLink(1, *this, 5);
    _gates[2]->setInternLink(2, *this, 6);
    this->setInternLink(4, *(_gates[2]), 3);

    _gates[3]->setInternLink(1, *this, 8);
    _gates[3]->setInternLink(2, *this, 9);
    this->setInternLink(10, *(_gates[3]), 3);

    _gates[4]->setInternLink(1, *this, 12);
    _gates[4]->setInternLink(2, *this, 13);
    this->setInternLink(11, *(_gates[4]), 3);
}

nts::Tristate Component4001::compute(std::size_t pin) {
    return getLink(pin);
}
