#pragma once

#include <memory>
#include "IComponent.hpp"

namespace nts {
    class Link {
        private:
            Tristate _state;

            bool _processed;
            IComponent *_comp;
            size_t _compPin;

            bool _internProcessed;
            IComponent *_internComp;
            size_t _internCompPin;
        public:
            Link();
            void setLink(IComponent &comp, size_t compPin);
            void setInternLink(IComponent &comp, size_t compPin);
            Tristate getState() const;
            void setState(Tristate state);
            size_t getCompPin() const;
            size_t getInternCompPin() const;
            bool getProcessed() const;
            Tristate compute();
            void reset();
            // ~Link();
    };
}
