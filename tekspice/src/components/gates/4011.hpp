#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4011: public AComponent<14> {
        public:
            Component4011();
            // ~Component4011();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
