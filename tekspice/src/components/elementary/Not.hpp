#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class NotComponent: public AComponent<2> {
        public:
            NotComponent();
            // ~NotComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
