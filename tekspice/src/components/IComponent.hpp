#pragma once

#include <iostream>
#include "../Tristate.hpp"

namespace nts {
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
            virtual void setInternLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

            virtual nts::Tristate getValue(std::size_t pin) = 0;
            virtual void setValue(nts::Tristate value) = 0;
            virtual void reset() = 0;
    };
}
