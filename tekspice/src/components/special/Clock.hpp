#pragma once

#include <iostream>
#include "Input.hpp"
#include "../AComponent.hpp"

namespace nts {
    class ClockComponent: public InputComponent {
        public:
            ClockComponent();
            // ~ClockComponent();
            virtual void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
