#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class SumComponent: public AComponent<5> {
        public:
            SumComponent();
            // ~SumComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
