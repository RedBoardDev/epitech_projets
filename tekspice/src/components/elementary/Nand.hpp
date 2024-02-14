#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class NandComponent: public AComponent<3> {
        public:
            NandComponent();
            // ~NandComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
