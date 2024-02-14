#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <utility>
#include "Link.hpp"
#include "IComponent.hpp"

namespace nts {
    template<size_t nbrPins>
    class AComponent: public IComponent {
        public:
            AComponent();
            virtual void simulate(std::size_t tick);
            virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) final;
            virtual void setInternLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

            // Returns state of a pin
            virtual nts::Tristate getValue(std::size_t pin) final;
            // Sets state of a pin
            virtual void setValue(nts::Tristate value);
            virtual void reset() final;
        protected:
            // Computes a pin and returns its state
            virtual Tristate getLink(std::size_t pin) final;
            // Returns Link object of a pin
            virtual Link &getPin(size_t pin) final;
        private:
            std::unordered_map<std::size_t, nts::Link> _link;
    };

    template<size_t nbrPins>
    AComponent<nbrPins>::AComponent() {
        for (size_t i = 1; i <= nbrPins; ++i)
            _link[i] = nts::Link();
    }

    template<size_t nbrPins>
    void AComponent<nbrPins>::simulate(std::size_t tick) {
        (void)tick;
    }

    template<size_t nbrPins>
    void AComponent<nbrPins>::setLink(std::size_t pin, IComponent& other, std::size_t otherPin) {
        if (pin > nbrPins)
            throw std::out_of_range("Not enouth pins");

        if (_link[pin].getCompPin() == 0) {
            _link[pin].setLink(other, otherPin);
            other.setLink(otherPin, *this, pin);
        }
    }

    template<size_t nbrPins>
    void AComponent<nbrPins>::setInternLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin > nbrPins)
            throw std::out_of_range("Not enouth pins");

        // if (_link[pin].getInternCompPin() == 0) {
            _link[pin].setInternLink(other, otherPin);
            // other.setInternLink(otherPin, *this, pin);
        // }
    }

    template<size_t nbrPins>
    nts::Tristate AComponent<nbrPins>::getValue(std::size_t pin) {
        if (pin > nbrPins || !_link.contains(pin))
            throw std::out_of_range("Not enouth pins");
        return _link[pin].getState();
    }

    template<size_t nbrPins>
    void AComponent<nbrPins>::setValue(nts::Tristate value) {
        (void)value;
    }

    template<size_t nbrPins>
    void AComponent<nbrPins>::reset() {
        for (auto i = _link.begin(); i != _link.end(); ++i) {
            i->second.reset();
        }
    }

    template<size_t nbrPins>
    Tristate AComponent<nbrPins>::getLink(std::size_t pin) {
        if (pin > nbrPins || !_link.contains(pin))
            throw std::out_of_range("Not enouth pins");
        return _link[pin].compute();
    }

    template<size_t nbrPins>
    Link &AComponent<nbrPins>::getPin(size_t pin) {
        if (pin > nbrPins || !_link.contains(pin))
            throw std::out_of_range("Not enouth pins");
        return _link[pin];
    }
}
