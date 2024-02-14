#include "Factory.hpp"
#include "../Errors/Critical.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::Factory::createPrimitive(const std::string& type)
{
    std::unordered_map<std::string,
    std::function<std::shared_ptr<RayTracer::IPrimitive>()>>
    ::const_iterator it = this->primitiveMap.find(type);
    if (it == primitiveMap.end())
        throw Critical("Unknown primitive type: " + type);
    return it->second();
}

std::shared_ptr<RayTracer::ILights> RayTracer::Factory::createLight(const std::string& type)
{
    std::unordered_map<std::string,
    std::function<std::shared_ptr<RayTracer::ILights>()>>
    ::const_iterator it = this->lightMap.find(type);
    if (it == lightMap.end())
        throw Critical("Unknown light type: " + type);
    return it->second();
}
