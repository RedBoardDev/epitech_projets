#pragma once
#include <memory>
#include "Pizzas/IPizza.hpp"
#include "Utils.hpp"
#include "PizzaFactory.hpp"

namespace Plazza {
    class Packager {
        public:
            static std::string pack(const std::unique_ptr<Plazza::IPizza> &obj);
            static std::unique_ptr<Plazza::IPizza> unpack(const std::string &str);
    };
}