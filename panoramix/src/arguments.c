/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** arguments.c
*/

#include "../include/panoramix.h"

bool isnumeric(const char *s)
{
    int i = 0;

    if (*s == '0')
        return false;
    while (*s) {
        if (*s < '0' || *s > '9')
            return false;
        ++s;
        ++i;
    }
    return true;
}

bool verify_arguments(int argc, char const **argv)
{
    if (argc != 5)
        return false;
    if (isnumeric(argv[1]) == false || isnumeric(argv[2]) == false
    || isnumeric(argv[1]) == false || isnumeric(argv[3]) == false
    || isnumeric(argv[4]) == false)
        return false;
    return true;
}

void fill_struct(panoramix_t *panoramix, char const **argv)
{
    panoramix->arguments.nb_villagers = atoi(argv[1]);
    panoramix->arguments.nb_fights = atoi(argv[3]);
    panoramix->arguments.nb_refill = atoi(argv[4]);
    panoramix->arguments.pot_size = atoi(argv[2]);
}
