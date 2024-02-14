/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/navy.h"

int main(int ac, char **av)
{
    int ret = 0;

    if (ac == 1)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return (0);
    }
    if (ac == 2 || ac == 3)
        ret = navy(ac, av);
    else
        ret = 84;
    return (ret);
}
