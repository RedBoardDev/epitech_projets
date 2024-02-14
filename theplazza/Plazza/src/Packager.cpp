#include "Packager.hpp"
#include "ConvertEnum.hpp"
#include "./Logs/Error.hpp"

std::string Plazza::Packager::pack(const std::unique_ptr<Plazza::IPizza> &obj)
{
    std::string out;
    out += std::to_string(obj->getType());
    out += "|";
    out += std::to_string(obj->getSize());
    return out;
}

std::unique_ptr<Plazza::IPizza> Plazza::Packager::unpack(const std::string &str)
{
    std::vector<std::string> splited = Utils::split(str, "|");

    int convertNbr = std::stoi(splited[1]);
    int convertType = std::stoi(splited[0]);
    Plazza::IPizza::PizzaSize size;
    Plazza::IPizza::PizzaType type;

    switch (convertType) {
        case Plazza::IPizza::PizzaType::Regina:
            type = Plazza::IPizza::PizzaType::Regina;
            break;
        case Plazza::IPizza::PizzaType::Margarita:
            type = Plazza::IPizza::PizzaType::Margarita;
            break;
        case Plazza::IPizza::PizzaType::Americana:
            type = Plazza::IPizza::PizzaType::Americana;
            break;
        case Plazza::IPizza::PizzaType::Fantasia:
            type = Plazza::IPizza::PizzaType::Fantasia;
            break;

        default:
            throw Error("Bad type");
            break;
    }

    switch (convertNbr) {
        case Plazza::IPizza::PizzaSize::S:
            size = Plazza::IPizza::PizzaSize::S;
            break;
        case Plazza::IPizza::PizzaSize::M:
            size = Plazza::IPizza::PizzaSize::M;
            break;
        case Plazza::IPizza::PizzaSize::L:
            size = Plazza::IPizza::PizzaSize::L;
            break;
        case Plazza::IPizza::PizzaSize::XL:
            size = Plazza::IPizza::PizzaSize::XL;
            break;
        case Plazza::IPizza::PizzaSize::XXL:
            size = Plazza::IPizza::PizzaSize::XXL;
            break;

        default:
            throw Error("Bad size");
            break;
    }
    return PizzaFactory::createPizza(type, size);
}
