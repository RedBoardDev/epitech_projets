#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4008: public AComponent<16> {
        public:
            Component4008();
            // ~Component4008();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
