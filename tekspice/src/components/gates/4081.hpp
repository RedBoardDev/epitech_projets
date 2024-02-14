#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4081: public AComponent<14> {
        public:
            Component4081();
            // ~Component4081();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
