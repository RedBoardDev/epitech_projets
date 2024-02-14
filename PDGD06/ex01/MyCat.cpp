/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD06-thomas.ott
** File description:
** , MyCat.cpp
*/

#include <fstream>
#include <iostream>

int main(int argc, char const **argv)
{
    int feur = 0;
    std::ifstream ifs;
    std::string file;

    if (argc == 1) {
        while (std::getline(std::cin, file))
            std::cout << file << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            ifs.open(argv[i], std::ios_base::in);
            if (ifs.is_open() == true) {
                std::cout << ifs.rdbuf();
                ifs.close();
            } else {
                feur = 84;
                std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            }
        }
    }
    return feur;
}
