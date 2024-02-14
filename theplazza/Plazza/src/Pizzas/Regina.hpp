#include <vector>
#include "IPizza.hpp"

namespace Plazza {
    namespace Pizza {
        class Regina : public Plazza::IPizza {
            private:
                Plazza::IPizza::PizzaSize _size;
                Plazza::IPizza::PizzaType _type;
                int _backedTime = 2;
                std::vector<Plazza::IPizza::Ingredients> _ingredients {IPizza::INGR_BICHE, IPizza::INGR_TOMATO, IPizza::INGR_GRUYERE, IPizza::INGR_HAM, IPizza::INGR_MUSHROOMS};

            public:
                Regina(const Plazza::IPizza::PizzaSize &size) : _size(size){};
                ~Regina() {};
                const Plazza::IPizza::PizzaSize &getSize() const { return this->_size; };
                Plazza::IPizza::PizzaType getType() const { return Plazza::IPizza::Regina; };
                const int &getBakedTime() const { return this->_backedTime; };
                const std::vector<Plazza::IPizza::Ingredients> &getIngredients() const { return this->_ingredients; };
        };
    }
}
