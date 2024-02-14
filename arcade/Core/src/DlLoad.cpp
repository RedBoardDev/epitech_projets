#include "../includes/DlLoad.hpp"

DLLoader::DLLoader() {};

DLLoader::DLLoader(const std::string &filemane) {
    char *str;
    openDL(filemane);
    if ((str = dlerror()) != NULL) {
        std::cout << str << std::endl;
        throw(DLLoader::DlError());
    }
    // if (str != NULL) free(str);
}

void DLLoader::openDL(const std::string &filemane) {
    char *str;
    this->closeDL();
    this->handle = dlopen(filemane.c_str(), RTLD_LAZY | RTLD_NOW);
    if (handle == nullptr) {
        throw(DLLoader::DlError());
    }
    if ((str = dlerror()) != NULL) {
        std::cout << str << std::endl;
        throw(DLLoader::DlError());
    }
    // if (str != NULL) free(str);
}

void DLLoader::closeDL() {
    if (this->handle != NULL)
        dlclose(this->handle);
    this->handle = NULL;
}

DLLoader::~DLLoader() {
    if (this->handle != NULL)
        dlclose(this->handle);
}
