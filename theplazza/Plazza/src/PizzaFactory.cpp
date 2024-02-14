#include "PizzaFactory.hpp"
#include <unordered_map>
#include <functional>

std::unique_ptr<Plazza::IPizza> Plazza::PizzaFactory::createPizza(const Plazza::IPizza::PizzaType &name, const Plazza::IPizza::PizzaSize &size)
{
    static const std::unordered_map<Plazza::IPizza::PizzaType, std::function<std::unique_ptr<Plazza::IPizza>(const Plazza::IPizza::PizzaSize &)>> PizzaMap {
        {Plazza::IPizza::PizzaType::Americana, [](const Plazza::IPizza::PizzaSize &size)
            {return std::make_unique<Plazza::Pizza::Americana>(size);}},
        {Plazza::IPizza::PizzaType::Fantasia, [](const Plazza::IPizza::PizzaSize &size)
            {return std::make_unique<Plazza::Pizza::Fantasia>(size);}},
        {Plazza::IPizza::PizzaType::Regina, [](const Plazza::IPizza::PizzaSize &size)
            {return std::make_unique<Plazza::Pizza::Regina>(size);}},
        {Plazza::IPizza::PizzaType::Margarita, [](const Plazza::IPizza::PizzaSize &size)
            {return std::make_unique<Plazza::Pizza::Margarita>(size);}}
    };
    std::unordered_map<Plazza::IPizza::PizzaType, std::function<std::unique_ptr<Plazza::IPizza>(const Plazza::IPizza::PizzaSize &)>>::const_iterator it = PizzaMap.find(name);
    if (it == PizzaMap.end())
        throw std::out_of_range("Unknown Pizza: " + name);
    return it->second(size);
}
