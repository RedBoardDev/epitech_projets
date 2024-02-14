/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-oscar.frank
** File description:
** DLLoader.hpp
*/

#pragma once

#include <dlfcn.h>
#include <fstream>
#include <iostream>
#include <memory>

class DLLoader {
public:
    DLLoader() {
    }
 
    DLLoader(std::string libname)
    {
        this->retDlOpen = dlopen(libname.c_str(), RTLD_LAZY | RTLD_NOW);
    }

    ~DLLoader()
    {
        if (this->retDlOpen)
           dlclose(this->retDlOpen);
    }

    template <typename T>
    T* getInstance(std::string symbol)
    {
        if (this->retDlOpen) {
            void* dlg = dlsym(this->retDlOpen, symbol.c_str());
            if (dlg == NULL)
                return nullptr;
            return reinterpret_cast<T*>(dlg);
        } else {
            std::cout << dlerror() << std::endl;
            exit(84);
            return nullptr;
        }
    }

    void load_new(std::string libname)
    {
        if (this->retDlOpen)
            dlclose(this->retDlOpen);
        this->retDlOpen = dlopen(libname.c_str(), RTLD_LAZY | RTLD_NOW);
    }

    void rm_actual()
    {
        if (this->retDlOpen)
            dlclose(this->retDlOpen);
    }


protected:
    void* retDlOpen = nullptr;
};
