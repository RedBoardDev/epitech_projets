/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main.c
*/

#include "../include/sokoban.h"

int main(int ac, char **av)
{
    int ret = 0;

    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h')
            ret = help_message();
        else
            ret = sokoban(av);
        else
        return (84);
    return (ret);
}
