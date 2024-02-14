/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-BSQ-thomas.ott
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int main(int argc, char **argv)
{
    map_t map;
    int size = 0;
    struct stat stats;

    if (argc >= 1) {
        bsq(argv[1]);
    } else
        return (84);
    return (0);
}