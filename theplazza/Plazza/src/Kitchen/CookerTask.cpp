#include "CookerTask.hpp"
#include "../Logs/Info.hpp"
#include "../ConvertEnum.hpp"

Plazza::CookerTask::CookerTask(std::unique_ptr<Plazza::IPizza> &pizza, double cookTimerMultiplier,
        int replaceStockTime, std::function<void()> resetTimerCloseKitchenFunc,
        std::function<bool()> checkStockFunc, std::function<void()> useIngredientOnStock, std::function<void()> decActualPizzaOnKitchenFunc): _pizza(pizza) {
    this->_cookTimerMultiplier = cookTimerMultiplier;
    this->_replaceStockTime = replaceStockTime;
    this->_resetTimerCloseKitchenFunc = resetTimerCloseKitchenFunc;
    this->_checkStockFunc = checkStockFunc;
    this->_useIngredientOnStock = useIngredientOnStock;
    this->_decActualPizzaOnKitchenFunc = decActualPizzaOnKitchenFunc;
}

Plazza::CookerTask::~CookerTask() {};

void Plazza::CookerTask::CookerTask::executeTask() {
    this->_pizzaMutex.lock();
    this->_resetTimerCloseKitchenFunc();
    this->_pizzaMutex.unlock();
    int bakedTime = this->_pizza->getBakedTime() * this->_cookTimerMultiplier;

    Info("Cooking Pizza...");
    while (!this->_checkStockFunc()) {
        this->_pizzaMutex.lock();
        this->_resetTimerCloseKitchenFunc();
        this->_pizzaMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(this->_replaceStockTime));
    }
    this->_pizzaMutex.lock();
    this->_useIngredientOnStock();
    this->_pizzaMutex.unlock();
    for (int timer = 0; timer < bakedTime; ++timer) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        this->_pizzaMutex.lock();
        this->_resetTimerCloseKitchenFunc();
        this->_pizzaMutex.unlock();
        timer += 1;
    }
    this->_pizzaMutex.lock();
    this->_decActualPizzaOnKitchenFunc();
    this->_pizzaMutex.unlock();
    Info("Pizza done: " + Plazza::ConvertEnum::pizzaTypeToString(this->_pizza->getType()) + " " + Plazza::ConvertEnum::pizzaSizeToString(this->_pizza->getSize()));
}
