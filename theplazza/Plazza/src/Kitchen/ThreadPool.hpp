/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** ThreadPool.hpp
*/

#pragma once

#include <thread>
#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "ISafeQueue.hpp"
#include "SafeQueue.hpp"
#include <memory>
#include <string>
#include <map>
#include "../Pizzas/Pizza.hpp"
#include "CookerTask.hpp"

namespace Plazza {
    class ThreadPool {
        public:
            ThreadPool(size_t maxThread);
            void setName(std::string name);
            ~ThreadPool();
            void stop();
            void addTask(std::shared_ptr<CookerTask> &task);
            std::unique_ptr<Plazza::ISafeQueue> _queue;
            std::vector<Plazza::IPizza::PizzaType> _workersPizzaType;
            size_t _nbrThread;
        private:
            std::string _name;
            std::vector<std::thread> _workers;
            void worker();
            size_t _maxThreads;
            bool _stop = false;
            std::mutex _mutex;
    };
}