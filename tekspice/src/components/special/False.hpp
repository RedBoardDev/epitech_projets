#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class FalseComponent: public AComponent<1> {
        public:
            FalseComponent();
            // ~FalseComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
