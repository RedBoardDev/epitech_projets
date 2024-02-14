#pragma once

#include <iostream>
#include <memory>
#include "components/IComponent.hpp"

namespace nts {
    std::unique_ptr<IComponent> createComponent(const std::string& type);
}
