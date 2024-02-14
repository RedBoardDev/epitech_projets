#pragma once

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

namespace std {
    class Fork {
        public:
            class ForkError: public  std::exception {
                public:
                    const char* what() const noexcept override {return "[ERROR] Fork error";}
            };
            static int MakeChild();
            static int getPid();
    };
}
