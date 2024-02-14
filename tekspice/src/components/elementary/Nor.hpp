#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class NorComponent: public AComponent<3> {
        public:
            NorComponent();
            // ~NorComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
