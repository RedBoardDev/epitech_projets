#pragma once

#include <iostream>
#include "Socket.hpp"
#include <thread>
#include "../Status.hpp"
#include <string>
#include "../Utils.hpp"
#include <regex>
#include <mutex>
#include "../Pizzas/IPizza.hpp"
#include "../Packager.hpp"
#include "../PizzaFactory.hpp"
#include "Fork.hpp"

namespace Plazza {
    namespace Reception {
        class Reception {
            private:
                Plazza::Reception::Socket serv;
                void serverThread();
                void stdinThread();
                void sendPizzas();
                bool runServ;
                bool runStdin;
                std::thread srvThrd;
                std::thread stdinThrd;
                int kitchenSize;
                double multCook;
                int cookTime;
                std::vector<std::unique_ptr<Plazza::IPizza>> pizzas;
            public:
                Reception(std::string mult, std::string nbCook, std::string time);
                ~Reception();
                void serverRun();
                void serverStop();
                void stdinReaderRun();
                void stdinReaderStop();
        };
    }

}