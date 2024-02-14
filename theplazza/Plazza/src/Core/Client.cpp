
#include "Client.hpp"
#include "../Status.hpp"
#include <unistd.h>
#include <string>

Plazza::Reception::Client::Client(int socket)
{
    this->resStatus = Plazza::NONE;
    this->reqStatus = Plazza::NONE;
    this->socket = socket;
    this->freeSlots = 0;
}

Plazza::Reception::Client::~Client()
{

}

void Plazza::Reception::Client::sendRes()
{
    std::string out = std::to_string(this->resStatus) + " " + this->res;

    write(this->socket, out.c_str(), out.size());
    res.clear();
    resStatus = Plazza::NONE;
}

void Plazza::Reception::Client::getReq()
{
    char buf[4096];
    int readNb;
    if ((readNb = read(this->socket , buf, 4095)) == 0) {
        throw(Plazza::Reception::Client::ClientClosed());
    } else if (readNb == -1)
        throw(Plazza::Reception::Client::ClientReadError());
    else {
        buf[readNb] = 0;
        std::string strBuf(buf);
        try {
            this->reqStatus = std::stoi(strBuf);
            this->req = strBuf.substr(strBuf.find(' ') + 1);
        } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
            throw(Plazza::Reception::Client::ClientBadFormatReq());
        }
    }
}
