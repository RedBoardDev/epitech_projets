#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class Component4030: public AComponent<14> {
        public:
            Component4030();
            // ~Component4030();
            nts::Tristate compute(std::size_t pin);

        private:
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> _gates;
    };
}
