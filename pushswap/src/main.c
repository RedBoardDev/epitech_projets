/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** main.c
*/

#include "../include/pushswap.h"

int main(int argc, char const **argv)
{
    int rtn = 0;

    if (argc > 1)
        rtn = push_swap(argc, argv);
    else
        rtn = 84;
    return (rtn);
}
