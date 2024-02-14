
#include "Fork.hpp"

int std::Fork::MakeChild()
{
    pid_t c_pid = fork();

     if (c_pid == -1) {
        throw(std::Fork::ForkError());
    }
    return (static_cast<int>(c_pid));
}

int std::Fork::getPid()
{
    return (static_cast<int>(getpid()));
}