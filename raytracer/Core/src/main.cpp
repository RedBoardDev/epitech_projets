/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** test
*/

#include "Scene/Camera.hpp"
#include "Errors/Critical.hpp"
#include "Core.hpp"
#include <iostream>


int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            throw Critical("Wrong or too many parameters.");
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
        return (84);
    }
    Core cr("plugins/", av[1]);
    cr.render();
    return 0;
}
