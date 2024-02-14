#include "Link.hpp"

using namespace nts;

Link::Link():
    _state(Tristate::Undefined),
    _processed(false),
    _comp(nullptr),
    _compPin(0),
    _internProcessed(false),
    _internComp(nullptr),
    _internCompPin(0) {}

void Link::setLink(IComponent &comp, size_t compPin) {
    _comp = &comp;
    _compPin = compPin;
}

void Link::setInternLink(IComponent &comp, size_t compPin) {
    _internComp = &comp;
    _internCompPin = compPin;
}

Tristate Link::getState() const
{
    return this->_state;
}

void Link::setState(Tristate state)
{
    this->_state = state;
    this->_processed = true;
}

size_t Link::getCompPin() const
{
    return this->_compPin;
}

size_t Link::getInternCompPin() const
{
    return this->_internCompPin;
}

bool Link::getProcessed() const
{
    return this->_processed;
}

Tristate Link::compute() {
    if (!_internProcessed && _internComp) {
        _internProcessed = true;
        setState(_internComp->compute(_internCompPin));
    } else if (!_processed && _comp) {
        _processed = true;
        setState(_comp->compute(_compPin));
    }
    return _state;
}

void Link::reset()
{
    if (this->_processed && this->_comp) {
        this->_processed = false;
        this->_comp->reset();
    }
    if (this->_internProcessed && this->_internComp) {
        this->_internProcessed = false;
        this->_internComp->reset();
    }
    this->_processed = false;
    this->_internProcessed = false;
}
