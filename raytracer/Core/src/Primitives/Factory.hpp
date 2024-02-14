#pragma once

#include "../Lights/ILights.hpp"
#include "IPrimitive.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

namespace RayTracer {
class Factory {
public:
    Factory() {};
    ~Factory() {};
    std::shared_ptr<IPrimitive> createPrimitive(const std::string& type);
    std::shared_ptr<ILights> createLight(const std::string& type);
    std::unordered_map<std::string, std::function<std::shared_ptr<IPrimitive>()>> primitiveMap;
    std::unordered_map<std::string, std::function<std::shared_ptr<ILights>()>> lightMap;
};
}
