/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** threadPool.cpp
*/

#include "ThreadPool.hpp"
#include "../Logs/Info.hpp"

Plazza::ThreadPool::ThreadPool(size_t maxThreads) : _maxThreads(maxThreads), _stop(false) {
    this->_queue = std::make_unique<Plazza::SafeQueue>();
}

Plazza::ThreadPool::~ThreadPool()
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->_stop = true;
    stop();
}

void Plazza::ThreadPool::setName(std::string name)
{
    this->_name = name;
}

void Plazza::ThreadPool::addTask(std::shared_ptr<CookerTask> &task)
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    if (this->_nbrThread < this->_maxThreads) {
        this->_nbrThread += 1;
        this->_workersPizzaType.emplace_back(task.get()->_pizza.get()->getType());
        this->_workers.emplace_back(&Plazza::ThreadPool::worker, this);
    }
    this->_queue->push(std::move(task));
}

void Plazza::ThreadPool::stop()
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    _stop = true;
    for (auto &worker : this->_workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
    this->_workers.clear();
}

void Plazza::ThreadPool::worker() {
    Info("Cooker start cooking in " + this->_name);
    while (!this->_stop) {
        std::shared_ptr<CookerTask> taskToExecute;
        if (this->_queue->pop(taskToExecute)) {
            taskToExecute->executeTask();
        } else
            break;
    }
    Info("Cooker stop cooking in " + this->_name);
    _mutex.lock();
    this->_nbrThread -= 1;
    _mutex.unlock();
}
