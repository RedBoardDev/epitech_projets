#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class TrueComponent: public AComponent<1> {
        public:
            TrueComponent();
            // ~TrueComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
