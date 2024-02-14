#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class OutputComponent: public AComponent<1> {
        public:
            OutputComponent();
            // ~OutputComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
