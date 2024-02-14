/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** ISafeQueue.hpp
*/

#pragma once
#include "../Pizzas/IPizza.hpp"
#include <functional>
#include <memory>
#include <queue>
#include "CookerTask.hpp"

namespace Plazza {
    class ISafeQueue {
        public:
            virtual ~ ISafeQueue() = default;
            virtual void push(std::shared_ptr<CookerTask> task) = 0;
            virtual bool pop(std::shared_ptr<CookerTask> &task) = 0;
            virtual bool empty() = 0;
            virtual int size() = 0;
    };
}
