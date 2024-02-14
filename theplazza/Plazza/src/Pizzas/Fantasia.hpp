#include <vector>
#include "IPizza.hpp"

namespace Plazza {
    namespace Pizza {
        class Fantasia : public Plazza::IPizza {
            private:
                Plazza::IPizza::PizzaSize _size;
                Plazza::IPizza::PizzaType _type;
                int _backedTime = 4;
                std::vector<Plazza::IPizza::Ingredients> _ingredients {IPizza::INGR_BICHE, IPizza::INGR_TOMATO, IPizza::INGR_EGGPLANTS, IPizza::INGR_GOAT_CHEESE, IPizza::INGR_CHIEF_LOVE};

            public:
                Fantasia(const Plazza::IPizza::PizzaSize &size) : _size(size){};
                ~Fantasia() {};
                const Plazza::IPizza::PizzaSize &getSize() const { return this->_size; };
                Plazza::IPizza::PizzaType getType() const { return Plazza::IPizza::Fantasia; };
                const int &getBakedTime() const { return this->_backedTime; };
                const std::vector<Plazza::IPizza::Ingredients> &getIngredients() const { return this->_ingredients; };
        };
    }
}
