/*
** EPITECH PROJECT, 2021
** dante
** File description:
** main.c solver
*/

#include "../include/solver.h"

int main(int argc, char **argv)
{
    int ret = 0;

    if (argc == 2)
        ret = solver(argv[1]);
    else
        ret = 84;
    return (ret);
}
