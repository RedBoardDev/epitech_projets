#include <iostream>
#include <dlfcn.h>
#include <cstring>

#pragma once

class DLLoader
{
    private:

    public:
        void *handle = NULL;

        class DlError: public  std::exception {
            public:
                const char* what() const noexcept override {return std::strerror(errno);}
        };
        DLLoader();
        DLLoader(const std::string &filemane);
        void openDL(const std::string &filemane);
        void closeDL();
        ~DLLoader();
        template <typename T>
        T *getInstance(const std::string &targetFunction);
};

template <typename T>
T *DLLoader::getInstance(const std::string &targetFunction)
{
    T *temp = reinterpret_cast<T *> (dlsym(handle, targetFunction.c_str()));

    if (temp == nullptr)
        throw(DLLoader::DlError());
    return temp;
}
