#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class OrComponent: public AComponent<3> {
        public:
            OrComponent();
            // ~OrComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
