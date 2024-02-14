#pragma once

#include <vector>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <mutex>
#include "../Status.hpp"
#include <thread>


namespace Plazza {
    namespace Kitchen {
        class Client {
            private:
                int servSocket;
                std::string req;
                std::string res;
                fd_set readfd;
                fd_set writefd;
                std::mutex reqMutex;
                std::mutex resMutex;
                void refreshThread();
                std::thread refreshThrd;
                bool stopThread;
            public:
                class SocketError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Cannot create socket";}
                };

                class ConnectionError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Ennable to connect to the reception";}
                };

                class SelectError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Select error (Disconnected)";}
                };
                
                Client();
                ~Client();
                void setReq(std::string str);
                std::string getRes();
                void operator>>(std::string &str);
                void operator<<(const std::string &str);
        };
    }
}
