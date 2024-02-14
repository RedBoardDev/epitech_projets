#pragma once

#include <memory>
#include <functional>
#include "../Pizzas/IPizza.hpp"
#include <thread>
#include <mutex>

namespace Plazza {
    class CookerTask {
    public:
        CookerTask(std::unique_ptr<Plazza::IPizza> &pizza, double cookTimerMultiplier,
            int replaceStockTime, std::function<void()> resetTimerCloseKitchenFunc,
            std::function<bool()> checkStockFunc, std::function<void()> useIngredientOnStock, std::function<void()> decActualPizzaOnKitchenFunc);
        ~CookerTask();
        void executeTask();
        std::unique_ptr<Plazza::IPizza> &_pizza;

    private:
        double _cookTimerMultiplier;
        int _replaceStockTime;
        std::function<void()> _resetTimerCloseKitchenFunc;
        std::function<bool()> _checkStockFunc;
        std::function<void()> _useIngredientOnStock;
        std::function<void()> _decActualPizzaOnKitchenFunc;
        std::mutex _pizzaMutex;
    };
}
