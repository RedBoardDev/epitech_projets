#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4069: public AComponent<14> {
        public:
            Component4069();
            // ~Component4069();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
