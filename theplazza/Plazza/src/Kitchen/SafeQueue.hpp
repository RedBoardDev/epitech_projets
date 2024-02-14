/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** SafeQueue.hpp
*/

#pragma once
#include "ISafeQueue.hpp"
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "CookerTask.hpp"

namespace Plazza {
    class SafeQueue : public ISafeQueue {
        public:
            SafeQueue();
            ~SafeQueue();
            void push(std::shared_ptr<CookerTask> task);
            bool pop(std::shared_ptr<CookerTask> &task);
            bool empty();
            int size();
        private:
            std::mutex _mutex;
            std::queue<std::shared_ptr<CookerTask>> _tasks;
    };
}
