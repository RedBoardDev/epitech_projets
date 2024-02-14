#pragma once

#include <memory>
#include "./Pizzas/IPizza.hpp"
#include "./Pizzas/Pizza.hpp"

namespace Plazza {
    class PizzaFactory {
        private:
            /* data */
        public:
            static std::unique_ptr<Plazza::IPizza> createPizza(const Plazza::IPizza::PizzaType &name, const Plazza::IPizza::PizzaSize &size);
    };
}
