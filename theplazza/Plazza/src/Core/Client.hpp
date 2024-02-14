#pragma once 

#include <iostream>
#include <mutex>
#include <thread>

namespace Plazza {
    namespace Reception {
        class Client {
            
            public:
                class ClientReadError: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Client read error.";}
                };

                class ClientBadFormatReq: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[ERROR] Client bad format request.";}
                };

                class ClientClosed: public  std::exception {
                    public:
                        const char* what() const noexcept override {return "[INFO] Client closed.";}
                };
                int socket;
                int resStatus;
                int reqStatus;
                std::string req;
                std::string res;
                int freeSlots;
                Client(int socket);
                ~Client();
                void sendRes();
                void getReq();
        };
    }
}