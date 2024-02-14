#include "Client.hpp"


Plazza::Kitchen::Client::Client()
{
    this->servSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (this->servSocket == -1)
        throw(Plazza::Kitchen::Client::SocketError());

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<in_port_t>(8080));
    addr.sin_addr.s_addr = INADDR_ANY;
    if (connect(this->servSocket, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
        throw(Plazza::Kitchen::Client::ConnectionError());
    this->refreshThrd = std::thread(&Plazza::Kitchen::Client::refreshThread, this);
    this->stopThread = false;
}

Plazza::Kitchen::Client::~Client()
{
    this->stopThread = true;
    this->refreshThrd.join();
    close(this->servSocket);
}

void Plazza::Kitchen::Client::refreshThread()
{
    while (true)
    {
        FD_ZERO(&this->readfd);
        FD_ZERO(&this->writefd);
        FD_SET(this->servSocket, &this->readfd);
        FD_SET(this->servSocket, &this->writefd);
        if (this->stopThread)
            return;
        if (select(this->servSocket + 1, &this->readfd, &this->writefd, NULL, NULL) == -1)
            throw(Plazza::Kitchen::Client::SelectError());
        this->reqMutex.lock();
        if (!this->req.empty() && FD_ISSET(this->servSocket, &this->writefd)) {
            write(this->servSocket, this->req.c_str(), this->req.size());
            this->req.clear();
        }
        this->reqMutex.unlock();
        if (FD_ISSET(this->servSocket, &this->readfd)) {
            this->resMutex.lock();
            char buf[4096];
            int readNb;
            readNb = read(this->servSocket , buf, 4095);
            buf[readNb] = 0;
            this->res = std::string(buf);
            this->resMutex.unlock();
        }
    }
}


void Plazza::Kitchen::Client::setReq(std::string str)
{
    this->reqMutex.lock();
    this->req = str;
    this->reqMutex.unlock();
}

std::string Plazza::Kitchen::Client::getRes()
{
    this->resMutex.lock();
    std::string out;
    if (!this->res.empty()) {
        out = this->res;
        this->res.clear();
    }
    this->resMutex.unlock();
    return out;
}

void Plazza::Kitchen::Client::operator>>(std::string &str)
{
    this->resMutex.lock();
    if (!this->res.empty()) {
        str = this->res;
        this->res.clear();
    }
    this->resMutex.unlock();
}

void Plazza::Kitchen::Client::operator<<(const std::string &str)
{
    this->reqMutex.lock();
    this->req = str;
    this->reqMutex.unlock();
}
