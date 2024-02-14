#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class AndComponent: public AComponent<3> {
        public:
            AndComponent();
            // ~AndComponent();
            nts::Tristate compute(std::size_t pin);

        private:
    };
}
