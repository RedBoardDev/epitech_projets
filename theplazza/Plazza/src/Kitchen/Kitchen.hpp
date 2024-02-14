#pragma once
#include <chrono>
#include <vector>
#include <map>
#include "../Pizzas/IPizza.hpp"
#include <mutex>
#include "ThreadPool.hpp"

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

namespace Plazza {
    namespace Kitchen {
        class Kitchen {
            private:
                int _maxCookerPerKitchen; // maximum of cooker on kitchen
                int _actualPizzaOnKitchen; // actual nbr pizza cook + waiting
                int _maxPizzasPerKitchen; // number of pizza per kitchen
                double _replaceStockTime; // time in milliseconds for the kitchen stock to replace ingredient
                size_t _timerIngredients = 0;
                size_t _timerCloseKitchen = 0;
                std::map<Plazza::IPizza::Ingredients, int> _stock;
                std::mutex _pizzaMutex;
                Plazza::ThreadPool _threadPool;
                void refillStock();
                void resetTimerCloseKitchen();
                bool checkStock();
                const std::string generateKitchenName();
                void useIngredientOnStock();

            public:
                std::string _name;
                int _cookTimerMultiplier; // multiplier for the cooking time
                std::unique_ptr<Plazza::IPizza> _newPizza;
                void processKitchen();
                void displayStatus();
                Kitchen(int maxCookerPerKitchen, int cookTimerMultiplier, double replaceStockTime);
                ~Kitchen();
        };
    }
}
