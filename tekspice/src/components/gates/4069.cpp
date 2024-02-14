#include <sstream>
#include <exception>
#include "../../nts.hpp"

using namespace nts;

Component4069::Component4069() {
    _gates.insert({1, createComponent("not")});
    _gates.insert({2, createComponent("not")});
    _gates.insert({3, createComponent("not")});
    _gates.insert({4, createComponent("not")});
    _gates.insert({5, createComponent("not")});
    _gates.insert({6, createComponent("not")});

    _gates[1]->setInternLink(1, *this, 1);
    this->setInternLink(2, *(_gates[1]), 2);

    _gates[2]->setInternLink(1, *this, 3);
    this->setInternLink(4, *(_gates[2]), 2);

    _gates[3]->setInternLink(1, *this, 5);
    this->setInternLink(6, *(_gates[3]), 2);

    _gates[4]->setInternLink(1, *this, 9);
    this->setInternLink(8, *(_gates[4]), 2);

    _gates[5]->setInternLink(1, *this, 11);
    this->setInternLink(10, *(_gates[5]), 2);

    _gates[6]->setInternLink(1, *this, 13);
    this->setInternLink(12, *(_gates[6]), 2);
}

nts::Tristate Component4069::compute(std::size_t pin) {
    return getLink(pin);
}
