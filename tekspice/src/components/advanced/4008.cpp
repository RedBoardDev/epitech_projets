#include <sstream>
#include <exception>
#include "../../nts.hpp"

using namespace nts;

Component4008::Component4008() {
    _gates.insert({1, createComponent("sum")});
    _gates.insert({2, createComponent("sum")});
    _gates.insert({3, createComponent("sum")});
    _gates.insert({4, createComponent("sum")});

    _gates[1]->setInternLink(1, *this, 6);
    _gates[1]->setInternLink(2, *this, 7);
    _gates[1]->setInternLink(3, *this, 9);
    this->setInternLink(10, *(_gates[1]), 4);
    _gates[1]->setLink(5, *(_gates[2]), 3);

    _gates[2]->setInternLink(1, *this, 4);
    _gates[2]->setInternLink(2, *this, 5);
    // _gates[2]->setInternLink(3, *this, 9);
    this->setInternLink(11, *(_gates[2]), 4);
    _gates[2]->setLink(5, *(_gates[3]), 3);

    _gates[3]->setInternLink(1, *this, 2);
    _gates[3]->setInternLink(2, *this, 3);
    // _gates[3]->setInternLink(3, *this, 9);
    this->setInternLink(12, *(_gates[3]), 4);
    _gates[3]->setLink(5, *(_gates[4]), 3);

    _gates[4]->setInternLink(1, *this, 15);
    _gates[4]->setInternLink(2, *this, 1);
    // _gates[4]->setInternLink(3, *this, 9);
    this->setInternLink(13, *(_gates[4]), 4);
    // _gates[4]->setLink(5, *(_gates[4]), 3);
    this->setInternLink(14, *(_gates[4]), 5);
}

nts::Tristate Component4008::compute(std::size_t pin) {
    return getLink(pin);
}
