#pragma once

#include <iostream>
#include "../AComponent.hpp"

namespace nts {
    class LoggerComponent: public AComponent<10> {
        public:
            LoggerComponent();
            // ~LoggerComponent();
            nts::Tristate compute(std::size_t pin);

        protected:
            std::string _filePath;
            bool _printed;
    };
}
