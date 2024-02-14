#include <regex>
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Kitchen.hpp"
#include "Client.hpp"
#include "../Packager.hpp"
#include "../Status.hpp"
#include "../Utils.hpp"
#include "CookerTask.hpp"
#include "../ConvertEnum.hpp"
#include "../Logs/Info.hpp"

Plazza::Kitchen::Kitchen::Kitchen(int maxCookerPerKitchen, int cookTimerMultiplier, double replaceStockTime): _threadPool(maxCookerPerKitchen) {
    this->_name = this->generateKitchenName();
    _threadPool.setName(this->_name);
    Info("Create kitchen " + this->_name);
    this->_actualPizzaOnKitchen = 0;
    this->_replaceStockTime = replaceStockTime;
    this->_maxPizzasPerKitchen = 2 * maxCookerPerKitchen;
    this->_maxCookerPerKitchen = maxCookerPerKitchen;
    this->_cookTimerMultiplier = cookTimerMultiplier;
    this->resetTimerCloseKitchen();
    this->_stock = {
        {Plazza::IPizza::Ingredients::INGR_BICHE, 5},
        {Plazza::IPizza::Ingredients::INGR_TOMATO, 5},
        {Plazza::IPizza::Ingredients::INGR_GRUYERE, 5},
        {Plazza::IPizza::Ingredients::INGR_HAM, 5},
        {Plazza::IPizza::Ingredients::INGR_EGGPLANTS, 5},
        {Plazza::IPizza::Ingredients::INGR_MUSHROOMS, 5},
        {Plazza::IPizza::Ingredients::INGR_GOAT_CHEESE, 5},
        {Plazza::IPizza::Ingredients::INGR_STEAK, 5},
        {Plazza::IPizza::Ingredients::INGR_CHIEF_LOVE, 5}
    };
}

Plazza::Kitchen::Kitchen::~Kitchen() {}

void Plazza::Kitchen::Kitchen::refillStock() {
    for (auto &[ingredient, quantity] : this->_stock) {
        quantity += 1;
    }
}

void Plazza::Kitchen::Kitchen::resetTimerCloseKitchen() {
    this->_timerCloseKitchen = NOW;
}

bool Plazza::Kitchen::Kitchen::checkStock()
{
    std::vector<Plazza::IPizza::Ingredients> ingredients = _newPizza.get()->getIngredients();
    for (size_t i = 0; i < ingredients.size(); i++) {
        auto it = _stock.find(ingredients.at(i));
        if (it->second < 0)
            return false;
    }
    return true;
}

void Plazza::Kitchen::Kitchen::useIngredientOnStock()
{
    std::vector<Plazza::IPizza::Ingredients> ingredients = _newPizza.get()->getIngredients();
    for (size_t i = 0; i < ingredients.size(); i++) {
        auto it = _stock.find(ingredients.at(i));
        it->second -= 1;
    }
}

void Plazza::Kitchen::Kitchen::processKitchen() {
    Plazza::Kitchen::Client cli;

    while (true) {
        std::string out;
        cli >> out;
        if (!out.empty()) {
            std::vector<std::string> rsp = Utils::split(out, " ");;
            if (rsp[0] == std::to_string(STATUS_FREE)) {
                std::string res = std::to_string(STATUS_FREE_ANSW) + " " + std::to_string(this->_actualPizzaOnKitchen - this->_maxPizzasPerKitchen);
                cli << res;
            }
            if (rsp[0] == std::to_string(DO_PIZZA)) {
                this->_newPizza = Plazza::Packager::unpack(rsp[1]);
                this->_actualPizzaOnKitchen += 1;
                std::shared_ptr<CookerTask> cookerTask = std::make_shared<CookerTask>(
                    this->_newPizza,
                    this->_cookTimerMultiplier,
                    this->_replaceStockTime,
                    [this](){this->resetTimerCloseKitchen();},
                    [this](){return this->checkStock();},
                    [this](){this->useIngredientOnStock();},
                    [this](){this->_actualPizzaOnKitchen -= 1;}
                );

                this->_threadPool.addTask(cookerTask);
                cli << std::to_string(Plazza::PIZZA_WIP);
            }
            if (rsp[0] == std::to_string(STATUS_KITCHEN)) {
                this->displayStatus();
                cli << std::to_string(Plazza::STATUS_KITCHEN_ANSW);
            }
        }

        if ((NOW - this->_timerCloseKitchen) >= 5000) {
            this->_threadPool.stop();
            Info("Kitchen " + this->_name + " closed");
            std::exit(0);
        }
        if ((NOW - this->_timerIngredients) >= this->_replaceStockTime) {
            this->refillStock();
            Info("Refill kitchen " + this->_name);
            this->_timerIngredients = NOW;
        }
    }
    this->_threadPool.stop();
    std::exit(0);
}

void Plazza::Kitchen::Kitchen::displayStatus() {
    auto queueSize = this->_threadPool._queue.get()->size();

    std::cout << std::setw(4) << "" << "- x" << this->_threadPool._nbrThread << " pizzas in cook and x" << queueSize << " pizzas waiting" << std::endl;
    for (const auto &workerType : this->_threadPool._workersPizzaType) {
        std::cout << std::setw(8) << "" << "- " << Plazza::ConvertEnum::pizzaTypeToString(workerType) << std::endl;
    }
    std::cout << std::setw(4) << "" << "- Ingredients:" << std::endl;
    for (const auto &pair : this->_stock) {
        std::cout << std::setw(8) << "" << "- " << Plazza::ConvertEnum::ingredientsToString(pair.first) << "(" << pair.second << ")" << std::endl;
    }
}

const std::string Plazza::Kitchen::Kitchen::generateKitchenName() {
    std::srand(std::time(nullptr));
    std::vector<std::string> pizzaList = {
        "Pizzaroma", "Napolicrust", "SicilianSlice", "ToscanaTaste", "VesuvioBake",
        "AzzurroOven", "RossoCrust", "VerdeDough", "BiancoBites", "NeroPies",
        "TrattoriaCrust", "RistoranteRustic", "CucinaCrust", "FornoFresh", "CasaCalzone",
        "FamigliaFeast", "MargheritaMelt", "PepperoniPies", "FormaggioFusion", "NapoletanaNibbles",
        "CapriCrust", "DiavolaDelight", "MarinaraMouthful", "SicilianoSlices", "CalzoneCorner",
        "ProsciuttoParadise", "FunghiFeast", "TonnoTreats", "CarbonaraKitchen", "MareMunch",
        "StagioniStonebake", "CapreseCravings", "RusticoRolls", "PrimaveraPies", "RomanaRustic",
        "ParmigianoPlace", "PestoPerfection", "GorgonzolaGoodness", "MozzaMelt", "RicottaRustic",
        "RomanoRolls", "BasilicoBites", "OreganoOven", "AglioAroma", "PeperoncinoPizzas",
        "DolceDough", "ProntoPizza", "GustoGrill", "StellaStonebake", "LunaLunch"
    };
    int randIndex = std::rand() % pizzaList.size();
    return (pizzaList[randIndex]);
    return 0;
}
