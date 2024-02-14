#include <vector>
#include "IPizza.hpp"

namespace Plazza {
    namespace Pizza {
        class Margarita : public Plazza::IPizza {
            private:
                Plazza::IPizza::PizzaSize _size;
                Plazza::IPizza::PizzaType _type;
                int _backedTime = 1;
                std::vector<Plazza::IPizza::Ingredients> _ingredients {IPizza::INGR_BICHE, IPizza::INGR_TOMATO, IPizza::INGR_GRUYERE};

            public:
                Margarita(const Plazza::IPizza::PizzaSize &size) : _size(size){};
                ~Margarita() {};
                const Plazza::IPizza::PizzaSize &getSize() const { return this->_size; };
                Plazza::IPizza::PizzaType getType() const { return Plazza::IPizza::Margarita; };
                const int &getBakedTime() const { return this->_backedTime; };
                const std::vector<Plazza::IPizza::Ingredients> &getIngredients() const { return this->_ingredients; };
        };
    }
}
