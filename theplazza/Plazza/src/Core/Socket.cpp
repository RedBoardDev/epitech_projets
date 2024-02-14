#include "Socket.hpp"
#include "../Status.hpp"

Plazza::Reception::Socket::Socket(int port)
{
    if ((this->mainSocket = socket(PF_INET, SOCK_STREAM, 0)) <= 0)
        throw(Plazza::Reception::Socket::SocketError());
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(static_cast<in_port_t>(port));
    this->addr.sin_addr.s_addr = INADDR_ANY;
    this->addrlen = sizeof(this->addr);
    int opt = 1;
    if (setsockopt(this->mainSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        throw(Plazza::Reception::Socket::SocketOptError());

    if (bind(this->mainSocket,  (struct sockaddr *)&this->addr, this->addrlen) == -1)
        throw(Plazza::Reception::Socket::SocketBindError());

    if (listen(this->mainSocket, 3) < 0)
        throw(Plazza::Reception::Socket::SocketListenError());
}

Plazza::Reception::Socket::~Socket()
{
    close(this->mainSocket);
}

void Plazza::Reception::Socket::refresh()
{
    int highest = this->mainSocket;
    int tmp;
    int newCli;
    FD_ZERO(&this->readfds);
    FD_ZERO(&this->writefds);
    FD_SET(this->mainSocket, &this->readfds);
    FD_SET(this->mainSocket, &this->writefds);
    for (size_t i = 0;  i < this->Clients.size(); ++i) {
        tmp = this->Clients[i].socket;
        (tmp > highest) ? (highest = tmp) : 0;
        if (tmp > 0) {
            FD_SET(tmp, &this->writefds);
            FD_SET(tmp, &this->readfds);
        }
    }
    if (select(highest + 1, &this->readfds, &this->writefds,NULL, NULL) == -1) {
        throw(Plazza::Reception::Socket::SelectError());
    }
    if (FD_ISSET(this->mainSocket, &this->readfds)) {
        if ((newCli = accept(this->mainSocket, (struct sockaddr *)&this->addr,(socklen_t *)&this->addrlen)) < 0)
            throw(Plazza::Reception::Socket::AcceptError());
        this->Clients.push_back(Plazza::Reception::Client(newCli));
    }

    for (auto i = this->Clients.begin(); i != this->Clients.end(); ++i) {
        try {
            this->cliMutex.lock();
            if (FD_ISSET(i->socket, & this->readfds))
                i->getReq();
            if (FD_ISSET(i->socket, &this->writefds) && i->resStatus != Plazza::NONE)
                i->sendRes();
        } catch (const Plazza::Reception::Client::ClientClosed &e) {
            close(i->socket);
            this->cliMutex.unlock();
            this->Clients.erase(i);
            --i;
            continue;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        this->cliMutex.unlock();
    }
}
