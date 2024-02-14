#include "nts.hpp"
#include <unordered_map>
#include <functional>

std::unique_ptr<nts::IComponent> nts::createComponent(const std::string& type) {
    static const std::unordered_map<std::string, std::function<std::unique_ptr<IComponent>()>> componentMap {
        // Elementary components
        {"and", []() {return std::make_unique<AndComponent>();}},
        {"or", []() {return std::make_unique<OrComponent>();}},
        {"xor", []() {return std::make_unique<XorComponent>();}},
        {"not", []() {return std::make_unique<NotComponent>();}},
        {"sum", []() {return std::make_unique<SumComponent>();}},
        {"nand", []() {return std::make_unique<NandComponent>();}},
        {"nor", []() {return std::make_unique<NorComponent>();}},

        // Special Components
        {"input", []() {return std::make_unique<InputComponent>();}},
        {"clock", []() {return std::make_unique<ClockComponent>();}},
        {"true", []() {return std::make_unique<TrueComponent>();}},
        {"false", []() {return std::make_unique<FalseComponent>();}},
        {"output", []() {return std::make_unique<OutputComponent>();}},
        {"logger", []() {return std::make_unique<LoggerComponent>();}},

        // Gates components
        {"4001", []() {return std::make_unique<Component4001>();}},
        {"4011", []() {return std::make_unique<Component4011>();}},
        {"4030", []() {return std::make_unique<Component4030>();}},
        {"4069", []() {return std::make_unique<Component4069>();}},
        {"4071", []() {return std::make_unique<Component4071>();}},
        {"4081", []() {return std::make_unique<Component4081>();}},

        // Advanced components
        {"4008", []() {return std::make_unique<Component4008>();}}
    };

    std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>>::const_iterator it = componentMap.find(type);
    if (it == componentMap.end())
        throw std::out_of_range("Unknown component type: " + type);
    return it->second();
}
