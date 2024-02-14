#include "ConvertEnum.hpp"

std::string Plazza::ConvertEnum::ingredientsToString(Plazza::IPizza::Ingredients ingredient)
{
    switch (ingredient)
    {
        case Plazza::IPizza::Ingredients::INGR_BICHE:
            return "Biche";
        case Plazza::IPizza::Ingredients::INGR_TOMATO:
            return "Tomato";
        case Plazza::IPizza::Ingredients::INGR_GRUYERE:
            return "Gruyere";
        case Plazza::IPizza::Ingredients::INGR_HAM:
            return "Ham";
        case Plazza::IPizza::Ingredients::INGR_EGGPLANTS:
            return "Eggplants";
        case Plazza::IPizza::Ingredients::INGR_MUSHROOMS:
            return "Mushrooms";
        case Plazza::IPizza::Ingredients::INGR_GOAT_CHEESE:
            return "Goat Cheese";
        case Plazza::IPizza::Ingredients::INGR_STEAK:
            return "Steak";
        case Plazza::IPizza::Ingredients::INGR_CHIEF_LOVE:
            return "Chief Love";
        default:
            return "Unknown";
    }
}

std::string Plazza::ConvertEnum::pizzaTypeToString(Plazza::IPizza::PizzaType type)
{
    switch (type)
    {
        case Plazza::IPizza::PizzaType::Regina:
            return "Regina";
        case Plazza::IPizza::PizzaType::Margarita:
            return "Margarita";
        case Plazza::IPizza::PizzaType::Americana:
            return "Americana";
        case Plazza::IPizza::PizzaType::Fantasia:
            return "Fantasia";
        default:
            return "Unknown";
    }
}

std::string Plazza::ConvertEnum::pizzaSizeToString(Plazza::IPizza::PizzaSize size)
{
    switch (size)
    {
        case Plazza::IPizza::PizzaSize::S:
            return "S";
        case Plazza::IPizza::PizzaSize::M:
            return "M";
        case Plazza::IPizza::PizzaSize::L:
            return "L";
        case Plazza::IPizza::PizzaSize::XL:
            return "XL";
        case Plazza::IPizza::PizzaSize::XXL:
            return "XXL";
        default:
            return "Unknown";
    }
}

Plazza::IPizza::PizzaType Plazza::ConvertEnum::getPizzaType(const std::string &type)
{
    static const std::unordered_map<std::string, Plazza::IPizza::PizzaType> TypeMap {
        {"regina", Plazza::IPizza::PizzaType::Regina},
        {"margarita", Plazza::IPizza::PizzaType::Margarita},
        {"americana", Plazza::IPizza::PizzaType::Americana},
        {"fantasia", Plazza::IPizza::PizzaType::Fantasia}
    };
    std::unordered_map<std::string, Plazza::IPizza::PizzaType>::const_iterator it = TypeMap.find(type);
    if (it == TypeMap.end())
        return Plazza::IPizza::PizzaType::UNKNOWN_TYPE;
    return it->second;
}

Plazza::IPizza::PizzaSize Plazza::ConvertEnum::getPizzaSize(const std::string &size)
{
    static const std::unordered_map<std::string, Plazza::IPizza::PizzaSize> SizeMap {
        {"S", Plazza::IPizza::PizzaSize::S},
        {"M", Plazza::IPizza::PizzaSize::M},
        {"L", Plazza::IPizza::PizzaSize::L},
        {"XL", Plazza::IPizza::PizzaSize::XL},
        {"XXL", Plazza::IPizza::PizzaSize::XXL}
    };
    std::unordered_map<std::string, Plazza::IPizza::PizzaSize>::const_iterator it = SizeMap.find(size);
    if (it == SizeMap.end())
        return Plazza::IPizza::PizzaSize::UNKNOWN_SIZE;
    return it->second;
}
