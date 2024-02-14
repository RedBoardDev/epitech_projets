#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4001: public AComponent<14> {
        public:
            Component4001();
            // ~Component4001();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
