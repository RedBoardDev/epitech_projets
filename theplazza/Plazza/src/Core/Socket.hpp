#pragma once

#include <vector>
#include "Client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

namespace Plazza {
    namespace Reception {

        class Socket {
            public:
                class SocketError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Cannot create socket";}
                };
                class SocketOptError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Cannot set socket options";}
                };
                class SocketBindError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Cannot bind socket";}
                };
                class SocketListenError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Cannot listen on socket";}
                };

                class SelectError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Select error";}
                };
                class AcceptError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Client accept error";}
                };
                fd_set readfds;
                fd_set writefds;
                int mainSocket;
                struct sockaddr_in addr;
                int addrlen;
                std::vector<Client> Clients;
                std::mutex cliMutex;
                Socket(int port = 8080);
                ~Socket();
                void refresh();
        };
    }
}


