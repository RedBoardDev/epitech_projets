#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class InputComponent: public AComponent<1> {
        public:
            InputComponent();
            // ~InputComponent();
            virtual void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin);
            virtual void setValue(nts::Tristate value);

        protected:
            bool _changeValue;
            nts::Tristate _nextValue;
    };
}
