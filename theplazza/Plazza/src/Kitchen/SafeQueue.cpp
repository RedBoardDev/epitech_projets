/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** SafeQueue.cpp
*/

#include "SafeQueue.hpp"

Plazza::SafeQueue::SafeQueue() {}

Plazza::SafeQueue::~SafeQueue() {}

void Plazza::SafeQueue::push(std::shared_ptr<CookerTask> task)
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->_tasks.push(std::move(task));
}

bool Plazza::SafeQueue::pop(std::shared_ptr<CookerTask> &task)
{
    if (this->_tasks.empty())
        return false;
    task = std::move(this->_tasks.front());
    this->_tasks.pop();
    return true;
}

bool Plazza::SafeQueue::empty()
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    return this->_tasks.empty();
}

int Plazza::SafeQueue::size()
{
    return this->_tasks.size();
}
