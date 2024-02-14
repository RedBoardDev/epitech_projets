#include "Reception.hpp"
#include "../Kitchen/Kitchen.hpp"
#include "../ConvertEnum.hpp"
#include "../Logs/Critical.hpp"
#include "../Logs/Error.hpp"
#include "../Logs/Info.hpp"

Plazza::Reception::Reception::Reception(std::string mult, std::string nbCook, std::string time)
{
    this->kitchenSize = std::stoi(nbCook);
    Info("Start reception");
    try {
        this->multCook = std::stod(mult);
    } catch (const std::exception &e) {
        throw Error("Bad parameter");
    }
    this->cookTime = std::stoi(time);
}

Plazza::Reception::Reception::~Reception()
{
    this->srvThrd.join();
    this->stdinThrd.join();
}


void Plazza::Reception::Reception::serverThread()
{
    while (true) {
        try {
            this->serv.refresh();
            if (this->runServ == false)
                return;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Plazza::Reception::Reception::serverRun()
{
    this->runServ = true;
    this->srvThrd = std::thread(&Plazza::Reception::Reception::serverThread, this);
}

void Plazza::Reception::Reception::serverStop()
{
    this->runServ = false;
    this->srvThrd.join();
}

void Plazza::Reception::Reception::sendPizzas()
{
    for (size_t i = 0; i < this->pizzas.size(); ++i) {
        auto lowest = this->serv.Clients.begin();
        for (auto j = this->serv.Clients.begin(); j != this->serv.Clients.end(); ++j) {
            if (j->freeSlots > lowest->freeSlots)
                lowest = j;
        }
        this->serv.cliMutex.lock();
        lowest->resStatus = Plazza::DO_PIZZA;
        lowest->res = Plazza::Packager::pack(this->pizzas[i]);
        this->serv.cliMutex.unlock();
        while (lowest->reqStatus == Plazza::NONE);
        this->serv.cliMutex.lock();
        lowest->reqStatus = Plazza::NONE;
        lowest->req.clear();
        this->serv.cliMutex.unlock();
        lowest->freeSlots -= 1;
    }
    this->pizzas.clear();
}

void Plazza::Reception::Reception::stdinThread()
{
    for (std::string line; std::getline(std::cin, line);) {
        if (line == "status") {
            for (auto i = this->serv.Clients.begin(); i != this->serv.Clients.end(); ++i) {
                this->serv.cliMutex.lock();
                i->resStatus = Plazza::STATUS_KITCHEN;
                i->res = "kitchen status";
                this->serv.cliMutex.unlock();
                while (i->reqStatus == Plazza::NONE);
                this->serv.cliMutex.lock();
                i->reqStatus = Plazza::NONE;
                i->req.clear();
                this->serv.cliMutex.unlock();
            }
            continue;
        }

        std::vector<std::string> commands = Plazza::Utils::split(line, ";");
        for (auto i = commands.begin(); i != commands.end(); ++i) {
            try {
                std::vector<std::string> command = Plazza::Utils::split(*i, " ");
                if (command.size() < 3)
                    throw Critical("Missing parameter");
                Plazza::IPizza::PizzaType typePizza = Plazza::ConvertEnum::getPizzaType(command[0]);
                if (typePizza == Plazza::IPizza::PizzaType::UNKNOWN_TYPE)
                    throw Critical("Bad Type");
                Plazza::IPizza::PizzaSize sizePizza = Plazza::ConvertEnum::getPizzaSize(command[1]);
                if (sizePizza == Plazza::IPizza::PizzaSize::UNKNOWN_SIZE)
                    throw Critical("Bad size");
                if (!std::regex_match(command[2], std::regex("x[1-9][0-9]*")))
                    throw Critical("Bad number");

                int nb = std::stoi(command[2].substr(1));
                for (int j = 0; j < nb; ++j)
                    this->pizzas.push_back(PizzaFactory::createPizza(typePizza, sizePizza));
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        size_t tot = 0;
        for (auto i = this->serv.Clients.begin(); i != this->serv.Clients.end(); ++i) {
            this->serv.cliMutex.lock();
            i->resStatus = Plazza::STATUS_FREE;
            i->res = "";
            this->serv.cliMutex.unlock();
            while (i->reqStatus == Plazza::NONE);
            this->serv.cliMutex.lock();
            std::string reqOut = i->req;
            i->reqStatus = Plazza::NONE;
            i->req.clear();
            this->serv.cliMutex.unlock();
            try {
                i->freeSlots = std::stoi(reqOut);
            } catch (const std::exception &e) {
                throw Error("invalid stoi");
            }
            tot += i->freeSlots;
        }
        if (tot < pizzas.size()) {
            int tmp = pizzas.size() - tot;
            int nbToOpen = tmp / (this->kitchenSize * 2);
            (tmp % (this->kitchenSize * 2) != 0) ? (++nbToOpen) : (0);
            size_t waitNb = nbToOpen + this->serv.Clients.size();
            Info("Pizza received x" + std::to_string(pizzas.size()));
            for (int i = 0; i < nbToOpen; ++i) {
                try {
                    int pidTmp = std::Fork::MakeChild();
                    if (pidTmp == 0) {
                        Plazza::Kitchen::Kitchen k(this->kitchenSize, this->multCook, this->cookTime);
                        k.processKitchen();
                    }
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
            }
            while(this->serv.Clients.size() != waitNb);
        }
        this->sendPizzas();
    }
}

void Plazza::Reception::Reception::stdinReaderRun()
{
    this->runStdin = true;
    this->stdinThrd = std::thread(&Plazza::Reception::Reception::stdinThread, this);
}

void Plazza::Reception::Reception::stdinReaderStop()
{
    this->runStdin = false;
    this->stdinThrd.join();
}
