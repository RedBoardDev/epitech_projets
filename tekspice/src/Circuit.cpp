#include "Circuit.hpp"
#include "nts.hpp"

Circuit::NotFoundException::NotFoundException(std::string w): _w(w) {}

const char *Circuit::NotFoundException::what() const noexcept {
    return _w.c_str();
}

Circuit::Circuit(): _tick(0) {}

void Circuit::addComponent(std::string name, std::string type)
{
    if (type == "input" || type == "clock")
        this->_input.insert({name, nts::createComponent(type)});
    else if (type == "output" || type == "logger")
        this->_output.insert({name, nts::createComponent(type)});
    else
        this->_other.insert({name, nts::createComponent(type)});
}

nts::IComponent &Circuit::getComponent(const std::string name)
{
    if (_input.contains(name))
        return (*_input.find(name)->second);
    if (_output.contains(name))
        return (*_output.find(name)->second);
    if (_other.contains(name))
        return (*_other.find(name)->second);
    throw NotFoundException(name + " doesn't exists.");
}

void Circuit::setLink(std::string name, std::size_t pin, std::string otherName, std::size_t otherPin)
{
    this->getComponent(name).setLink(pin, this->getComponent(otherName), otherPin);
}

void Circuit::display(void)
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (std::map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = this->_input.begin(); it != this->_input.end(); ++it) {
        std::cout << "  " << it->first << ": " << it->second->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (std::map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = this->_output.begin(); it != this->_output.end(); ++it) {
        std::cout << "  " << it->first << ": " << it->second->compute(1) << std::endl;
    }
}

void Circuit::changeInputValue(std::string name, std::string value)
{
    if (value == "0") {
        this->getComponent(name).setValue(nts::Tristate::False);
        return;
    }
    if (value == "1") {
        this->getComponent(name).setValue(nts::Tristate::True);
        return;
    }
    this->getComponent(name).setValue(nts::Tristate::Undefined);
}

void Circuit::simulate(void)
{
    for (std::map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = this->_input.begin(); it != this->_input.end(); ++it)
        it->second->simulate(_tick);
    for (std::map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = this->_output.begin(); it != this->_output.end(); ++it) {
        it->second->reset();
        it->second->compute(1);
    }
    ++this->_tick;
}

void Circuit::loop() {
    this->simulate();
    this->display();
}

std::size_t Circuit::size(void) {
    return _input.size() + _output.size() + _other.size();
}
