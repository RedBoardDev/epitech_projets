#include <sstream>
#include <exception>
#include "Logger.hpp"
#include <fstream>
#include <math.h>

using namespace nts;

LoggerComponent::LoggerComponent() {
    this->_filePath = "./log.bin";
    this->_printed = false;
}

nts::Tristate LoggerComponent::compute(std::size_t pin) {
    (void)pin;
    char byte = 0;

    for (size_t i = 8; i >= 1; --i) {
        if (this->getLink(i) == nts::Tristate::Undefined)
            return this->getLink(i);
        byte = (byte << 1) | (this->getLink(i) == nts::Tristate::True ? 1 : 0);
    }
    if (this->getLink(10) != nts::Tristate::False) {
        this->_printed = true;
        return this->getLink(10);
    }
    if (this->getLink(9) == nts::Tristate::True) {
        if (this->_printed == false) {
            std::ofstream logFile(this->_filePath, std::ios::out | std::ios::binary | std::ios::app); // write mode only / binary mode / data write at the end of the file
            logFile.write(&byte, 1);
            this->_printed = true;
        }
    } else if (this->getLink(9) == nts::Tristate::False) {
        this->_printed = false;
    }
    return this->getPin(1).getState();
}
