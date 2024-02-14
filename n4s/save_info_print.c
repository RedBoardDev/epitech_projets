/*
** EPITECH PROJECT, 2022
** B-AIA-200-MLH-2-1-bsn4s-luca.haumesser
** File description:
** save_info_print
*/

#include "struct.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    write (1, str, i);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    write (2, str, i);
}

int save_int(char *info, int i)
{
    int nbr = 0;

        nbr = atoi(info + i);
    return (nbr);
}

int find_lidar(char *info, int nbr_lidar)
{
    int i = 0;
    int current_lidar = 0;

    for (; nbr_lidar + 3 > current_lidar; ++i)
        if (info[i] == ':')
            ++current_lidar;
    return (i);
}
