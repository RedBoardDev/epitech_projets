#include <string>
#include <unordered_map>
#include "./Pizzas/IPizza.hpp"

namespace Plazza {
    class ConvertEnum {
    public:
        static std::string ingredientsToString(Plazza::IPizza::Ingredients ingredient);
        static std::string pizzaTypeToString(Plazza::IPizza::PizzaType type);
        static std::string pizzaSizeToString(Plazza::IPizza::PizzaSize size);
        static Plazza::IPizza::PizzaType getPizzaType(const std::string &type);
        static Plazza::IPizza::PizzaSize getPizzaSize(const std::string &size);
    };
}
