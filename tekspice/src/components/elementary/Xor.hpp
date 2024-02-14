#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class XorComponent: public AComponent<3> {
        public:
            XorComponent();
            // ~XorComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
